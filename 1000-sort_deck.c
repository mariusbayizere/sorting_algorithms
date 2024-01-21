#include "deck.h"

void sub_sort_deck_type(deck_node_t **deck);
int String_compore(const char *s1, const char *s2);
void sub_deck_expression(deck_node_t **deck);
char numerical_values(deck_node_t *card);
void sort_deck(deck_node_t **deck);

/**
 * String_compore - Compare two strings case-insensitively.
 *
 * @ch1: Pointer to the first string.
 * @cha2: Pointer to the second string.
 * Return:
 * 0 if the strings are equal, a positive value if ch1 is greater,
 * and a negative value if cha2 is greater.
 */
int String_compore(const char *ch1, const char *cha2)
{
	while (*ch1 && *cha2 && *ch1 == *cha2)
	{
		ch1++;
		cha2++;
	}

	if (*ch1 != *cha2)
		return (*ch1 - *cha2);
	return (0);
}

/**
 * sort_deck - Sort a doubly linked list of cards in ascending order.
 *
 * @deck: Double pointer to the head of the doubly linked list.
 * Return: void.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sub_sort_deck_type(deck);
	sub_deck_expression(deck);
}

/**
 * numerical_values - Extract numerical values from a deck of cards.
 *
 * @card: Pointer to the head of the doubly linked list representing cards.
 * Return:
 * A character representing the result numerical values.
 */
char numerical_values(deck_node_t *card)
{
	if (String_compore(card->card->value, "Ace") == 0)
		return (0);
	if (String_compore(card->card->value, "1") == 0)
		return (1);
	if (String_compore(card->card->value, "2") == 0)
		return (2);
	if (String_compore(card->card->value, "3") == 0)
		return (3);
	if (String_compore(card->card->value, "4") == 0)
		return (4);
	if (String_compore(card->card->value, "5") == 0)
		return (5);
	if (String_compore(card->card->value, "6") == 0)
		return (6);
	if (String_compore(card->card->value, "7") == 0)
		return (7);
	if (String_compore(card->card->value, "8") == 0)
		return (8);
	if (String_compore(card->card->value, "9") == 0)
		return (9);
	if (String_compore(card->card->value, "10") == 0)
		return (10);
	if (String_compore(card->card->value, "Jack") == 0)
		return (11);
	if (String_compore(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sub_deck_expression - Rearrange a doubly linked list of cards based
 * on a custom expression.
 *
 * @deck: Double pointer to the head of the doubly linked list.
 * Return: void.
 */
void sub_deck_expression(deck_node_t **deck)
{
	deck_node_t *few, *insert, *tempp;

	for (few = (*deck)->next; few != NULL; few = tempp)
	{
		tempp = few->next;
		insert = few->prev;
		while (insert != NULL &&
		       insert->card->kind == few->card->kind &&
		       numerical_values(insert) > numerical_values(few))
		{
			insert->next = few->next;
			if (few->next != NULL)
				few->next->prev = insert;
			few->prev = insert->prev;
			few->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = few;
			else
				*deck = few;
			insert->prev = few;
			insert = few->prev;
		}
	}
}

/**
 * sub_sort_deck_type - Sort a doubly linked list of cards by card type.
 *
 * @deck: Double pointer to the head of the doubly linked list.
 * Return: void.
 */
void sub_sort_deck_type(deck_node_t **deck)
{
	deck_node_t *few, *insert, *tempp;

	for (few = (*deck)->next; few != NULL; few = tempp)
	{
		tempp = few->next;
		insert = few->prev;
		while (insert != NULL && insert->card->kind > few->card->kind)
		{
			insert->next = few->next;
			if (few->next != NULL)
				few->next->prev = insert;
			few->prev = insert->prev;
			few->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = few;
			else
				*deck = few;
			insert->prev = few;
			insert = few->prev;
		}
	}
}
