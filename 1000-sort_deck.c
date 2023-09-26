#include "deck.h"

/**
 * insertion_sort_deck_kind - Sort a deck of cards by kind (S, H, C, D).
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp)
    {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL && insert->card->kind > iter->card->kind)
        {
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/**
 * insertion_sort_deck_value - Sort a deck of cards by value within each kind.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
    deck_node_t *iter, *insert, *tmp;

    for (iter = (*deck)->next; iter != NULL; iter = tmp)
    {
        tmp = iter->next;
        insert = iter->prev;
        while (insert != NULL &&
               insert->card->kind == iter->card->kind &&
               _strcmp(insert->card->value, iter->card->value) > 0)
        {
            insert->next = iter->next;
            if (iter->next != NULL)
                iter->next->prev = insert;
            iter->prev = insert->prev;
            iter->next = insert;
            if (insert->prev != NULL)
                insert->prev->next = iter;
            else
                *deck = iter;
            insert->prev = iter;
            insert = iter->prev;
        }
    }
}

/**
 * sort_deck - Sort a deck of cards by kind and then by value within each kind.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    insertion_sort_deck_kind(deck);
    insertion_sort_deck_value(deck);
}

