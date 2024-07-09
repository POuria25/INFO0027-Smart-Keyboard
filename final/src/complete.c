
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
#include "util.h"

void findAllWordsFromNode(TstNode *root, const char *prefix, char *buffer, int depth)
{
    if (!root)
        return;

    buffer[depth] = root->data;
    buffer[depth + 1] = '\0';

    if (root->isEndOfString && strstr(buffer, prefix) != NULL)
    {
        buffer[depth + 2] = '\0';
        printf("%s\n", uppercase(buffer));
    }

    findAllWordsFromNode(root->left, prefix, buffer, depth);
    findAllWordsFromNode(root->equal, prefix, buffer, depth + 1);
    findAllWordsFromNode(root->right, prefix, buffer, depth);
}

void completWord(TstNode *root, const char *prefix)
{
    if (!root || !prefix)
    {
        fprintf(stderr, "completWord: Invalid input\n");
        return;
    }

    if (!prefix)
    {
        fprintf(stderr, "completWord: Memory allocation failed\n");
        return;
    }

    char buffer[MAX_WORD_LENGTH] = {0};
    findAllWordsFromNode(root, prefix, buffer, 0);
}