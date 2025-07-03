#include "rb_trees.h"

/**
 * rb_tree_node - Creates a new red-black tree node
 * @parent: pointer to parent
 * @color: color of node
 * @value: value of node
 * Return: pointer to new node, Null on faiol
 */

 rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)