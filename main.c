
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "smartkeyboard.h"

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
                // if (!search(root, argv[3]))
                // {
                //     fprintf(stderr, "The word is in the dictionary\n");
                //     freeTst(root);
                //     return EXIT_SUCCESS;
                // }
                // else
                // {
                //     fprintf(stderr, "The word is not in the dictionary\n");
                //     freeTst(root);
                //     return EXIT_FAILURE;
                // }
                // printf("suggest\n");
            }
            else if (strcmp(argv[2], "complete") == 0)
            {
                completWord(root, argv[3]);
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