#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list unsing insertion sort
 * @list: doubly linked list head pointer
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *after;
	if (*list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		after = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			if (current->prev->prev == NULL)
			{
				current->prev->prev = current;
				current->prev->next = current->next;
				current->next = current->prev;
				current->prev = NULL;
				if (*list != NULL)
					(*list)->prev = current;
				*list = current;
			}
			else
			{
				current->next = current->prev;
				current->prev = current->prev->prev;
				current->prev->next->prev = current;
				current->prev->next = current;
			}
			print_list(*list);
		}
		current = after;
	}
}
