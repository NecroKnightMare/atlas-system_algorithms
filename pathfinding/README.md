# C - Pathfinding
 By: Alexandre Gautier, Software Engineer at Holberton School



## Resources
Read or watch:

[Pathfinding](https://intranet.atlasschool.com/rltoken/L7NO2st7C44KqbfixrkpUw)
[Backtracking](https://intranet.atlasschool.com/rltoken/qwHAap6f2hr09k9FFA5sPw)
[Dijkstra’s Algorithm](https://intranet.atlasschool.com/rltoken/oI2R0S6uogEzbDApBpIocQ)
[Dijkstra’s Algorithm - Computerphile](https://intranet.atlasschool.com/rltoken/qPo17zIlyzwF-7T1Ayn9Og)
[A Star algorithm](https://intranet.atlasschool.com/rltoken/ZGGUFt1jwQHRj8Qjh4d9qg)
[A Star Search Algorithm - Computerphile](https://intranet.atlasschool.com/rltoken/RVpDyRPDhozWkB4TLQeRgw)

## Learning Objectives

What is pathfinding
What are the most common applications of pathfinding
What is backtracking, and why you should never use it
What is Dijkstra’s algorithm, and what is its main weakness
What is A star algorithm, and how it is better than Dijkstra’s
Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS
Your C programs and functions will be compiled with gcc 9.4.0 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
You are allowed to use the standard library
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called pathfinding.h
Don’t forget to push your header file
All your header files should be include guarded
More Info
Data Structures
Please use the following data structures and types for binary trees. Don’t forget to include them in your header file pathfinding.h.

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
    int x;
    int y;
} point_t;
Libraries
For this project, you are given two libraries, containing utility functions to manipulate graphs and queues. You can find these libraries here.

This repository will be used during the auto-review, thus your code will be compiled using -lgraphs and -lqueues.