#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;
/*	size_t height = 0;*/
	if (!tree)
		return (0);
/*	height_left = 1 + tree_size(tree->left);*/
	if (tree->left)
		height_left = 1 + tree_size(tree->left);
/*	height_right = 1 + tree_size(tree->right);*/
	if (tree->right)
		height_right = 1 + tree_size(tree->right);
/*	return (height_left + height_right);*/
	return (height_left + height_right);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int u, *o = NULL;
/*	int *o = NULL;*/
	if (!heap || !size)
		return (NULL);
/*	size = tree_size(heap) + 1;*/
	*size = tree_size(heap) + 1;
/*	o = malloc(sizeof(int) * (*size));*/
	o = malloc(sizeof(int) * (*size));
/*	if (!o)*/
	if (!o)
		return (NULL);
/*	for (u = 0; heap; u++)*/
	for (u = 0; heap; u++)
		o[u] = heap_extract(&heap);
/*	return (o);*/
	return (o);
}
