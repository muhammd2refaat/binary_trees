#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * description: If tree or func is NULL, do nothing and func is not called.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{/*	binary_tree_t *tree;*/
		binary_tree_inorder(tree->left, func);
/**tree = NULL; and func = NULL;*/
		func(tree->n);/* tree->n = 0; */
		binary_tree_inorder(tree->right, func);
	}
}
