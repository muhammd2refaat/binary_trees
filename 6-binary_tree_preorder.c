#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * Description: If tree or func is NULL, do nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{/*	binary_tree_t *tree;*/
		func(tree->n);
		binary_tree_preorder(tree->left, func);
/**tree = NULL; and func = NULL;*/
		binary_tree_preorder(tree->right, func);
	}
}
