# Project 2 - The Maze

## Project Outcomes:
Develop a C++ program that uses:
* Multi-dimensional array
* Multiple user-defined classes
* Algorithm analysis
* Unit testing

## ZyBook Preparatory Readings:
* Chapter 4 - Array and Vector Basics
* Chapter 7 - Objects and Classes Basics
* Chapter 9 - Modular Design and Makefiles
* Chapter 11 - Searching and Algorithm Analysis

## Project overview:
In this project you will read in a maze that is specified from a data file.
The data read in from the comma-delimited file will define characteristics about each room of the maze and the passageways connecting them.
This maze must be interactive and allow a user to navigate the maze by use of the N, E, S, and W keys, indicating North, East, South, and West directions of movement.

After each move you should notify the user of what room they are now in as well as details about the four walls of the room, e.g.
```
Welcome to The Dungeon.
There are no objects in this room.
There is an open doorway to the North.
There is a solid wall to the East.
There is a doorway that requires a red_key to the South.
There is an open doorway to the West.
Which way would you like to move?
```

## Project Requirements:
Your application must function as described below:
1. Your program must use a two-dimensional array to store the rooms of the maze.
1. Each Room object stored in the array should keep track of items it contains as well as the type of passageway for each of the walls.
1. Any cell that allows an exit beyond the bounds of the array is considered an exit.
1. When the user successfully finds an exit, notify them that they won and exit your program.
	1. Part of that notification should be to output the number of moves made by the user.
1. If at any point the user enters "Q", then your program should output a message such as "Better luck next time" and the program should exit.
1. You should have a means of keeping track of what items the player currently has, such as "red_key" and removing those items if they are used to pass through a door.
	1. When using an item to pass though a door, the two rooms adjacent to the doorway should both be updated to know that the doorway is now open.
	Thus, a user can go back and forth through a red_key doorway as many times as they want once they have used the red_key on that door.
1. Your program should implement unit testing functions that check such things as:
	1. Parsing the line of text outlining the size of the maze
	1. Parsing a line of text representing a room in the maze.
	1. Passing through a doorway that requires an item when that item is in hand.
		1. Was the item removed from player's inventory?
	1. Failing to pass through a doorway that requires an item when that item is not in hand.
	1. Successfully exiting the maze.
	1. Quitting the maze.

### Data format
Each passageway in a maze room is one of three types:
1. "-": No passage is allowed
1. "+": Passage is open
1. "item_needed_to_open_passageway": Requires the item(s) specified to open the door

```
Row_count,Column_count
Room_name,North_door,East_door,South_door,West_door,list_of_items_in_room
```

### Sample data
```
2 3
The Start,-,+,red_key,-,axe blue_key
The Landing,-,+,-,+,
Master Bedroom,-,-,-,+,red_key
The Kitchen,red_key,+,-,-,
The Hall,-,+,-,+,
The Exit!,-,+,-,+,
```

### Visualization of Maze _(this does not need to be implemented)_
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

**In the above maze, the shortest path goes right all the way along the top row to get the red\_key, then goes back to the 0 column, down through the red\_key dooorway and right until the exit**.

### Sample run of program



## Implementation Notes:
1. Create a project that is object oriented, therefore there should be several classes.
2. The input file will match the exact format given above.

## Submission Requirements:
1. All code must be added and commiitted to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
	1. After pushing, with `git push origin master`, visit the web URL of your repository to verify that your code is there.
	If you don't see the code there, then we can't see it either.
3. Your code must compile and run in Travis-CI or it might not be graded.
	1. The Travis-CI build should begin automatically when you push youur code to GitHub.
	2. If your program will not compile, the graders will not be responsible for trying to test it. 
	3. You should get an email regarding the status of your build, if it does not pass, keep trying.

## Important Notes:
* Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices. 
* Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero. 
* Please review the academic honesty policy.
	* Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
	* Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty.
	* All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.