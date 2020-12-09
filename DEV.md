# Dev Logs

## Week 1

- Remove PretzelGui Cinder Block due to compatibility issues and huge amount of source refactoring required
- All Week1 goals have been met: 
    1. Build a random game map generator to generate a set of blocks given some predefined constraints.
    2. Add a working movable plate and associated control mechanisms (arrow keys/mouse follow)
    3. Add a moving ball object with collisions to the top, left and right walls, and end-game to the bottom wall

# Week 2
- Implemented screens functionality within user interface
- Added Game modes (extra feature) with modular support for adding more modes at a later time
    1. Classic Mode
    2. Easy Mode
- Improved brick gen algorithm to get rid of overflow anomalies.
- Did NOT use 4D trees due to insignificant performance improvements at this scale.
- Tried adding in-built shaders via ci::gl but ran into camera perspective and other issues.
  Will be using a handmade substitute for ball light reflection.
- Decided to drop the customizable colors because the game has pre-defined color dependencies, and can focus the effort on some stretch goals.

# Week 3
- Added a functioning live score board in the game
- Added functionality to save high scores to a file for conserving scores across sessions
- Added sound effect on ball collisions with world objects
- Improved UI Experience with an end-game screen

## Planned Features

- Add screens to User Interface for UI Modularity (Accomplished) 