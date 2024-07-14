
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
#include "utility.h"
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
        root = create_node('\0', NULL);
        if (!root)
        {
            return EXIT_FAILURE;
        }

        if (!read_file(root, argv[1]))
        {
            if (strcmp(argv[2], "suggest") == 0)
            {
                char *prefix = convert_to_lowercase(argv[3]);
                suggest(root, prefix);
                free(prefix);
            }
            else if (strcmp(argv[2], "complete") == 0)
            {
                char *prefix = convert_to_lowercase(argv[3]);
                complet_word(root, prefix);
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
            fprintf(stderr, "Unknown command: %s\n", argv[2]);
            free_tst(root);
            return EXIT_FAILURE;
        }
    }
    free_tst(root);

    return EXIT_SUCCESS;
}