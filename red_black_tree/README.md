# C - Red-Black trees
 Master
 By: Alexandre Gautier, Software Engineer at Holberton School

#### Resource

(Red Black tree)[https://en.wikipedia.org/wiki/Red%E2%80%93black_tree]
## Learning Objectives

What is a Red Black Tree
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
The prototypes of all your functions should be included in your header files called rb_trees.h
Don’t forget to push your header files
All your header files should be include guarded

### Data structures

Please use the following data structures and types for this project. Don’t forget to include them in your header file(s). You’ll have to declare the following data structures in your header file rb_trees.h in the folder red_black_tree.

    /**
    * enum rb_color_e - Possible color of a Red-Black tree
    *
    * @RED: 0 -> Red node
    * @BLACK: 1 -> Black node
    */
    typedef enum rb_color_e
    {
        RED = 0,
        BLACK,
        DOUBLE_BLACK
    } rb_color_t;

    /**
    * struct rb_tree_s - Red-Black tree node structure
    *
    * @n: Integer stored in the node
    * @parent: Pointer to the parent node
    * @left: Pointer to the left child node
    * @right: Pointer to the right child node
    * @color: Color of the node (RED or BLACK)
    */
    typedef struct rb_tree_s
    {
        int n;
        rb_color_t color;
        struct rb_tree_s *parent;
        struct rb_tree_s *left;
        struct rb_tree_s *right;
    } rb_tree_t;

### Print function
To match the examples in the tasks, you are given these functions

These functions are used only for visualisation purposes. You don’t have to push them to your repo. They may not be used during the correction