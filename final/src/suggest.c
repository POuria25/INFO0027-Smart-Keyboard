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
#include "utility.h"

void collect_next_chars(TstNode *node, char *collected, int *count)
{
    if (!node || *count >= 256)
        return;

    for (int i = 0; i < *count; i++)
    {
        if (collected[i] == node->data)
        {
            return;
        }
    }

    collected[*count] = node->data;
    (*count)++;

    collect_next_chars(node->left, collected, count);
    collect_next_chars(node->right, collected, count);
}

void check_from_node(TstNode *node, const char *prefix, char *collected, int *count)
{
    while (*prefix && node)
    {
        if (*prefix < node->data)
        {
            node = node->left;
        }
        else if (*prefix > node->data)
        {
            node = node->right;
        }
        else
        {
            if (*(prefix + 1) == '\0')
            {
                if (node->equal)
                {
                    collect_next_chars(node->equal, collected, count);
                }
                return;
            }
            prefix++;
            node = node->equal;
        }
    }
}

void check_prefix_in_tst(TstNode *root, const char *prefix, char *collected, int *count)
{
    if (!prefix || !root)
        return;

    check_from_node(root, prefix, collected, count);

    if (root->left)
    {
        check_prefix_in_tst(root->left, prefix, collected, count);
    }
    if (root->equal)
    {
        check_prefix_in_tst(root->equal, prefix, collected, count);
    }
    if (root->right)
    {
        check_prefix_in_tst(root->right, prefix, collected, count);
    }
}

void suggest(TstNode *root, const char *prefix)
{
    if (!root || !prefix)
    {
        fprintf(stderr, "suggest: Empty input\n");
        return;
    }

    TstNode *node = root;
    int isCompleteWord = 0;

    while (*prefix && node)
    {
        if (*prefix < node->data)
        {
            node = node->left;
        }
        else if (*prefix > node->data)
        {
            node = node->right;
        }
        else
        {
            if (*(prefix + 1) == '\0')
            {
                isCompleteWord = node->isEndOfString;
                break;
            }
            prefix++;
            node = node->equal;
        }
    }

    // if the prefix is not found directly in the TST
    if (!node)
    {
        char tmp[256] = {0};
        int count = 0;

        check_prefix_in_tst(root, prefix, tmp, &count);

        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                printf("%c\n", tmp[i]);
            }
        }
        else
        {
            printf("No suggestions found for %s \n", prefix);
        }
    }

    char collected[256] = {0};
    int count = 0;

    if (isCompleteWord)
    {
        printf(".\n");
        if (node->equal && has_additional_words(node->equal))
        {
            printf("-\n");
            return;
        }
    }
    else
    {

        check_from_node(node, prefix, collected, &count);
    }

    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            printf("%c\n", collected[i]);
        }
    }
}
