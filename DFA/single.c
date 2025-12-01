#include <stdio.h>

int main() {
    printf("Aman Thapa Magar\n");
    int i = 0;
    char string[10];
    printf("Enter to check if the string is accepted as a single line comment in c: ");
    scanf("%9s", string);

    char currentState = 'A';
    i = 0;

    while (string[i] != '\0') {
        switch (currentState) {
            case 'A':
                if (string[i] == '/') currentState = 'B';
                else currentState = 'D';
                break;

            case 'B':
                if (string[i] == '/') currentState = 'C';
                else currentState = 'D';
                break;

            case 'C':
                printf("Accepted: Single line c comment\n");
                return 0;

            case 'D':
                printf("Rejected: Not a single line c comment\n");
                return 0;   
        }

        i++;
    }
}
