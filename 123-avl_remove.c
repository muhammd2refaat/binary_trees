#include "binary_trees.h"

/**
 * bal - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 * DESCRIPTION: If tree is NULL, your function must return 0.
 * and 0 is returned.
 *
 * NOTE: The new node is not inserted into the queue.
 *
 */
void bal(avl_t **tree)
{
	int palaver;
/**if (tree == NULL || *tree == NULL)*/
	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	palaver = binary_tree_balance((const binary_tree_t *)*tree);
	if (palaver > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (palaver < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 *
 * DESCRIPTION: If tree is NULL, your function must return 0.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 *
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1 .
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
int remove_type(bst_t *root)
{
	int new_addition = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_addition = successor(root->right);
		root->n = new_addition;
		return (new_addition);
	}
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1 .
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int new_add = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		new_add = remove_type(root);
		if (new_add != 0)
			bst_remove(root->right, new_add);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1 .
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
