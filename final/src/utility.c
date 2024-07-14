
/**
 * @file utility.c
 * @brief Implementation file for the utility module.
 * @author KATOUZIAN Pouria ID: S-192865
 * @date 2024-07-09
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include "utility.h"

char *convert_to_lowercase(char *word)
{
    if (word == NULL)
    {
        return NULL;
    }
    size_t length = strlen(word);
    char *lowercaseWord = (char *)malloc(length + 1); 
    if (lowercaseWord == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (size_t i = 0; i < length; i++)
    {
        lowercaseWord[i] = tolower(word[i]); 
    }
    lowercaseWord[length] = '\0';

    return lowercaseWord;
}

char *convert_to_uppercase(char *str)
{
    if (str == NULL || strlen(str) == 0)
    {
        return str;
    }
    str[0] = toupper((unsigned char)str[0]);
    for (int i = 1; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            str[i + 1] = toupper((unsigned char)str[i + 1]);
        }
        else if (str[i] == '-')
        {
            str[i + 1] = toupper((unsigned char)str[i + 1]);
        }
    }
    return str;
}


char *check_word(char *word)
{
    if(word == NULL)
    {
        return NULL;
    }
    size_t len = strlen(word);
    (len > 0 && word[len - 1] == '\n') ? (word[len - 1] = '\0') : (word[len] = '\0');


    return word;
}

int has_additional_words(TstNode *node) {
    if (!node) return 0;
    if (node->isEndOfString) return 1;
    return has_additional_words(node->left) || has_additional_words(node->equal) || has_additional_words(node->right);
}

bool is_complete_word(TstNode *root, const char *prefix) {
    TstNode *node = root;
    while (*prefix && node) {
        if (*prefix < node->data) {
            node = node->left;
        } else if (*prefix > node->data) {
            node = node->right;
        } else {
            if (*(prefix + 1) == '\0') {
                return node->isEndOfString;
            }
            prefix++;
            node = node->equal;
        }
    }
    return false;
}


int read_file(TstNode *root, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Opening File Failed\n");
        return EXIT_FAILURE;
    }
    int i = 1;
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

        char *tmp = convert_to_lowercase(check_word(new));
        free(new);
        root = insert(root, tmp, NULL);
        //fprintf(stderr, "[%d] : read_file --- insert: %s\n", i,tmp);
        i++;
        free(tmp);
        if (!root)
        {
            fprintf(stderr, "insert: Failed to insert word\n");
            fclose(file);
            return EXIT_FAILURE;
        }
    }
    fclose(file);
    return EXIT_SUCCESS;
}
