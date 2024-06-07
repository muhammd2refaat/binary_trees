#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{/*	binary_tree_t *parent;*/
	binary_tree_t *setter;
/*	binary_tree_t *parent;*/
	if (parent == NULL)
		return (NULL);
/*	binary_tree_t *parent;*/
	setter = binary_tree_node(parent, value);
	if (setter == NULL)
		return (NULL);
/**parent = setter;*/
	if (parent->left != NULL)
	{
		setter->left = parent->left;
		parent->left->parent = setter;
	}
	parent->left = setter;
/**setter = parent;*/
	return (setter);
}

