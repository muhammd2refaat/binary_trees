#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a
 *                       node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 * DESCRIPTION: If node is NULL, return NULL and 0 is returned.
 * If node has no sibling, return NULL and 0 is returned.
 * If node has a sibling, return the sibling and 1 is returned.
 * and 1 is returned.
 * Note: If node is NULL, return NULL and 0 is returned.
 * and 0 is returned.
 * NOTE: The function uses recursion.
 * REMEMBER: If node is NULL, return NULL and 0 is returned.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{/*	binary_tree_t *node;*/
	if (node == NULL || node->parent == NULL)
/**node = NULL || node->parent = NULL;*/
		return (NULL);
	if (node->parent->left == node)
/**node->parent->left = node;*/
		return (node->parent->right);
/**node->parent->right = node;*/
	return (node->parent->left);
}

