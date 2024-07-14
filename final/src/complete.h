
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
 * Finds all words in the Ternary Search Tree (TST) that have a given prefix.
 *
 * @param root The root node of the TST.
 * @param prefix The prefix to search for.
 * @param buffer The buffer to store the found words.
 * @param depth The current depth in the TST.
 */
void find_words(TstNode *root, const char *prefix, char *buffer, int depth);


/**
 * Completes a word based on a given prefix.
 *
 * This function takes a TstNode pointer `root` and a const char pointer `prefix` as parameters.
 * It completes a word based on the given prefix by traversing the Ternary Search Tree (TST) starting from the root node.
 * The completed word is printed to the standard output.
 *
 * @param root   A pointer to the root node of the Ternary Search Tree.
 * @param prefix The prefix of the word to be completed.
 */
void complet_word(TstNode *root, const char *prefix);


#endif // COMPLETE_H
