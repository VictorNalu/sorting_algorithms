#include "sort.h"

/**
* swap_nodes - Swaps a node with its previous node in a doubly linked list
* @current: Node to swap
* @list: Pointer to the head of the list
* Return: Pointer to the node after swapping
*/
listint_t *swap_nodes(listint_t *current, listint_t **list)
{
	listint_t *prev = current->prev;
	listint_t *temp = current;

	prev->next = temp->next;
	if (temp->next)
		temp->next->prev = prev;

	temp->next = prev;
	temp->prev = prev->prev;
	prev->prev = temp;

	if (temp->prev)
		temp->prev->next = temp;
	else
		*list = temp;

	return (temp);
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Cocktail Shaker sort algorithm.
* @list: Pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;

	node = *list;
	while (swapped)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_nodes(node->next, list);
				swapped = 1;
				print_list(*list);
			}
			node = node->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_nodes(node, list);
				swapped = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
