#include "binary_trees.h"

leveller_queue_t *create_node(binary_tree_t *node);
void free_queue(leveller_queue_t *head);
void pint_push(binary_tree_t *node, leveller_queue_t *head,
		leveller_queue_t **tail, void (*func)(int));
void pop(leveller_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new leveller_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * and 0 is returned.
 * NOITE: The new node is not inserted into the queue.
 */
leveller_queue_t *create_node(binary_tree_t *node)
{
	leveller_queue_t *newer;

	newer = malloc(sizeof(leveller_queue_t));
	if (newer == NULL)
		return (NULL);

	newer->node = node;
	newer->next = NULL;

	return (newer);
}

/**
 * free_queue - Frees a leveller_queue_t queue.
 * @head: A pointer to the head of the queue.
 * Description: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The queue is not freed.
 */
void free_queue(leveller_queue_t *head)
{
	leveller_queue_t *change;

	while (head != NULL)
	{
		change = head->next;
		free(head);
		head = change;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a leveller_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
void pint_push(binary_tree_t *node, leveller_queue_t *head,
		leveller_queue_t **tail, void (*func)(int))
{
	leveller_queue_t *newer;

	func(node->n);
	if (node->left != NULL)
	{
		newer = create_node(node->left);
		if (newer == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newer;
		*tail = newer;
	}
	if (node->right != NULL)
	{
		newer = create_node(node->right);
		if (newer == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newer;
		*tail = newer;
	}
}

/**
 * pop - Pops the head of a leveller_queue_t queue.
 * @head: A double pointer to the head of the queue.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
void pop(leveller_queue_t **head)
{
	leveller_queue_t *change;

	change = (*head)->next;
	free(*head);
	*head = change;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * DESCRIPTION: If tree or func is NULL, do nothing.
 * NOTE: The new node is not inserted into the queue.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	leveller_queue_t *header, *tall;

	if (tree == NULL || func == NULL)
		return;

	header = tall = create_node((binary_tree_t *)tree);
	if (header == NULL)
		return;

	while (header != NULL)
	{
		pint_push(header->node, header, &tall, func);
		pop(&header);
	}
}

