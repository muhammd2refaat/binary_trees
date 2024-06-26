#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 * Description: If tree is NULL, return 0 and 0 is returned.
 * and 0 is returned.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 * DESCRIPTION: If tree is NULL, return 0 and 0 is returned.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{/*	binary_tree_t *tree;*/
	if (tree)
	{
		size_t i = 0, x = 0;
/**tree = NULL;*/
		i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		x = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((i > x) ? i : x);
	}
	return (0);
}
