#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[] = "aAaBbZ";
    printf("=== DEBUGGING INPUT: '%s' ===\n", input);
    printf("Input length: %zu\n", strlen(input));
    
    // Show each character
    for (int i = 0; i < strlen(input); i++) {
        printf("input[%d] = '%c' (ASCII: %d)\n", i, input[i], (int)input[i]);
    }
    
    // Array to store the count of each letter (A-Z)
    int letterCounts[26] = {0};
    
    // Process each character
    printf("\n=== PROCESSING ===\n");
    int inputLength = strlen(input);
    for (int i = 0; i < inputLength; i++) {
        char currentChar = input[i];
        printf("Processing char[%d]: '%c'\n", i, currentChar);
        
        if (isalpha(currentChar)) {
            char upperChar = toupper(currentChar);
            int index = upperChar - 'A';
            letterCounts[index]++;
            printf("  -> Letter '%c' -> index %d -> count now %d\n", upperChar, index, letterCounts[index]);
        } else {
            printf("  -> Not a letter, skipping\n");
        }
    }
    
    // Show final counts
    printf("\n=== FINAL COUNTS ===\n");
    for (int i = 0; i < 26; i++) {
        if (letterCounts[i] > 0) {
            printf("%c: %d\n", 'A' + i, letterCounts[i]);
        }
    }
    
    // Generate output exactly as the main program does
    printf("\n=== OUTPUT ===\n");
    int isFirstOutput = 1; 
    for (int i = 0; i < 26; i++) {
        if (letterCounts[i] > 0) {
            if (!isFirstOutput) {
                printf(" ");
            }
            char letter = 'A' + i;
            printf("%c%d", letter, letterCounts[i]);
            isFirstOutput = 0;
        }
    }
    printf("\n");
    
    return 0;
}