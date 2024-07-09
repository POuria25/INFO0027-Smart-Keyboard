
/**
 * @file smartkeyboard.h
 * @brief Header file for the Smart Keyboard module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the declarations of functions and structures used in the Smart Keyboard module.
 * The Smart Keyboard module implements a Ternary Search Tree (TST) data structure for efficient word insertion and retrieval.
 */

#ifndef SMARTKEYBOARD_H
#define SMARTKEYBOARD_H

#define ALPHABET_SIZE 28
#define MAX_WORD_LENGTH 28

typedef struct TstNode TstNode;

struct TstNode
{
    char data;
    int isEndOfString;
    TstNode *left;
    TstNode *equal;
    TstNode *right;
};

/**
 * Creates a new node with the given data.
 *
 * @param data The data to be stored in the node.
 * @return A pointer to the newly created node.
 */
TstNode *createNode(char data);

/**
 * Inserts a new word into the Ternary Search Tree (TST).
 *
 * @param root The root node of the TST.
 * @param word The word to be inserted.
 * @return The updated root node of the TST.
 */
TstNode *insert(TstNode *root, char *word);

/**
 * Frees the memory allocated for a Ternary Search Tree (TST).
 *
 * @param root The root node of the TST to be freed.
 */
void freeTst(TstNode *root);

#endif