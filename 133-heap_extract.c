#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 * NOTE: The new node is not inserted into the queue.
 * DESCRIPTION: However, the new node is not inserted into the queue.
 * Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * heigth = 1 + max(height(left), height(right))
 * height = 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;
/*	size_t height = 0;*/
	if (!tree)
		return (0);
/*	height_left = 1 + tree_height(tree->left);*/
	if (tree->left)
		height_left = 1 + tree_height(tree->left);
/*	height_right = 1 + tree_height(tree->right);*/
	if (tree->right)
		height_right = 1 + tree_height(tree->right);
/*	return (height_left + height_right);*/
	if (height_left > height_right)
		return (height_left);
	return (height_right);
}
/**
 * tree_size_h - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 * height = 1 + max(height(left), height(right))
 * height = 0 if tree is NULL
 * NOTE: The new node is not inserted into the queue.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;
/*	size_t height = 0;*/
	if (!tree)
		return (0);
/*	height_left = 1 + tree_size_h(tree->left);*/
	if (tree->left)
		height_left = 1 + tree_size_h(tree->left);
/*	height_right = 1 + tree_size_h(tree->right);*/
	if (tree->right)
		height_right = 1 + tree_size_h(tree->right);
/*	return (height_left + height_right);*/
	return (height_left + height_right);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 *
 * Return: No Return
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;
/*	_preorder(tree->left, node, height);*/
	if (!height)
		*node = tree;
	height--;
/*	_preorder(tree->left, node, height);*/
	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *temporary1, *temporary2;
/*	binary_tree_t *root = NULL;*/
	if (!root)
		return;
/*	return (binary_tree_is_complete(root));*/
	temporary1 = root;
/*	binary_tree_levelorder(root, heapify);*/
	while (1)
	{
		if (!temporary1->left)
			break;
		if (!temporary1->right)
			temporary2 = temporary1->left;
		else
		{
			if (temporary1->left->n > temporary1->right->n)
				temporary2 = temporary1->left;
			else
				temporary2 = temporary1->right;
		}
		if (temporary1->n > temporary2->n)
			break;
		value = temporary1->n;
		temporary1->n = temporary2->n;
		temporary2->n = value;
		temporary1 = temporary2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int outcome;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	outcome = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (outcome);
	}
/*	_preorder(heap_r, &node, tree_height(heap_r));*/
	_preorder(heap_r, &node, tree_height(heap_r));
/*	node->parent = NULL;*/
	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (outcome);
}
