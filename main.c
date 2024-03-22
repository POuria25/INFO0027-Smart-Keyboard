#include "smartkeyboard.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <command>\n", argv[0]);
        return 1;
    }

    TrieNode *root = createNode();
    read_file(root, argv[1]);

    if (strcmp(argv[2], "suggest") == 0) {
        if (argc != 4) {
            printf("Usage: %s <filename> suggest <prefix>\n", argv[0]);
            return 1;
        }
        suggestWords(root, argv[3]);
    } else if (strcmp(argv[2], "complete") == 0) {
        if (argc != 4) {
            printf("Usage: %s <filename> complete <prefix>\n", argv[0]);
            return 1;
        }
        completWord(root, argv[3]);
    } else {
        printf("Invalid command. Use 'suggest' or 'complete'.\n");
        return 1;
    }

    return 0;
}