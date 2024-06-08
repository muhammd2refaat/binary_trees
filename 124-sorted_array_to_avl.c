#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 * NOTE: The new node is not inserted into the queue.
 *
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 *
 * and 0 is returned.
 *
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t medium;
/*	avl_t *root = NULL;*/
	if (size == 0)
		return;
/*	root = *node;*/
	medium = (size / 2);
	medium = (size % 2 == 0) ? medium - 1 : medium;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[medium]);
		create_tree(&((*node)->left), array, medium, 1);
		create_tree(&((*node)->left), array + medium + 1, (size - 1 - medium), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[medium]);
		create_tree(&((*node)->right), array, medium, 1);
		create_tree(&((*node)->right), array + medium + 1, (size - 1 - medium), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t medium;
/*	avl_t *root = NULL;*/
	root = NULL;
/*	root = binary_tree_node(root, array[medium]);*/
	if (size == 0)
		return (NULL);
/*	root = binary_tree_node(root, array[medium]);*/
	medium = (size / 2);
/*	root = binary_tree_node(root, array[medium]);*/
	medium = (size % 2 == 0) ? medium - 1 : medium;
/*	root = binary_tree_node(root, array[medium]);*/
	root = binary_tree_node(root, array[medium]);
/*	root = binary_tree_node(root, array[medium]);*/
	create_tree(&root, array, medium, 1);
	create_tree(&root, array + medium + 1, (size - 1 - medium), 2);
/*	return (root);*/
	return (root);
}

