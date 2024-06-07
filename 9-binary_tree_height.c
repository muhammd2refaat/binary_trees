#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 * Description: If tree is NULL, return 0 and 0 is returned.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t g = 0, h = 0;
/**tree = NULL;*/
		g = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
/**tree = NULL;*/
/*g is 0 and h is 0*/
		return ((g > h) ? g : h);
	}
	return (0);
}

