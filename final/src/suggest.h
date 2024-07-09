
/**
 * @file suggest.h
 * @brief Header file for the Suggest module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the declarations of functions used in the Suggest module.
 */

#ifndef SUGGEST_H
#define SUGGEST_H

#include "smartkeyboard.h"

/**
 * Collects the next characters of the given node and prints them.
 *
 * @param root The root node of the TST.
 * @param buffer The buffer to store the word.
 * @param depth The current depth of the TST.
 * @param nextChars The next characters to be collected.
 * @param charCount The number of characters to be collected.
 */
void collectNextCharacters(TstNode *root, char *buffer, int depth, char *nextChars, int *charCount);

/**
 * Suggests a word based on the given prefix.
 *
 * @param root The root node of the TST.
 * @param prefix The prefix to be searched for.
 */
void suggestWord(TstNode *root, const char *prefix);

#endif // SUGGEST_H