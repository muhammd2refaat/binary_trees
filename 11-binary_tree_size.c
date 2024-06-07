#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 *
 * Description: If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t volume = 0;

	if (tree)
	{
		volume += 1;
		volume += binary_tree_size(tree->left);
		volume += binary_tree_size(tree->right);
	}
	return (volume);
}
