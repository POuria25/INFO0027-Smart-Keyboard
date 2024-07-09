
/**
 * @file util.h
 * @brief Header file for the Util module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the declarations of functions used in the Util module.
 */

#ifndef UTIL_H
#define UTIL_H

#include "smartkeyboard.h"

/**
 * Reads a file and inserts the words into a Ternary Search Tree (TST).
 *
 * @param root The root node of the TST.
 * @param filename The name of the file to be read.
 * @return 0 if the file was read successfully, 1 otherwise.
 */
int readfile(TstNode *root, char *filename);

/**
 * Converts a word to lowercase.
 *
 * @param word The word to be converted.
 * @return The lowercase version of the word.
 */
char *convertToLower(const char *word);

/**
 * Converts the first letter of each word in a string to uppercase.
 *
 * @param str The string to be converted.
 * @return The string with the first letter of each word in uppercase.
 */
char *uppercase(char *str);

#endif // UTIL_H