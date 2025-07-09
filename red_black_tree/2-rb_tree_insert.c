#include "rb_trees.h"
#include <stddef.h>

/**
 * bst_insert
 * @tree: pointer to root
 * @value: insert value
 * Return: pointer to new node, NULL if value exists
 */

rb_tree_t *bst_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *parent = NULL, *current = *tree;

	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return NULL;
	}
	return (rb_tree_node(parent, value, RED));
}
/**
 * rotate_left - rotate tree left
 * @tree: pointer to root
 * @node: node to rotate
 */
void rotate_left(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *right = node->right;

	node->right = right->left;
	if (right->left)
	{
		right->left->parent = node;
	}

	right->parent = node->parent;
	if (!node->parent)
	{
		*tree = right;
	}
	else if (node == node->parent->left)
	{
		node->parent->left = right;
	} else {
		node->parent->right = right;
	}

	right->left = node;
	node->parent = right;
}

/**
 * rotate_right - rotate tree right
 * @tree: Double pointer to root
 * @node: Node to rotate
 */

void rotate_right(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *left = node->left;

	node->left = left->right;
	if (left->right)
	{
		left->right->parent = node;
	}

	left->parent = node->parent;
	if (!node->parent)
	{
		*tree = left;
	}
	else if (node == node->parent->right)
	{
		node->parent->right = left;
	} else {
		node->parent->left = left;
	}

	left->right = node;
	node->parent = left;
}

/**
* fix_insert - fix red black tree after insertion
* @tree: double pointer to root
* @node: inserted node
*/

void fix_insert(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *uncle;

	while (node->parent && node->parent->color == RED)
	{
		if (node->parent == node->parent->parent->left)
		{
			uncle = node->parent->parent->right;
			if (uncle && uncle->color == RED)
			{
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			} else {
				if (node == node->parent->right)
				{
					node = node->parent;
					rotate_left(tree, node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				rotate_right(tree, node->parent->parent);
			}
		} else {
			uncle = node->parent->parent->left;
			if (uncle && uncle->color == RED)
			{
				node->parent->color = BLACK;
				uncle->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			} else {
				if (node == node->parent->left)
				{
					node = node->parent;
					rotate_right(tree, node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				rotate_left(tree, node->parent->parent);
			}
		}
	}
	(*tree)->color = BLACK;
}

/**
* rb_tree_insert - insert a value into a red black tree
* @tree: double pointer to root
* @value: insert value
* Return: pointer to inserted node, NULL
*/
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node;

	if (!tree)
	{
		return (NULL);
	}
	if (!*tree)
	{
		*tree = rb_tree_node(NULL, value, BLACK);
		return (*tree);
	}
	new_node = bst_insert(tree, value);
	if(!new_node)
	{
		return (NULL);
	}
	if (new_node->parent->n > value)
	{
		new_node->parent->left = new_node;
	} else {
		new_node->parent->right = new_node;
	}
	fix_insert(tree, new_node);
	return (new_node);
}
