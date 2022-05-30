# triangle-gamez
A two-player game where you fight against friends as triangles with the power to move, shoot pencil-like projectiles, and dodge by flipping your equilateral self across the horizontal axis..

## Dependencies
The program makes use of low-level, deprecated graphics and resource libraries: GDI (Graphics Device Intercace) and windres, a program that compiles resources specified within a .rc file into an object file. It also uses the gcc compiler, with a required link to the gdi32 dll and the windmm multimedia library (for playing sounds).
## Programming Notes
I had a strong interest in OpenGL during the development of this game. Thus, I modeled the vertex data and drawing procedures after the OpenGL specification. They begin with 'tgl', which stands for "Triangle Graphics Library".\
\
Also, sadly, my main library file triangleOperations.c was corrupted and contains only NULL values. It is provided only for project directory completeness.
## Playing the Game
Players use either WASD or the arrow keys to translate their triangles across the screen.
### FULL KEY MAP:
#### PLAYER 1
movement: WASD\
shoot: t\
flip: g
#### Player 2
movement: arrow keys\
shoot: return\
flip: space

## Contribution
Some ideas for contribution include: 
(1) Converting the files to a modern language and graphical framework (for example python, javascript, or C++ with OpenGL, PyGame, or Phaser.js). 
(2) Reimplmenting the triangleOperations.c file.
(3) Adding network capability, leaderboard, power-ups, AI.
