#ifndef SMARTKEYBOARD_H
#define SMARTKEYBOARD_H

#define ALPHABET_SIZE 28

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

void collectWords(TstNode *root, char *buffer, int depth);

TstNode *findPrefixNode(TstNode *root, const char *prefix);

void findAllWordsFromNode(TstNode *root, const char *prefix, char *buffer, int depth);

void completWord(TstNode *root, const char *prefix);

void collectNextCharacters(TstNode *root, char *buffer, int depth, char *nextChars, int *charCount);

void suggestWord(TstNode *root, const char *prefix);



#endif