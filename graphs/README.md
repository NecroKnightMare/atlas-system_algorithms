C - Graphs
 Master
 By: Alexandre Gautier, Software Engineer at Holberton School
 Weight: 1
 Your score will be updated as you progress.
Description
For this project, we expect you to look at this concept:

[EYNTK] Graphs
Resources
Read or watch:

[Graphs](https://en.wikipedia.org/wiki/Graph_%28abstract_data_type%29)
Graphs (Stanford lecture)
[Introduction to graphs](https://www.youtube.com/watch?v=gXgEDyodOJU)


General
What is a graph
What are vertices and edges
What are the different types of graphs (directed, weighted, …)
What are the most common ways used to represent graphs in C
How to traverse a graph using DFS and BFS
## Requirements

Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS
Your C programs and functions will be compiled with gcc 9.4.0 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
You are allowed to use the standard library
In the following examples, the main.c files are showed as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one showed in the examples
The prototypes of all your functions should be included in your header file called graphs.h
Don’t forget to push your header file
All your header files should be include guarded
More Info
### Data structures
+ Please use the following data structures and types for graphs. Don’t forget to include them in your header file graphs.h.

    /**
    * enum edge_type_e - Enumerates the different types of
    * connection between two vertices
    *
    * @UNIDIRECTIONAL: The connection is made only in one way
    * @BIDIRECTIONAL: The connection is made in two ways
    */
    typedef enum edge_type_e
    {
        UNIDIRECTIONAL = 0,
        BIDIRECTIONAL
    } edge_type_t;

    /* Define the structure temporarily for usage in the edge_t */
    typedef struct vertex_s vertex_t;

    /**
    * struct edge_s - Node in the linked list of edges for a given vertex
    * A single vertex can have many edges
    *
    * @dest: Pointer to the connected vertex
    * @next: Pointer to the next edge
    */
    typedef struct edge_s
    {
        vertex_t    *dest;
        struct edge_s   *next;
    } edge_t;


    /**
    * struct vertex_s - Node in the linked list of vertices in the adjacency list
    *
    * @index: Index of the vertex in the adjacency list.
    * @content: Custom data stored in the vertex (here, a string)
    * @nb_edges: Number of conenctions with other vertices in the graph
    * @edges: Pointer to the head node of the linked list of edges
    * @next: Pointer to the next vertex in the adjacency linked list
    *   This pointer points to another vertex in the    graph, but it
    *   doesn't stand for an edge between the two vertices
    */
    struct vertex_s
    {
        size_t      index;
        char        *content;
        size_t      nb_edges;
        edge_t      *edges;
        struct vertex_s *next;
    };

    /**
    * struct graph_s - Representation of a graph
    * We use an adjacency linked list to represent our graph
    *
    * @nb_vertices: Number of vertices in our graph
    * @vertices: Pointer to the head node of our adjacency linked list
    */
    typedef struct graph_s
    {
        size_t      nb_vertices;
        vertex_t    *vertices;
    } graph_t;

### Print function
To match the examples in the tasks, you are given [this function](https://github.com/hs-hq/0x06-graphs.c)

This function is used only for visualisation purpose. You don’t have to push it to your repo. It may not be used during the correction