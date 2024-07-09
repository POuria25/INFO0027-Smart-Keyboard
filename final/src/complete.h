
/**
 * @file complete.h
 * @brief Header file for the Complete module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the declarations of functions used in the Complete module.
 */

#ifndef COMPLETE_H
#define COMPLETE_H

#include "smartkeyboard.h"

/**
 * Collects all the words in the Ternary Search Tree (TST) and prints them.
 *
 * @param root The root node of the TST.
 */
void collectWords(TstNode *root, char *buffer, int depth);

/**
 * Finds the node that corresponds to the given prefix.
 *
 * @param root The root node of the TST.
 * @param prefix The prefix to be searched for.
 * @return The node that corresponds to the given prefix.
 */
TstNode *findPrefixNode(TstNode *root, const char *prefix);

/**
 * Finds all the words that start with the given prefix and prints them.
 *
 * @param root The root node of the TST.
 * @param prefix The prefix to be searched for.
 */
void findAllWordsFromNode(TstNode *root, const char *prefix, char *buffer, int depth);

/**
 * Completes the given word and prints the suggestions.
 *
 * @param root The root node of the TST.
 * @param prefix The word to be completed.
 */
void completWord(TstNode *root, const char *prefix);

#endif // COMPLETE_H