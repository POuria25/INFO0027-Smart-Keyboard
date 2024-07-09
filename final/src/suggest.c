
/**
 * @file suggest.c
 * @brief Implementation file for the Suggest module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the implementations of functions used in the Suggest module.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "suggest.h"

void collectNextCharacters(TstNode *root, char *buffer, int depth, char *nextChars, int *charCount)
{
    if (!root)
        return;

    if (root->isEndOfString && depth == 0)
    {
        return;
    }

    if (depth == 0 && root->data != '\0')
    {
        nextChars[*charCount] = root->data;
        (*charCount)++;
    }

    collectNextCharacters(root->left, buffer, depth, nextChars, charCount);
    collectNextCharacters(root->equal, buffer, depth - 1, nextChars, charCount);
    collectNextCharacters(root->right, buffer, depth, nextChars, charCount);
}

TstNode *findPrefixNode(TstNode *root, const char *prefix)
{
    while (root && *prefix)
    {
        if (*prefix < root->data)
        {
            root = root->left;
        }
        else if (*prefix > root->data)
        {
            root = root->right;
        }
        else
        {
            if (*(prefix + 1) == '\0')
            {
                return root;
            }
            root = root->equal;
            prefix++;
        }
    }
    return NULL;
}

void suggestWord(TstNode *root, const char *prefix)
{
    if (!root || !prefix)
    {
        fprintf(stderr, "suggestWord: Invalid input\n");
        return;
    }

    TstNode *prefixNode = findPrefixNode(root, prefix);

    if (!prefixNode)
    {
        printf("No suggestions found.\n");
        return;
    }

    char nextChars[MAX_WORD_LENGTH] = {0};
    int charCount = 0;

    if (prefixNode->equal)
    {
        collectNextCharacters(prefixNode->equal, NULL, 0, nextChars, &charCount);
    }

    for (int i = 0; i < charCount; i++)
    {
        if (nextChars[i] == ' ' || nextChars[i] == '-' || nextChars[i] == '_')
        {
            printf("%c\n", nextChars[i]);
        }
        else
        {
            int j;
            for (j = 0; j < i; j++)
            {
                if (nextChars[i] == nextChars[j])
                {
                    break;
                }
            }
            if (j == i)
            {
                printf("%c\n", nextChars[i]);
            }
        }
    }
}
