#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[] = "aAaBbZ";
    printf("Input: '%s'\n", input);
    printf("Length: %zu\n", strlen(input));
    
    int letterCounts[26] = {0};
    
    for (int i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        printf("Processing char[%d]: '%c'\n", i, currentChar);
        
        if (isalpha(currentChar)) {
            char upperChar = toupper(currentChar);
            int index = upperChar - 'A';
            letterCounts[index]++;
            printf("  -> Letter '%c' at index %d, count now %d\n", upperChar, index, letterCounts[index]);
        }
    }
    
    printf("Final counts:\n");
    for (int i = 0; i < 26; i++) {
        if (letterCounts[i] > 0) {
            printf("  %c: %d\n", 'A' + i, letterCounts[i]);
        }
    }
    
    printf("Output: ");
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