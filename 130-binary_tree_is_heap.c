#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - goes through a binary tree cheking ropt as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 *
 * NOTE: The new node is not inserted into the queue.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 **/
int check_max(const binary_tree_t *tree)
{
	int temporary1 = 1, temporary2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temporary1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temporary2 = check_max(tree->right);
	}
	return (temporary1 && temporary2);
}
/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 * NOTE: The new node is not inserted into the queue.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temporary;
/*	binary_tree_t *root = NULL;*/
	if (!tree)
		return (0);
/*	return (binary_tree_is_complete(tree));*/
	temporary = binary_tree_is_complete(tree);
	if (!temporary)
		return (0);
	return (check_max(tree));
}
