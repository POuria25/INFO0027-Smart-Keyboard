#include "smartkeyboard.h"

// Create a new TrieNode
TrieNode *createNode()
{
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->EndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        newNode->children[i] = NULL;
    return newNode;
}


// Insert a word into the Trie
int insert(TrieNode *root, char *word)
{
    if(!root || !word)
    {
        printf("Word Insertion Failed\n");
        return EXIT_FAILURE;
    }
    int length = strlen(word);
    TrieNode *tmp = root;
    for (int i = 0; i < length; i++)
    {
        int j = word[i] - 'a';
        if (tmp->children[j] == NULL)
            tmp->children[j] = createNode();
        tmp = tmp->children[j];
    }
    tmp->EndOfWord = 1;

    return EXIT_SUCCESS;
}

// // Read the file
int read_file(TrieNode *root, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("File not found\n");
        return EXIT_FAILURE;
    }
    char word[30];
    while (fscanf(file, "%s", word) != EOF)
    {
        if(insert(root, word))
        {
            return EXIT_SUCCESS;
        }
        printf("Word Insertion Failed\n");
        return EXIT_FAILURE;
    }
    fclose(file);
    return EXIT_SUCCESS;
}


// // Suggest words based on the prefix
int suggestWords(TrieNode *root, const char *prefix)
{
    if(!root || !prefix)
    {
        printf("Word Suggestion Failed\n");
        return EXIT_FAILURE;
    }
    int length = strlen(prefix);
    TrieNode *tmp = root;

    for (int i = 0; i < length; i++)
    {
        int j = tolower(prefix[i]) - 'a';
        if (!tmp->children[j])
        {
            printf("No words found with this prefix\n");
            return EXIT_FAILURE;
        }
        tmp = tmp->children[j];
    }
    printWord(tmp, (char *)prefix);
    return EXIT_SUCCESS;
}

int printWord(TrieNode *root, char *prefix)
{
    if(!root || !prefix || *prefix == '\0')
    {
        printf("Word Suggestion Failed\n");
        return EXIT_FAILURE;
    }
    if(root->EndOfWord)
    {
        printf("%s\n", (char *)prefix);
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(root->children[i])
        {
            prefix[strlen(prefix)] = i + 'a';
            printWord(root->children[i], (char *)prefix);
            prefix[strlen(prefix) - 1] = '\0';
        }
    }
    return EXIT_SUCCESS;
}


int completWord(TrieNode *root, const char *prefix)
{
    if(!root || !prefix)
    {
        printf("Word Completion Failed\n");
        return EXIT_FAILURE;
    }
    int length = strlen(prefix);
    TrieNode *tmp = root;

    for (int i = 0; i < length; i++)
    {
        int j = tolower(prefix[i]) - 'a';
        if (!tmp->children[j])
        {
            printf("No words found with this prefix\n");
            return EXIT_FAILURE;
        }
        tmp = tmp->children[j];
    }
    if(tmp->EndOfWord)
    {
        printf("%s\n", (char *)prefix);
        return EXIT_SUCCESS;
    }
    printWord(tmp, (char *)prefix);
    return EXIT_SUCCESS;
}