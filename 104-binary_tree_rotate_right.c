#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that  rotates right the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivotal;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
/*	pivotal = tree->left;*/
	pivotal = tree->left;
	tree->left = pivotal->right;
	if (pivotal->right != NULL)
	{
/*		pivotal->right->parent = tree;*/
		pivotal->right->parent = tree;
	}
	pivotal->right = tree;
	pivotal->parent = tree->parent;
	tree->parent = pivotal;
	return (pivotal);
/*	return (pivotal);*/
}
