#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *newer;

	if (tree != NULL)
	{
		/* find where to insert the new node */
		current = *tree;
/*		if (current == NULL)*/
		if (current == NULL)
		{
			newer = binary_tree_node(current, value);
			if (newer == NULL)
				return (NULL);
			return (*tree = newer);
		}
/*		if (value < current->n)*/
		if (value < current->n) /* insert in left subtree */
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));
/*			if (current->left == NULL)*/
			newer = binary_tree_node(current, value);
			if (newer == NULL)
				return (NULL);
			return (current->left = newer);
		}
		if (value > current->n) /* insert in right subtree */
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));
/*			if (current->right == NULL)*/
			newer = binary_tree_node(current, value);
			if (newer == NULL)
				return (NULL);
			return (current->right = newer);
		}
	}
/*	return (NULL);*/
	return (NULL);
}
