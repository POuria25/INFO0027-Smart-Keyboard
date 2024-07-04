#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "smartkeyboard.h"

#define MAX_WORD_LENGTH 28

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

char *convertToLower(const char *word)
{
    if (word == NULL)
    {
        return NULL;
    }
    size_t length = strlen(word);
    char *lowercaseWord = (char *)malloc(length + 1); // Allocate memory for the modified word
    if (lowercaseWord == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (size_t i = 0; i < length; i++)
    {
        lowercaseWord[i] = tolower(word[i]); // Convert each character to lowercase
    }
    lowercaseWord[length] = '\0'; // Add the null terminator

    return lowercaseWord;
}

int readfile(TstNode *root, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Opening File Failed\n");
        return EXIT_FAILURE;
    }
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }
        char *new = malloc(strlen(line) + 1);
        strcpy(new, line);
        if (!new)
        {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(file);
            return EXIT_FAILURE;
        }

        char *tmp = convertToLower(new);
        free(new);
        root = insert(root, tmp);
        free(tmp);
        if (!root)
        {
            fprintf(stderr, "insert: Failed to insert word\n");
            fclose(file);
            return EXIT_FAILURE;
        }
    }
    // printWords(root);
    fclose(file);
    return EXIT_SUCCESS;
}

void collectWords(TstNode *root, char *buffer, int depth)
{
    if (!root)
        return;

    buffer[depth] = root->data;
    buffer[depth + 1] = '\0';

    if (root->left)
    {
        collectWords(root->left, buffer, depth);
    }

    if (root->isEndOfString)
    {
        printf("%s\n", buffer);
    }

    if (root->equal)
    {
        collectWords(root->equal, buffer, depth + 1);
    }

    if (root->right)
    {
        collectWords(root->right, buffer, depth);
    }
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

void findAllWordsFromNode(TstNode *root, const char *prefix, char *buffer, int depth)
{
    if (!root)
        return;

    buffer[depth] = root->data;
    buffer[depth + 1] = '\0';

    if (root->isEndOfString && strstr(buffer, prefix) != NULL)
    {
        buffer[depth + 1] = '\0';
        printf("%s\n", buffer);
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
