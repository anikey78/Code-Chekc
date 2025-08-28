#include <stdio.h>
#include <string.h>

int main() {
    char test[] = "hello\n";
    printf("Before strcspn: '%s' (len=%zu)\n", test, strlen(test));
    test[strcspn(test, "\n")] = '\0';
    printf("After strcspn: '%s' (len=%zu)\n", test, strlen(test));
    return 0;
}