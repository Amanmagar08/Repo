#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK 100

int doSomething() {
        char string[100];
    printf("Enter the string over the language {0,1}: ");
    scanf("%99s", string);

    // Validate input
    int zeroCount = 0, oneCount = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != '0' && string[i] != '1') {
            printf("Rejected! String not over language {0,1}\n");
            return 1;
        }
    }

    char stack[MAX_STACK];
    int top = -1;
    bool readingZeros = true;

    printf("Start (empty stack)\n");

    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        char c = string[i];

        if (readingZeros) {
            if (c == '0') {
                if (top == MAX_STACK - 1) {
                    printf("Stack overflow\nRejected\n");
                    return 1;
                }
                stack[++top] = '0';
                zeroCount++;
            } else if (c == '1') {
                readingZeros = false;
                oneCount++;
                if (top == -1) {
                    // More 1s than 0s at this point
                    printf("Rejected\n");
                    return 0;
                }
                top--; // pop for 1
            } else {
                // Invalid char, handled earlier
            }
        } else {
            // Already reading 1's; no more zeros allowed
            if (c == '1') {
                oneCount++;
                if (top == -1) {
                    printf("Rejected\n");
                    return 0;
                }
                top--; // pop for 1
            } else {
                // '0' after '1' not allowed for this language
                printf("Rejected\n");
                return 0;
            }
        }

        // Print stack after each input
        printf("Read '%c' -> Stack: ", c);
        if (top == -1) {
            printf("empty");
        } else {
            for (int j = 0; j <= top; j++) {
                printf("%c", stack[j]);
            }
        }
        printf("\n");
    }

    // Accept if stack empty and zeroCount == oneCount and n > 1
    if (top == -1 && zeroCount == oneCount && zeroCount > 1) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
}
int main() {
    printf("Aman Thapa Magar\n");

    doSomething();
    printf("\n\n");
    doSomething();

    return 0;
}
