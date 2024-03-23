#ifndef SMARTKEYBOARD_H
#define SMARTKEYBOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 28

#define char_to_index(c) (c == ' ' ? 26 : c == '-' ? 27 : c == '.'  ? 28 : c - 'a')
#define index_to_char(c) (c == 26 ? ' ' : c == 27 ? '-' : c == 28 ? '.' : c + 'a')

typedef struct TrieNode TrieNode;



struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int EndOfWord;
};


/**
 * Creates a new TrieNode.
 *
 * @return A pointer to the newly created TrieNode.
 */
TrieNode *createNode();

/**
 * Inserts a word into the Trie data structure.
 *
 * @param root The root node of the Trie.
 * @param word The word to be inserted.
 * @return The number of characters inserted into the Trie.
 */
int insert(TrieNode *root, char *word);

/**
 * Reads a file and inserts its contents into a Trie data structure.
 *
 * @param root The root node of the Trie data structure.
 * @param filename The name of the file to be read.
 * @return The number of words successfully inserted into the Trie.
 */
int read_file(TrieNode *root, char *filename);

/**
 * @brief Suggests words based on a given prefix.
 * 
 * This function takes a TrieNode pointer and a prefix string as input and suggests words that have the given prefix.
 * 
 * @param root A pointer to the root node of the trie.
 * @param prefix The prefix string to search for.
 * @return The number of suggested words.
 */
int suggestWords(TrieNode *root, const char *prefix);

/**
 * Prints all the words in the Trie starting with the given prefix.
 *
 * @param root The root node of the Trie.
 * @param prefix The prefix string to search for.
 * @return The number of words printed.
 */
int printWord(TrieNode *root, char *prefix);

/**
 * Finds the number of words in a Trie data structure that have the given prefix.
 *
 * @param root The root node of the Trie data structure.
 * @param prefix The prefix to search for.
 * @return The number of words in the Trie that have the given prefix.
 */
int completWord(TrieNode *root, const char *prefix);

#endif