# Intro to C++

# Due: 

# Project 2 - The Maze

## Objective:

This project is meant to help you familiarize yourself with multi-dimensional arrays, while also further strengthening
your knowledge of OO principles and problem solving. You will be creating an interactive maze that involves the creation
of multiple user-defined classes. As programs grow in size and complexity, you will need to be able to work with and manage
multiple modules and data structures.

## Learning Outcomes:

Developer a program that uses:

- Multiple modules
- Multi-dimensional arrays

## Preparation:

To complete this project, you need to make sure that you have read the following:

- Chapter 3 - Strings
- Chapter 4 - Array and Vector Basics
- Chapter 7 - Objects and Classes Basics
- Chapter 9 - Modular Design and Makefiles
- Chapter 10 - Memory Management
- The Arrays Handout on Canvas

## Problem Description:

The idea for this project is similar to old text-based adventure games in which a player is presented with various options through various screens of text.
In the case of your project, you have been trapped in a maze and must figure out how to navigate a maze in order to escape.
The maze is composed of rooms. In order to escape, the player needs to travel through each room of the maze, gathering keys and objects along the way
that will aid in their escape.

Take the following maze as an example (note that you do not need to implement this visualization):

```
+--------------+-------------+----------------+
|              |             |                |
| The Start    = The Landing = Master Bedroom |
| axe,blue_key |             |    red_key     |
|              |             |                |
+---red_key----+-------------+----------------+
|              |             |                |
| The Kitchen  =  The Hall   =   The Exit!    =
|              |             |                |
+--------------+-------------+----------------+
```

This maze is composed of two rows and three columns. Every maze can be represented as a grid. In order to get the specifications for a maze, you will
read in a maze's layout through a data file (discussed later). For each maze, the player starts in the top left corner of the maze and must make their
way out of the maze. Escaping the maze means finding an exit that has an accessible passagway out of the maze.
The data read in from the input file will define characteristics about each room of the maze and the passageways connecting them. Some rooms will have passageways
blocked by doors that require special items to open. In the given example, the door to the south of the player's starting location is blocked by a door that requires
a red_key to open. The player must make their way to the "Master Bedroom" first before they backtrack and can finally open the door that will allow them to progress
to The Exit.
The maze will be interactive as described in the next section.

## Overview of the Interface:

The player starts in the top left corner of the maze. Each room has a name as specified in the data file. At the start of the game, you will be required to enter the
name of a data file that will contain the maze's details.

```
Welcome to The Maze.
Please enter the filename of your maze:
```

Once the file name is entered, the program should show options for the first room. Assume we were using the example maze that we previously mentioned. Then the interface
should look as follows:

```
Welcome to The Maze.
Please enter the filename of your maze: maze.txt

You are in The Start!
There is a(n) axe and a(n) blue_key in this room. You picked up the item(s)!
There is a(n) solid wall to the North.
There is a(n) open doorway to the East.
There is a(n) doorway that requires a(n) red_key to the South.
There is a(n) solid wall to the West.
Which way would you like to move?
```

Given the choices, there is only one option for the player, so the player moves to the East:

```
You are in The Start!
There is a(n) axe and a(n) blue_key in this room. You picked up the item(s)!
There is a(n) solid wall to the North.
There is a(n) open doorway to the East.
There is a(n) doorway that requires a(n) red_key to the South.
There is a(n) solid wall to the West.
Which way would you like to move? E

You are in The Landing!
There are no objects in this room.
There is a(n) solid wall to the North.
There is a(n) open doorway to the East.
There is a(n) solid wall to the South.
There is a(n) open doorway to the West.
Which way would you like to move?
```
When a player enters a room, they loot the room of all items. Entering that room again should show that there are no objects in the room. 

If the player chooses a path that is currently blocked, either by a solid wall or because they don't have a needed key,
then the game should output the message "You can't go that way!" and then prompt for another direction. The player may at any time, also choose to
enter "Q" in which case the output should be "Better luck next time!" and the program should end.

If the player makes it through an exit, then the program should output "It took you x moves, but you're free!" where x is the number of moves that the player
took to get out of the maze. Then the program should end. There can be multiple exits in a maze. An exit is a passageway that leads out of the maze.
The player wins when they travel through that passageway. In our example, if the player has reached The Exit, they still need to move East again to win.

## Data format:

A maze is specified by an input file with the following format:

```
Row_count,Column_count
Room_name,North_passageway,East_passageway,South_passageway,West_passageway,list_of_items_in_room
```

The first line of the input file is the number of rows (Row_count) and the number of columns (Column_count)
in the maze. The first line is followed by Row_count x Column_count lines with each line representing a different Room in the maze.

Each room has a name, four connected passageways, and a list of items in that room. Each passageway in a room is one of three types:

1. "-": No passage is allowed
1. "+": Passage is open
1. "item_needed_to_open_passageway": Requires the item(s) specified to open the door

The input file for our example maze would look like the following:

```
2 3
The Start,-,+,red_key,-,axe blue_key
The Landing,-,+,-,+,
Master Bedroom,-,-,-,+,red_key
The Kitchen,red_key,+,-,-,
The Hall,-,+,-,+,
The Exit!,-,+,-,+,
```

Note that the list of items in the room is not comma-separated.

### Sample run of program

Takes a second or so to start. You can ignore the cd command.

![Sample execution of program](demo.gif)

## Code Organization:

You will need to make sure that your code meets the following specifications.
Note that there is some room for interpretation, but a general code outline is given below.
 
### The Main File
The main file shall create a Game instance and utilize its methods to implement the game.
Additionally, the main file will handle user selections and input. 



- Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
- Do not change the TestCase.cpp, testMaze.txt, or keyboard_input.txt files unless told to! The results you get will be pointless as they will not align with our grading! You can change maze.txt all you want.
- Please review the academic honesty policy.
  - Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
  - Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty. \* All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.
  
## Breakdown of Grades:

You will find a rubric for the project in Canvas. 

## Submission Instructions:

1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
   1. After pushing, with `git push origin master`, visit the web URL of your repository to verify that your code is there.
      If you don't see the code there, then we can't see it either.
3. Your code must compile and run in Travis-CI or it might not be graded.
   1. The Travis-CI build should begin automatically when you push your code to GitHub.
   2. If your program will not compile, the graders will not be responsible for trying to test it.
   3. You should get an email regarding the status of your build, if it does not pass, keep trying.
