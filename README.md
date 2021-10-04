# Ants-and-anteaters
For this assignment, you are tasked with creating
a world that consists of a 30x30 grid of cells.
Call the direction toward the top of the grid
'north', the direction toward the left side of the
grid 'west', and so forth.
Cells can contain one of the following things:
• an ant
• An anteater (a mammal that eats ants and
has a very long tongue)
Represent ants with the character 'a' and anteaters with the character '@'
For the purposes of this assignment, both ants and anteaters move exactly one square a time step,
but neither ants nor anteaters can move diagonally. No organism should ever move off the edge
of the grid.
Every time step the events below happen in the order in which they appear.
Execute each event in the time step starting with the organisms in the northernmost row,
scanning from west to east to find organisms to activate. Then repeat with the secondnorthernmost
row, and so forth. Never move on to the next event until after all of the board has
carried out the current event (i.e. move all anteaters before any anteaters feed, do all anteater
feeding before moving ants, check for ant reproduction before checking for anteater
reproduction, and so forth).
1. Anteater moves: If there is no ant within five squares directly to the north,
south, east, or west of an anteater, that anteater moves one step toward the nearest
ant on the board. If multiple ants are at the same distance, choose one of the
nearest ants at random and move one square toward it. If all squares that take the
anteater closer to the nearest ant are blocked, the anteater should not move.
=== (there is more than one way to do this) ===
2. Anteater feeding: If there is an ant within five squares directly to the north,
south, east, or west of an anteater, that anteater extends its tongue five squares in
that direction. If there are multiple valid directions, choose one at random.
The anteater eats every ant in every cell its tongue occupies. However, if the
tongue encounters either the edge of the grid or a square occupied by another
anteater, the attempt at eating fails and no ants are eaten.
When an ant is eaten, it is considered dead. Remove it from the grid.
After an attempt at eating, the anteater withdraws its tongue. You do not have to
represent the anteater's tongue in your program output.
3. Ant moves: Ants move into an empty square adjacent to them. If there is more
than one empty adjacent square, choose one of the valid squares at random. If all
squares are full, the ant does not move. Ants, like all organisms, cannot move off
the grid.
4. Ant reproduction: If an ant survives for 3 time steps, it reproduces. Place a new
ant on an empty square adjacent to the ant. If there are no empty adjacent squares,
the attempt at reproduction fails and no new ant is placed.
5. Anteater reproduction: If an anteater survives for 8 time steps, it reproduces.
Place a new anteater on an empty square adjacent to the anteater. If there are no
empty adjacent squares, replace an adjacent ant with a new anteater. If all of the
available adjacent squares already contain anteaters, the attempt at reproduction
fails and no new anteater is placed.
6. Anteater death: If an anteater goes more than three turns without eating an ant, it
dies. Remove it from the grid.
After each time step, print out the grid. Use # characters to represent the edges of the
board, - characters to represent empty squares, 'a' to represent ants, and '@' to represent
anteaters.
Start the program with a relatively large number of ants and a relatively small number of
anteaters added to the board at random positions. Experiment with starting the game with
different numbers of ants and anteaters. If possible, find an initial number of ants and
anteaters that results in a relatively stable population of both ants and anteaters.
Your program should be implemented using a sensible class hierarchy. The Ant class and
the Anteater class should be derived from a superclass called Organism. Organism should
be an abstract class -- it should contain pure virtual functions for both movement and
reproduction.
The grid should be contained within a class called World; this class should contain a
function to advance the grid one time step. Call this function each time the user presses
the enter key.
You may include additional classes as necessary.
