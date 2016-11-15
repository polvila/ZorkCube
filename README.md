# ZorkCube
The Zork game based on the movie "The cube"

##About

The game consists of leaving a cube of 3x3x3 where in there are 9 rooms of 1x1x1 connected between them. You will start inside a room, with position (2,0,0), and you will has to move from room to room until you find the exit, witch can be fund in the room located in (0,2,2). All this rooms change their position over time and some of them has a trap that can kill you or decrease your health. Moreover, if you dont leave early or eats something, you hungry will increase and you will end up dead. 

To find the exit, the rooms has nine numbers with which you can know their starting position, their first next position and their second next position. Their third next position is the same as the starting position.

>**Tip**:

> - The numbers of the rooms follow this structure: &nbsp;  x1 x2 x3 &nbsp; y1 y2 y3 &nbsp; z1 z2 z3

> - Initial position = (x1 + x2 +x3, y1 + y2 + y3, z1 + z2 + z3)
> 
> - Translation vector of the first movement = (x2 - x3, y2 - y3, z2 - z3)
> 
> - Translation vector of the second movement = (x3, y3, z3)
> 
> - Translation vector of the third movement = (-x2, -y2, -z2)

##Guide
###How to play

The game is a command line game, so you can only move and interact with objects from commands. [Here][1] there is the wiki, where you can read the diferent commands that you can use. Anyway, you can type `help` command to get the list of useful commands.

Mainly, you can move the player to another side room typing `goto north|south|east|west`. Each room show you where the exits lead. Finally you will see an exit named `EXIT!` which brings you to the end of the game.

###How to finish the game

####Quick and easy way
Do the following commands as fast as you can:
> 1. `goto up` (and responds `yes`)
> 2. `goto up` (and responds `yes`)
> 3. `goto east` (and responds `yes`)
> 4. `goto east` (and responds `yes`)

####Well played way
Try to avoid the red and green rooms, they can kill you in a few seconds. Count the times the rooms have changed and use the numbers to get the safe way until the exit of the big cube using the change of position of the rooms.

##Author

- Pol Vilà Saló ([polvilasalo@gmail.com](mailto:polvilasalo@gmail.com))

##GitHub Repository

See https://github.com/polvila/ZorkCube

##License

This project is licensed under the terms of the MIT license.

##Document resources

- [The Cube][2].

  [1]: https://github.com/polvila/ZorkCube/wiki/ZORKCUBE-WIKI
  [2]: https://www.uam.es/departamentos/ciencias/matematicas/premioUAM/premiados1/cube.pdf
