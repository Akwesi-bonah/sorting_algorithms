#include "sort.h"
/**
 * swap - swap the node with it's previous
 * @node: node to swap
 */
void swap(listint_t *node)
{
	listint_t *before = node->prev;

	if (node->next)
		node->next->prev = before;
	if (before->prev)
		before->prev->next = node;
	before->next = node->next;
	node->prev = before->prev;
	before->prev = node;
	node->next = before;
}

/**
 * insertion_sort_list - sorts a double linked list of integers in
 * ascending order using the insertion sort
 * algorithm
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p, *node, *head;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head = *list;
	p = head->next;
	while (p != NULL)
	{
		node = p;
		while (node->prev != NULL)
		{
			if (node->prev->n > node->n)
			{
				swap(node);
				if (node->prev == NULL)
					*list = node;
				print_list(*list);
			}
			else
				node = node->prev;
		}
		p = p->next;
	}
}
