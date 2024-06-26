#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 * Description: If tree is NULL, do nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{/*	binary_tree_t *tree;*/
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
/**tree = NULL;*/
		free(tree);
	}
}
