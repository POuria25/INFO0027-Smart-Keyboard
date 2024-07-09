
/**
 * @file util.c
 * @brief Implementation file for the Util module.
 * @author KATOUZIAN Pouria ID: S-192865
 * @date 2024-07-09
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "util.h"

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

char *uppercase(char *str)
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
    fclose(file);
    return EXIT_SUCCESS;
}