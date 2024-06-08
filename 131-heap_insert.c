#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and NULL is returned.
 * NOTE: The new node is not inserted into the queue.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, part, level, temporary;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;
	/* subtract all nodes except for bottom-most level */
	for (part = 1 << (level - 1); part != 1; part >>= 1)
		tree = leaves & part ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * representation of the number of leaves.
	 * Example -
	 * If there are 12 nodes in a complete tree, there are 5 leaves on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *root->right->left->right
	 * *root->right->right->left
	 * The bit value is 1 << (level - 1)
	 * The bit mask is 1 << (level - 1)
	 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
	 * NOTE: The new node is not inserted into the queue.
	 */
	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);
	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		temporary = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = temporary;
		new = new->parent;
	}
	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
/*	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));*/
	/* 1 + size of left + size of right */
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
