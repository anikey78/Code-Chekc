#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    printf("Enter input (type 'q' to quit): ");
    
    while (fgets(input, MAX_LENGTH, stdin) && input[0] != 'q') {
        printf("Raw input: '");
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '\n') {
                printf("\\n");
            } else {
                printf("%c", input[i]);
            }
        }
        printf("' (length: %zu)\n", strlen(input));
        
        // Remove newline
        input[strcspn(input, "\n")] = '\0';
        printf("After removing newline: '%s' (length: %zu)\n", input, strlen(input));
        
        // Process as usual
        int letterCounts[26] = {0};
        int inputLength = strlen(input);
        
        for (int i = 0; i < inputLength; i++) {
            char currentChar = input[i];
            if (isalpha(currentChar)) {
                char upperChar = toupper(currentChar);
                int index = upperChar - 'A';
                letterCounts[index]++;
            }
        }
        
        // Output
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
        printf("\n\n");
        
        printf("Enter input (type 'q' to quit): ");
    }
    
    return 0;
}