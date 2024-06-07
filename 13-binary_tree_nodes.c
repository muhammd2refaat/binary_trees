#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 * DESCRIPTION: If tree is NULL, return 0 and 0 is returned.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;
/* node = 0;*/
	if (tree)
	{
		node += (tree->left || tree->right) ? 1 : 0;
/*		node = (tree->left || tree->right) ? 1 : 0;*/
		node += binary_tree_nodes(tree->left);
		node += binary_tree_nodes(tree->right);
	}
/*return (node);*/
	return (node);
}

