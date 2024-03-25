#include "smartkeyboard.h"

// Create a new TrieNode
TrieNode *createNode()
{
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (!newNode)
    {
        fprintf(stderr, "Memory error\n");
        return NULL;
    }
    newNode->EndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void freeTrie(TrieNode *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != NULL)
        {
            freeTrie(root->children[i]);
        }
    }
    free(root);
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
    lowercaseWord[length] = '\0'; // Null-terminate the string

    return lowercaseWord;
}

// Insert a word into the Trie
int insert(TrieNode *root, char *word)
{
    // fprintf(stderr, "Word : [ %s ]\n", word);
    if (!root || !word)
    {
        fprintf(stderr, "insert : Invalid Input\n");
        return -1;
    }
    char *lowercaseWord = convertToLower(word);
    int length = strlen(lowercaseWord);
    TrieNode *tmp = root;
    for (int i = 0; i < length; i++)
    {
        // char c = tolower(word[i]);
        int j = char_to_index(lowercaseWord[i]);
        if (j < 0 || j >= ALPHABET_SIZE)
        {
            fprintf(stderr, "insert : Invalid character '%c'\n", word[i]);
            free(lowercaseWord);
            return -1;
        }
        // Check if the child node exists
        if (tmp->children[j] == NULL)
        {
            TrieNode *newNode = createNode();
            if (!newNode)
            {
                fprintf(stderr, "insert : Failed to create new node\n");
                free(lowercaseWord);
                return -1;
            }
            tmp->children[j] = newNode;
        }
        tmp = tmp->children[j];
    }
    tmp->EndOfWord = 1;
    free(lowercaseWord); // Free memory after use
    return EXIT_SUCCESS;
}

// // Read the file
int read_file(TrieNode *root, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Opening File Failed\n");
        return EXIT_FAILURE;
    }

    fprintf(stderr, "File Opened Successfully\n");

    char word[30000];
    while (fscanf(file, "%s", word) != EOF)
    {
        if (insert(root, word))
        {
            fprintf(stderr, "Word Insertion Failed\n");
            fclose(file);
            return EXIT_FAILURE;
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}

int printWordComplet(TrieNode *root, const char *prefix)
{
    if (!root || !prefix)
    {
        fprintf(stderr, "printWord : Invalid Inputs\n");
        return EXIT_FAILURE;
    }
    char fullWord[256];
    strcpy(fullWord, prefix);

    if (root->EndOfWord) // If node represents the end of a word, print it
    {
        fprintf(stderr, "%s\n", fullWord);
    }
    // printing the words from DS recursively
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        { // Appending characters
            fullWord[strlen(prefix)] = i + 'a';
            fullWord[strlen(prefix) + 1] = '\0';
            printWordComplet(root->children[i], (char *)fullWord);
        }
    }
    return EXIT_SUCCESS;
}

int completWord(TrieNode *root, const char *prefix)
{
    if (!root || !prefix)
    {
        fprintf(stderr, "completWord : Invalid Inputs\n");
        return EXIT_FAILURE;
    }
    TrieNode *tmp = root;

    for (int i = 0; prefix[i] != '\0'; i++)
    {
        int j = tolower(prefix[i]) - 'a';
        if (!tmp->children[j])
        {
            fprintf(stderr, "No words found with this prefix\n");
            return EXIT_FAILURE;
        }
        tmp = tmp->children[j];
    }
    // if(tmp->EndOfWord)
    // {
    //     fprintf(stderr,"%s\n", (char *)prefix);
    //     return EXIT_SUCCESS;
    // }
    printWordComplet(tmp, (char *)prefix);
    return EXIT_SUCCESS;
}

int printSuggestWords(TrieNode *root, const char *prefix)
{
    if (!root || !prefix)
    {
        fprintf(stderr, "suggestNextChar : Invalid Inputs\n");
        return EXIT_FAILURE;
    }

    int length = strlen(prefix);
    TrieNode *tmp = root;

    for (int i = 0; i < length; i++)
    {
        int j = tolower(prefix[i]) - 'a';
        if (!tmp->children[j])
        {
            fprintf(stderr, "suggestNextChar : No suggestions found\n");
            return EXIT_FAILURE;
        }
        tmp = tmp->children[j];
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (tmp->children[i])
        {
            fprintf(stderr, "%c\n", i + 'a'); // Print the suggested character
        }
    }

    return EXIT_SUCCESS;
}

// Suggest words based on the prefix
int suggestWords(TrieNode *root, const char *prefix)
{
    if (!root || !prefix)
    {
        fprintf(stderr, "Word Suggestion Failed\n");
        return EXIT_FAILURE;
    }
    int length = strlen(prefix);
    TrieNode *tmp = root;

    for (int i = 0; i < length; i++)
    {
        int j = char_to_index(tolower(prefix[i]));
        if (!tmp->children[j])
        {
            fprintf(stderr, "No words found with this prefix\n");
            return EXIT_FAILURE;
        }
        tmp = tmp->children[j];
    }
    printSuggestWords(tmp, (char *)prefix);
    return EXIT_SUCCESS;
}