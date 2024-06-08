#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that  rotates left the binary tree.
 * @tree: The root node of the three
 * Return: Pointer node of the new node
 * NULL if tree is NULL
 * NULL if pivot is NULL
 * NULL if pivot->right is NULL
 * NULL if pivot->right->left is not NULL
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
	{
/*		return (NULL);*/
		return (NULL);
	}
	pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left != NULL)
	{
/*		pivot->left->parent = tree;*/
		pivot->left->parent = tree;
	}
	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
/*	return (pivot);*/
}
