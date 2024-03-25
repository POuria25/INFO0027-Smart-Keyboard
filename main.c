#include "smartkeyboard.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <filename> <command>\n", argv[0]);
        return EXIT_FAILURE;
    }
    else
    {
        TrieNode *root = createNode();
        if (!root)
        {
            return EXIT_FAILURE;
        }
        if (!read_file(root, argv[1]))
        {
            if (strcmp(argv[2], "suggest") == 0)
            {
                if (suggestWords(root, argv[3]))
                {
                    freeTrie(root);
                    return EXIT_SUCCESS;
                }
                else
                {
                    freeTrie(root);
                    return EXIT_FAILURE;
                }
            }
            else if (strcmp(argv[2], "complete") == 0)
            {
                fprintf(stderr, "complete\n");
                if (completWord(root, argv[3]))
                {
                    freeTrie(root);
                    return EXIT_SUCCESS;
                }
                else
                {
                    freeTrie(root);
                    return EXIT_FAILURE;
                }
            }
            else
            {
                fprintf(stderr, "undefined command\n");
            }
        }
        else
        {   fprintf(stderr, "ok\n");
            freeTrie(root);
            return EXIT_FAILURE;
        }
    }
    return 0;
}