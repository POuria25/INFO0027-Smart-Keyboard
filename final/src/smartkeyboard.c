
/**
 * @file smartkeyboard.c
 * @brief Implementation file for the Smart Keyboard module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the implementations of functions used in the Smart Keyboard module.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "smartkeyboard.h"

// Function to create a new node
TstNode *createNode(char data)
{
    TstNode *node = (TstNode *)malloc(sizeof(TstNode));
    if (!node)
    {
        fprintf(stderr, "Memory allocation failed \n");
        return NULL;
    }
    node->data = data;
    node->isEndOfString = 0;
    node->left = NULL;
    node->equal = NULL;
    node->right = NULL;

    return node;
}

// Function to insert a new word in the TST
TstNode *insert(TstNode *root, char *word)
{
    // Check if the word is NULL or empty
    if (!word || !*word)
    {
        return root;
    }
    // If root is NULL, create a new node
    if (!root)
    {
        root = createNode(*word);
        if (!root)
        {
            fprintf(stderr, "[insert function]: Memory allocation failed\n");
            return NULL;
        }
    }
    // Insert the word in the appropriate subtree
    if (*word < root->data)
    {
        root->left = insert(root->left, word);
    }
    else if (*word > root->data)
    {
        root->right = insert(root->right, word);
    }
    else
    {
        // If we reach the end of the word, mark this node as end of string
        if (*(word + 1))
        {
            root->equal = insert(root->equal, word + 1);
        }
        else
        {
            root->isEndOfString = 1;
        }
    }
    return root;
}

// Function to free the TST
void freeTst(TstNode *root)
{
    if (root)
    {
        if (root->left)
        {
            freeTst(root->left);
        }
        if (root->equal)
        {
            freeTst(root->equal);
        }
        if (root->right)
        {
            freeTst(root->right);
        }
        free(root);
    }
}
