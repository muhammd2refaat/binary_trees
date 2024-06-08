#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, z;
/*	bst_t *root = NULL;*/
	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (z = 0; z < x; z++)
		{
			if (array[z] == array[x])
				break;
		}
		if (z == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}
/*	return (tree);*/
	return (tree);
}

