
/**
 * @file complete.c
 * @brief Implementation file for the Complete module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the implementations of functions used in the Complete module.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "complete.h"
#include "utility.h"


void find_words(TstNode *root, const char *prefix, char *buffer, int depth) {
    if (!root) return;

    buffer[depth] = root->data;
    buffer[depth + 1] = '\0';

    if (root->isEndOfString && strstr(buffer, prefix) != NULL) {
        printf("%s\n", convert_to_uppercase(buffer));
    }

    find_words(root->left, prefix, buffer, depth);
    find_words(root->equal, prefix, buffer, depth + 1);
    find_words(root->right, prefix, buffer, depth);
}


void complet_word(TstNode *root, const char *prefix) {
    if (!root || !prefix) {
        fprintf(stderr, "complet_word: Invalid input\n");
        return;
    }

    char buffer[256] = {0}; // Adjust buffer size as needed
    find_words(root, prefix, buffer, 0);
}