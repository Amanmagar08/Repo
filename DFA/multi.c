#include <stdio.h>
#include <string.h>

int main() {
    printf("Aman Thapa Magar\n");
    char string[100];
    printf("Enter string to check if it's a C multi-line comment: ");
    if (!fgets(string, sizeof(string), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
        len--;
    }

    char currentState = 'A';
    int i = 0;

    while (string[i] != '\0') {
        char ch = string[i];

        switch (currentState) {
            case 'A':
                if (ch == '/') currentState = 'B';
                else currentState = 'F';
                break;

            case 'B':
                if (ch == '*') currentState = 'C';
                else currentState = 'F';
                break;

            case 'C':
                if (ch == '*') currentState = 'D';
                break;

            case 'D':
                if (ch == '/') currentState = 'E';
                else if (ch == '*') currentState = 'D';
                else currentState = 'C';
                break;

            case 'E':
                currentState = 'F';
                break;

            case 'F':
                printf("Rejected: Not a valid C multi-line comment\n");
                return 0;
        }

        i++;
    }
    if (currentState = 'E')
        printf("Accepted: Valid multi-line C comment\n");
    else
        printf("Rejected: Not a valid multi-line C comment\n");

    return 0;
}
