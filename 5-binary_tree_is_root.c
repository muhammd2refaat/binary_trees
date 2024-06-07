#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a root - 1.
 *         Otherwise - 0.
 * Description: If node is NULL, return 0 and 0 is returned.
 */
int binary_tree_is_root(const binary_tree_t *node)
{/*	binary_tree_t *node;*/
	if (node == NULL || node->parent != NULL)
		return (0);/*	binary_tree_t *node;*/
/*	return (node->parent == NULL);*/
	return (1);
}
