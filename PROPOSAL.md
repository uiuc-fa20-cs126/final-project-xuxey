# Cinder Breakout

### What is this project?

I will be recreating the popular arcade & retro game `Breakout` using Cinder and C++. The game involves eliminiating a set of randomly spawned blocks by strategically bouncing a ball on a player-controlled movable plate. If the ball is not caught by the plate, the game ends/restarts. Try playing it on this [webpage](https://elgoog.im/breakout/)!

![Breakout Game](https://upload.wikimedia.org/wikipedia/en/thumb/2/2b/Breakout2600.svg/480px-Breakout2600.svg.png)

## Why do I want to do this project? 

I used to play this game a lot growing up, and would love to implement it by myself. 

## A rough timeline of what will get accomplished and when 
The draft timeline is as follows:

### Week 1 
1. Build a random game map generator to generate a set of blocks given some predefined constraints.
2. Add a working movable plate and associated control mechanisms (arrow keys/mouse follow)
3. Add a moving ball object with collisions to the top, left and right walls, and end-game to the bottom wall

### Week 2 
1. Add collisions for the ball with blocks, removing blocks after each collision. 
2. Add collisions for the ball with the plate, with biased collision response based on where the ball hits the plate. 
3. Add UI/UX enhancements 
  - Give the ball a 3D appearance
  - Add a layout for displaying user/score
4. Add play/pause functionality using space bar

### Week 3
1. Add a live functioning scoreboard depending on how many blocks are broken
2. Create customizable ball, plate and background colors using the [PretzelGui](https://github.com/cwhitney/PretzelGui) Library.
3. Make the blocks random-colored/row-wise colored 
4. Store high score in a file, so that it is saved even when app is closed. 

## If I were to finish the project early, what extra "stretch goals" could I implement?

Some stretch goals I had in mind are:

- Implement sounds for ball bounces, game end/start etc. (UI enchancement)
- Hardcore mode, where player has to manage 2 balls and 2 plates (one plate above as well which mirrors the bottom plate) (Gameplay enchancement)
