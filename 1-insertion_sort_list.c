#include "sort.h"

void exchange_number(listint_t **h, listint_t **n1, listint_t *n2);
/**
 * insertion_sort_list - Sorts a linked list of integers using Insertion Sort.
 *
 * @list: Pointer to the head of the linked list.
 * Returns:
 *     None (void).
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *fact;
	listint_t *ballety;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (ballety = (*list)->next; ballety != NULL; ballety = tmp)
	{
		tmp = ballety->next;
		fact = ballety->prev;
		while (fact != NULL && ballety->n < fact->n)
		{
			exchange_number(list, &fact, ballety);
			print_list((const listint_t *)*list);
		}
	}
}
/**
 * exchange_number - Exchange a node's value with a given integer.
 *
 * @h: Pointer to the head of the linked list.
 * @n1: Pointer to the node whose value will be exchanged.
 * @n2: Pointer to the integer value for the exchange.
 * Returns:
 *     None (void).
 */
void exchange_number(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
