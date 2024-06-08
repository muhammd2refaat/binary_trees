#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 * NOTE: Upon failure, exits with a status code of 1.
 * and 0 is returned.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int x;
	heap_t *root = NULL;
/*	heap_t *root = NULL;*/
	for (x = 0; x < size; x++)
		heap_insert(&root, array[x]);
/*	return (root);*/
	return (root);
}
