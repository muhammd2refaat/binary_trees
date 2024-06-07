#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * Description: If tree or func is NULL, do nothing and func is not called.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{/*	binary_tree_t *tree;*/
	if (tree && func)
	{/*	binary_tree_t *tree;*/
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
/**tree = NULL; and func = NULL;*/
		func(tree->n);
	}
/* tree->n = 0; */
}
