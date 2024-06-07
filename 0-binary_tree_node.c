#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *         Note that the node is not placed in any tree yet.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *getter;
/*	binary_tree_t *parent;*/
	getter = malloc(sizeof(binary_tree_t));
	if (getter == NULL)
		return (NULL);
/**getter = malloc(sizeof(binary_tree_t));*/
	getter->n = value;
	getter->parent = parent;
	getter->left = NULL;
	getter->right = NULL;
/**parent = getter;*/
	return (getter);
}

