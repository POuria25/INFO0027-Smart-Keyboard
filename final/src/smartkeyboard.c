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



TstNode *create_node(char data, TstNode *parent)
{
    TstNode *node = (TstNode *)malloc(sizeof(TstNode));
    if (!node)
    {
        fprintf(stderr, "create_node: Memory allocation failed\n");
        return NULL;
    }

    node->data = data;
    node->isEndOfString = 0;
    node->left = NULL;
    node->equal = NULL;
    node->right = NULL;
    node->parent = parent;

    return node;
}

// Function to free the TST
void free_tst(TstNode *root)
{
    if (root)
    {
        if (root->left)
        {
            free_tst(root->left);
        }
        if (root->equal)
        {
            free_tst(root->equal);
        }
        if (root->right)
        {
            free_tst(root->right);
        }
        // if(root->parent)
        // {
        //     free(root->parent);
        // }
        free(root);
    }
}

void add_word_list(WordList *wordList, TstNode *node)
{
    if (!wordList || !node)
    {
        fprintf(stderr, "add_word_list: Invalid input\n");
        return;
    }

    WordList *newWord = (WordList *)malloc(sizeof(WordList));
    if (!newWord)
    {
        fprintf(stderr, "add_word_list: Memory allocation failed\n");
        return;
    }

    newWord->node = node;
    newWord->next = NULL;

    while (wordList->next)
    {
        wordList = wordList->next;
    }

    wordList->next = newWord;
}


void free_word_list(WordList *wordList)
{
    if (!wordList)
    {
        fprintf(stderr, "free_word_list: Invalid input\n");
        return;
    }

    WordList *temp;
    while (wordList)
    {
        temp = wordList;
        wordList = wordList->next;
        free(temp);
    }
}

// Function to insert a word into the TST
TstNode *insert(TstNode *root, const char *word, TstNode *parent) {
    if (!word || !*word) {
        return root;
    }

    if (!root) {
        root = create_node(*word, parent);
        if (!root) {
            fprintf(stderr, "[insert function]: Memory allocation failed\n");
            return NULL;
        }
    }

    if (*word < root->data) {
        //printf("Inserting %c to the left of %c\n", *word, root->data);
        root->left = insert(root->left, word, root);
    } else if (*word > root->data) {
        //printf("Inserting %c to the right of %c\n", *word, root->data);
        root->right = insert(root->right, word, root);
    } else {
        if (*(word + 1)) {
            //printf("Inserting %c to the middle of %c\n", *(word + 1), root->data);
            root->equal = insert(root->equal, word + 1, root);
        } else {
            root->isEndOfString = 1;
            //printf("Marking end of string at %c\n", root->data);
        }
    }
    return root;
}

