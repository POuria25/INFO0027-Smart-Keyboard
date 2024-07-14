
/**
 * @file utility.h
 * @brief Header file for the utility module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the declarations of functions used in the utility module.
 */

#ifndef UTILITY_H
#define UTILITY_H

#include "smartkeyboard.h"

#include <stdbool.h>

/**
 * Reads a file and inserts the words into a Ternary Search Tree (TST).
 *
 * @param root The root node of the TST.
 * @param filename The name of the file to be read.
 * @return 0 if the file was read successfully, 1 otherwise.
 */
int read_file(TstNode *root, char *filename);

/**
 * Converts a word to lowercase.
 *
 * @param word The word to be converted.
 * @return The lowercase version of the word.
 */
char *convert_to_lowercase(char *word);

/**
 * Converts the first letter of each word in a string to uppercase.
 *
 * @param str The string to be converted.
 * @return The string with the first letter of each word in uppercase.
 */
char *convert_to_uppercase(char *str);

/**
 * Checks if a word is valid.
 *
 * @param word The word to be checked.
 * @return The word if it is valid, NULL otherwise.
 */
char *check_word(char *word);

/**
 * Checks if a word is valid.
 *
 * @param word The word to be checked.
 * @return The word if it is valid, NULL otherwise.
 */
int has_additional_words(TstNode *node);

/**
 * Checks if a word is valid.
 *
 * @param word The word to be checked.
 * @return The word if it is valid, NULL otherwise.
 */
bool is_complete_word(TstNode *root, const char *prefix);
#endif // utility_H