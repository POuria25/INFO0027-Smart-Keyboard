
/**
 * @file suggest.h
 * @brief Header file for the Suggest module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the declarations of functions used in the Suggest module.
 */

#ifndef SUGGEST_H
#define SUGGEST_H

#include <stdbool.h>

#include "smartkeyboard.h"

/**
 * Collects the next characters from the given TST node.
 *
 * This function collects the next characters from the given Ternary Search Tree (TST) node
 * and stores them in the `collected` array. The number of collected characters is stored in
 * the `count` variable.
 *
 * @param node      The TST node from which to collect the next characters.
 * @param collected The array to store the collected characters.
 * @param count     A pointer to an integer to store the number of collected characters.
 */
void collect_next_chars(TstNode *node, char *collected, int *count);


/**
 * Searches for words starting with a given prefix in a Ternary Search Tree (TST).
 *
 * This function traverses the TST starting from the specified node and collects all words
 * that have a prefix matching the given prefix. The collected words are stored in the
 * `collected` array, and the number of collected words is stored in the `count` variable.
 *
 * @param node      The starting node of the TST traversal.
 * @param prefix    The prefix to search for.
 * @param collected An array to store the collected words.
 * @param count     A pointer to an integer to store the number of collected words.
 */
void check_from_node(TstNode *node, const char *prefix, char *collected, int *count);


/**
 * Searches for words starting with a given prefix in a Ternary Search Tree (TST).
 *
 * This function traverses the TST starting from the given node and collects all the words
 * that start with the specified prefix. The collected words are stored in the `collected`
 * array, and the number of collected words is stored in the `count` variable.
 *
 * @param node      The starting node of the TST.
 * @param prefix    The prefix to search for.
 * @param collected An array to store the collected words.
 * @param count     A pointer to an integer to store the number of collected words.
 */
void check_from_node(TstNode *node, const char *prefix, char *collected, int *count);

/**
 * Searches for words with a given prefix in a Ternary Search Tree (TST).
 *
 * This function traverses the TST starting from the root node and collects all the words
 * that have the specified prefix. The collected words are stored in the `collected` array,
 * and the number of collected words is stored in the `count` variable.
 *
 * @param root      The root node of the TST.
 * @param prefix    The prefix to search for.
 * @param collected An array to store the collected words.
 * @param count     A pointer to an integer to store the number of collected words.
 */
void check_prefix_in_tst(TstNode *root, const char *prefix, char *collected, int *count);


/**
 * Suggests words based on a given prefix.
 *
 * This function takes a Ternary Search Tree (TST) root node and a prefix string as input.
 * It suggests words that match the given prefix by traversing the TST.
 *
 * @param root The root node of the TST.
 * @param prefix The prefix string to match.
 */
void suggest(TstNode *root, const char *prefix);


#endif // SUGGEST_H