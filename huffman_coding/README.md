C - Huffman coding
 Master
 By: Alexandre Gautier, Software Engineer at Holberton School
 Weight: 1
 Your score will be updated as you progress.
Description
Resources
Read or watch:

(Binary Heap)[https://intranet.atlasschool.com/rltoken/mSnDMlMgKBLtqrVzqeWvIg]
(Huffman coding)[https://intranet.atlasschool.com/rltoken/qotcNlmCvexiDGg6gcGg6w]
(Enumerated Types)[https://intranet.atlasschool.com/rltoken/SePvVSSmW23X4UauijxhsQ]
(Huffman Coding and Huffman Trees)[https://intranet.atlasschool.com/rltoken/Xqfs2zA3vcvlVW9oy9me1Q]

### Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General
What is a binary Heap (min and max)
What is a priority queue
What is a Huffman code

#### Requirements

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS
* Your C programs and functions will be compiled with gcc 9.4.0 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project, is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* You are allowed to use the standard library
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header files called huffman.h and heap/heap.h
* Don’t forget to push your header files
* All your header files should be include guarded

### Data structures

Please use the following data structures and types for this project. Don’t forget to include them in your header file(s). You’ll have to declare the following data structures in your header file heap.h in the folder huffman_coding/heap

    /**
    * struct binary_tree_node_s - Binary tree node data structure
    *
    * @data: Data stored in a node
    * @left: Pointer to the left child
    * @right: Pointer to the right child
    * @parent: Pointer to the parent node
    */
    typedef struct binary_tree_node_s
    {
        void *data;
        struct binary_tree_node_s *left;
        struct binary_tree_node_s *right;
        struct binary_tree_node_s *parent;
    } binary_tree_node_t;

    /**
    * struct heap_s - Heap data structure
    *
    * @size: Size of the heap (number of nodes)
    * @data_cmp: Function to compare two nodes data
    * @root: Pointer to the root node of the heap
    */
    typedef struct heap_s
    {
        size_t size;
        int (*data_cmp)(void *, void *);
        binary_tree_node_t *root;
    } heap_t;
You’ll have to declare the following data structures in your header file huffman.h in the folder huffman_coding

    /**
    * struct symbol_s - Stores a char and its associated frequency
    *
    * @data: The character
    * @freq: The associated frequency
    */
    typedef struct symbol_s
    {
        char data;
        size_t freq;
    } symbol_t;

### Print function

To match the examples in the tasks, you are given these functions

Theses functions are used only for visualisation purpose. You don’t have to push them to your repo. They may not be used during the correction.