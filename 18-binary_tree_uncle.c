#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *                     in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: If node is NULL or has no uncle, NULL.
 *         Otherwise, a pointer to the uncle node.
 * DESCRIPTION: If node is NULL, return NULL and 0 is returned.
 * If node has no uncle, return NULL and 0 is returned.
 * If node has an uncle, return the uncle and 1 is returned.
 * and 1 is returned.
 * Note: If node is NULL, return NULL and 0 is returned.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
/**node = NULL || node->parent = NULL || node->parent->parent = NULL;*/
		return (NULL);
	if (node->parent->parent->left == node->parent)
/**node->parent->parent->left = node->parent;*/
		return (node->parent->parent->right);
/**node->parent->parent->right = node->parent;*/
	return (node->parent->parent->left);
}
