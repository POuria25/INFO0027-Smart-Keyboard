
/**
 * @file main.c
 * @brief Main file for the Smart Keyboard module.
 * @author KATOUZIAN Pouria ID: S-192865 S-192865
 * @date 2024-07-09
 * This file contains the main function of the Smart Keyboard module.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "smartkeyboard.h"
#include "util.h"
#include "complete.h"
#include "suggest.h"



int main(int argc, char *argv[])
{
    TstNode *root;
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <filename> <command>\n", argv[0]);
        return EXIT_FAILURE;
    }
    else
    {
        root = createNode('\0'); 
        if (!root)
        {
            return EXIT_FAILURE;
        }

        if (!readfile(root, argv[1]))
        {
            if (strcmp(argv[2], "suggest") == 0)
            {
                char *prefix = convertToLower(argv[3]);
                suggestWord(root, prefix);
                free(prefix);
            }
            else if (strcmp(argv[2], "complete") == 0)
            {
                char *prefix = convertToLower(argv[3]);
                completWord(root, prefix);
                free(prefix);
            }
            else
            {
                fprintf(stderr, "You have to enter at least one character\n");
                return EXIT_FAILURE;
            }
        }
        else
        {
            freeTst(root);

            return EXIT_FAILURE;
        }
    }
    freeTst(root);

    return EXIT_SUCCESS;
}