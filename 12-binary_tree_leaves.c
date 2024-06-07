#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree.
 * Description: If tree is NULL, return 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lefted = 0;
/*	binary_tree_t *tree;*/
	if (tree)
	{/*	binary_tree_t *tree;*/
		lefted += (!tree->left && !tree->right) ? 1 : 0;
		lefted += binary_tree_leaves(tree->left);
		lefted += binary_tree_leaves(tree->right);
	}
/*return (lefted);*/
	return (lefted);
}

