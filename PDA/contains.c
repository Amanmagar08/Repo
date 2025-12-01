#include <stdio.h>
#include <string.h>

#define MAX_STACK 100

int doSomething() {char string[100];
    printf("Enter the string over the language {0,1}: ");
    scanf("%99s", string);

    // Validate input
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != '0' && string[i] != '1') {
            printf("Rejected! String not over language {0,1}\n");
            return 1;
        }
    }

    char stack[MAX_STACK];
    int top = -1;  // stack empty

    printf("Start (empty stack)\n");

    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        char c = string[i];

        if (top == -1) {
            // stack empty, push input symbol
            stack[++top] = c;
        } else {
            if (stack[top] == c) {
                // same symbol at top, push again
                if (top == MAX_STACK - 1) {
                    printf("Stack overflow\nRejected\n");
                    return 1;
                }
                stack[++top] = c;
            } else {
                // opposite symbol at top, pop
                top--;
            }
        }

        // Print stack contents
        printf("Read '%c' -> Stack: ", c);
        if (top == -1) printf("empty");
        else {
            for (int j = 0; j <= top; j++) printf("%c", stack[j]);
        }
        printf("\n");
    }

    if (top == -1) {
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
