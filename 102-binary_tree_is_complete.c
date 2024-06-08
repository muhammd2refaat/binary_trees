#include "binary_trees.h"

leveller_queue_t *create_node(binary_tree_t *node);
void free_queue(leveller_queue_t *head);
void push(binary_tree_t *node, leveller_queue_t *head,
		leveller_queue_t **tail);
void pop(leveller_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new leveller_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
leveller_queue_t *create_node(binary_tree_t *node)
{/*leveller_queue_t *newer;*/
	leveller_queue_t *newer;
/*newer = malloc(sizeof(leveller_queue_t));*/
	newer = malloc(sizeof(leveller_queue_t));
	if (newer == NULL)
		return (NULL);
/*newer = malloc(sizeof(leveller_queue_t));*/
	newer->node = node;
	newer->next = NULL;
/*return (newer);*/
	return (newer);
}

/**
 * free_queue - Frees a leveller_queue_t queue.
 * @head: A pointer to the head of the queue.
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The queue is not freed.
 */
void free_queue(leveller_queue_t *head)
{
	leveller_queue_t *temporary;

	while (head != NULL)
	{
		temporary = head->next;
		free(head);
		head = temporary;
	}
}

/**
 * push - Pushes a node to the back of a leveller_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * DESCRIPTION: Upon malloc failure, exits with a status code of 1.
 * and 0 is returned.
 * NOTE: The new node is not inserted into the queue.
 */
void push(binary_tree_t *node, leveller_queue_t *head,
		leveller_queue_t **tail)
{/*leveller_queue_t *newer;*/
	leveller_queue_t *newer;
/*newer = malloc(sizeof(leveller_queue_t));*/
	newer = create_node(node);
	if (newer == NULL)
	{
		free_queue(head);
		exit(1);
/*		return (NULL);*/
	}
	(*tail)->next = newer;
	*tail = newer;
}

/**
 * pop - Pops the head of a leveller_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(leveller_queue_t **head)
{
	leveller_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	leveller_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
