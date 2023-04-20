#define PI 3.14159265

uniform vec2 u_resolution;
uniform float u_time;
uniform sampler2D u_texture;
uniform float u_velocity;
uniform float n_drops;

float random1d(float dt) {
    float c = 43758.5453;
    float sn = mod(dt, 3.14);
    return fract(sin(sn) * c);
}

vec2 random_drop_pos(float val, vec2 screen_dim, vec2 velocity) {
    float max_x_move = velocity.x * abs(screen_dim.y / velocity.y);
    float x = -max_x_move * step(0.0, max_x_move) + (screen_dim.x + abs(max_x_move)) * random1d(val);

    return vec2(x, screen_dim.y * random1d(val + 1.0));
}

vec4 fish_color(vec2 pixel, vec2 pos, vec2 size) {
    vec2 uv = (pixel - pos) / size;
    if (uv.x >= 0.0 && uv.y >= 0.0 && uv.x <= 1.0 && uv.y <= 1.0) {
        return texture2D(u_texture, uv);
    }
    return vec4(0.0);
}

void main() {
    float fall_time = 0.7;
    float life_time = fall_time + 0.5;
    vec2 velocity = vec2(0.5 * u_resolution.x, -0.9 * u_resolution.y) / fall_time * u_velocity;
    vec2 fish_size = vec2(70.0, 70.0);
    vec4 pixel_color = vec4(0.0);

    for (float i = 0.0; i < n_drops; ++i) {
        float time = u_time + life_time * (i + i / n_drops);
        float ellapsed_time = mod(time, life_time);
        vec2 initial_pos = random_drop_pos(i + floor(time / life_time - i) * n_drops, u_resolution, velocity);

        if (ellapsed_time < fall_time) {
            vec2 current_pos = initial_pos + ellapsed_time * velocity;
            pixel_color += fish_color(gl_FragCoord.xy, current_pos, fish_size);
        }
    }
    gl_FragColor = pixel_color;
}
