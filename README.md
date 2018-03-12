# 345World

COMP 345 Assignment 1

by
Hanqing Zhao 26575919
Claudia Feochari 40000060

The concept for part 1 (Map.h, Region.h) is to make a vector contains 
lots of lists and every list contain the edge between the beginning nodes
with different destination nodes. And location of the list inside the vector
is the beginning node.

The part 2 (MapLoader.h) is to read a selected map file which contain 
all information about the regions: its id number, name, x and y coordinates, 
and type of region. Also, it reads the edges between each regions by using 
their id number.

The part 3 (Dice.h) is a simple dice method, random pick a number 
between 0 to 5, the number 1,2,3 will be keeped, and the other three 
should return 0.

The part 5 (Races.h, PowerBudgets.h) contains all the definition of the 
races and special powers by using inheritance.

The part 4 (Player.h) connects with part 5 through the method pick_race().

The Driver (GameDriver.h) will run all the previous files.