
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

/**
 * @brief Structure for a Ternary Search Tree (TST) node.
 * @param data The character data stored in the node.
 * @param isEndOfString A flag indicating if the node marks the end of a word.
 * @param left A pointer to the left child node.
 * @param equal A pointer to the equal child node.
 * @param right A pointer to the right child node.
 */
struct TstNode
{
    char data;
    int isEndOfString;
    TstNode *left;
    TstNode *equal;
    TstNode *right;
    TstNode *parent;
};

/**
 * @brief Structure for a list of words.
 * @param node A pointer to the TST node containing the word.
 * @param next A pointer to the next word in the list.
 */
typedef struct WordList {
    TstNode *node;
    struct WordList *next;
} WordList;


/**
 * @brief Creates a new TST node with the specified character data.
 *
 * @param data The character data to be stored in the node.
 * @param parent The parent node of the new node.
 * @return A pointer to the newly created TST node.
 */
TstNode *create_node(char data, TstNode *parent);

/**
 * @brief Frees the memory allocated for the TST.
 *
 * @param root The root node of the TST.
 */
void free_tst(TstNode *root);

/**
 * @brief Adds a word to the word list.
 *
 * @param wordList The word list to add the word to.
 * @param node The TST node containing the word.
 */
void add_word_list(WordList *wordList, TstNode *node);

/**
 * @brief Frees the memory allocated for the word list.
 *
 * @param wordList The word list to be freed.
 */
void free_word_list(WordList *wordList);

/**
 * @brief Inserts a word into the TST.
 *
 * @param root The root node of the TST.
 * @param word The word to be inserted.
 * @return The root node of the TST after inserting the word.
 */
TstNode *insert(TstNode *root, const char *word, TstNode *parent);

#endif // SMARTKEYBOARD_H
