#define PI 3.14159265

uniform vec2 u_resolution;
uniform float u_time;

float random1d(float dt) {
    float c = 43758.5453;
    float sn = mod(dt, 3.14);
    return fract(sin(sn) * c);
}

/*
 *  Returns a random drop position for the given seed value
 */
vec2 random_drop_pos(float val, vec2 screen_dim, vec2 velocity) {
    float max_x_move = velocity.x * abs(screen_dim.y / velocity.y);
    float x = -max_x_move * step(0.0, max_x_move) + (screen_dim.x + abs(max_x_move)) * random1d(val);
    float y = (1.0 + 0.05 * random1d(1.234 * val)) * screen_dim.y;

    return vec2(x, y);
}

/*
 * Calculates the drop trail color at the given pixel position
 */
vec3 trail_color(vec2 pixel, vec2 pos, vec2 velocity_dir, float width, float size) {
    vec2 pixel_dir = pixel - pos;
    float projected_dist = dot(pixel_dir, -velocity_dir);
    float tanjential_dist_sq = dot(pixel_dir, pixel_dir) - pow(projected_dist, 2.0);
    float width_sq = pow(width, 2.0);

    float line = step(0.0, projected_dist) * (1.0 - smoothstep(width_sq / 2.0, width_sq, tanjential_dist_sq));
    float dashed_line = line * step(0.5, cos(0.3 * projected_dist - PI / 3.0));
    float fading_dashed_line = dashed_line * (1.0 - smoothstep(size / 5.0, size, projected_dist));

    return vec3(fading_dashed_line);
}

/*
 * The main program
 */
void main() {
    const float n_drops = 20.0;
    float trail_width = 2.0;
    float trail_size = 70.0;
    float wave_size = 20.0;
    float fall_time = 0.7;
    float life_time = fall_time + 0.5;
    vec2 velocity = vec2(0.5 * u_resolution.x, -0.9 * u_resolution.y) / fall_time;
    vec2 velocity_dir = normalize(velocity);
    vec3 pixel_color = vec3(0.0);

    for (float i = 0.0; i < n_drops; ++i) {
        float time = u_time + life_time * (i + i / n_drops);
        float ellapsed_time = mod(time, life_time);
        vec2 initial_pos = random_drop_pos(i + floor(time / life_time - i) * n_drops, u_resolution, velocity);

        if (ellapsed_time < fall_time) {
            vec2 current_pos = initial_pos + ellapsed_time * velocity;
            pixel_color += trail_color(gl_FragCoord.xy, current_pos, velocity_dir, trail_width, trail_size);
        } else
            vec2 final_pos = initial_pos + fall_time * velocity;
    }
    gl_FragColor = vec4(pixel_color, max(max(pixel_color.r, pixel_color.g), pixel_color.b));
}