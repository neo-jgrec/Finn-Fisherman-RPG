# Finn Fisherman RPG

This project is one of the freest project of your first year. Create your own RPG.
To make feel like you are delivering a complete product, you need to polish as much as possible your game.
Our team tried to stick to thoses credo :
- Create a pleasant user interface;
- Create a coherent universe (visual assets, audio assets, scenario, ...);
- Create a funny game;

## Wiki
Here you can find the documentation of the game, so you'll be able to aknoledge the bases to play our game.
[Documentation](https://neo-19.gitbook.io/the-fisherman/)

## Project Requierments

### MANDATORY
- [X] The player needs to have characteristics
- [X] The player can fight enemies AND the characteristics impact the fights results
- [X] The player have an inventory which can contain a limited set of items
- [X] The player can earn experience by winning fights and/or accomplishing specific actions
- [X] The player can level up thanks to experience AND upgrading its characteristics
- [X] The game contains NPC
- [X] The game contains at least one quest
- [X] The game contains a how to play system at the very beginning

### TECHNICAL REQUIEREMENTS
This project, being the last project of the module, the following requierement are the mathematical and technical parts which has to be present in your final project:
- [X] A collision system including moving and static elements with different shapes.
- [X] Camera movements (zoom, translation, rotation).
- [X] 3D effects (depth scaling, isometric projection...).
- [X] Buttons must have at least 3 differents state
- [X] Saving system

### MUST
General

- [X] The window may be closed using events.
- [X] The windows may have differents mode :
    - [X] Window mode
    - [X] Full-screen mode
- [X] The windows may have differents resolutions, at least two (1920x1080, and an other)
- [X] The game manages inputs from the mouse click and keyboard,
- [X] The game contains animated sprites rendered thanks to sprite sheets,
- [X] Animations in your program are frame rate independent,
- [X] Animations and movements in your program are timed by clocks.

Main menu

- [X] Must contain at least these options
    - [X] Start the game
    - [X] Resume game
    - [X] Settings
    - [X] Quit the game
- [X] The settings option must contain
    - [X] Sound and music volume options
    - [X] A window size and resolution options

In game menu

- [X] Must be accessible by pressing the Escape key
- [X] Must contain at least these options
    - [X] Character options
        - [X] equipment and inventory management
        - [X] characteristics management
    - [X] Saving
    - [X] Loading
    - [X] Settings
        - [X] the same that main menu
        - [X] commands list

### SHOULD
- [ ] Splash screen at the beginning
- [ ] Command edit into the in game menu
- [X] As much information as possible about the game should be stored in a configuration file.
- [X] The game should have an advanced collision system to manage complex fighting.
- [X] The game should contains simple particle system :
    - [X] with at least 2 types of particle,
    - [X] particle effects (changing colors, scaling, bouncing, fading) to simulate realistic environment (wind, fire, rain, snow...).

### COULD
- [ ] Have a skill tree, unlocking different abilities (active and passive).
- [X] Have a complete particle engine.
- [X] Use scripting to describe entities.
- [X] Have a map edit

## How to run the Game

### Linux

You need to install the `CSFML` on version 2.5.1.
Once it's installed :
```bash
make && ./my_rpg
```

Now, Enjoy ! :)

### Windows

You need the `MSVC Build tools` to be installed on your machine.
Then download the archive from the realese, execute the executable and enjoy !

