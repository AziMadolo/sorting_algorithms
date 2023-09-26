#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * An enumeration representing card suits.
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * A structure representing a playing card.
 *
 * @value: The value of the card, ranging from "Ace" to "King".
 * @kind: The suit of the card.
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * A structure representing a node in a deck of cards.
 *
 * @card: A pointer to the card associated with this node.
 * @prev: A pointer to the previous node in the deck.
 * @next: A pointer to the next node in the deck.
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

/**
 * Sorts a deck of cards in a specified order.
 *
 * @deck: A pointer to a pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */

