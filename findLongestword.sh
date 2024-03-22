#!/bin/bash

# Check if the file path is provided as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

# Initialize variables
longest_word=""
max_length=0

# Read each word from the file and process
while IFS= read -r word; do
    # Get the length of the current word
    word_length=${#word}
    # Check if the current word is longer than the longest word encountered so far
    if (( word_length > max_length )); then
        longest_word="$word"
        max_length=$word_length
    fi
done < "$1"

# Output the longest word
echo "Longest word in the file is: $longest_word"
