#include <stdio.h>

int main() {
    printf("Aman Thapa Magar\n");
    int i = 0;
    char string[10];
    printf("Enter the string over the language 0, 1: ");
    scanf("%9s", string);
 
    while (string[i] != '\0') {
        if (string[i] != '0' && string[i] != '1') {
            printf("Rejected! String not over language 0, 1\n");
            return 1;
        }
        i++;
    }

    char currentState = 'A';
    i = 0;

    while (string[i] != '\0') {

        switch (currentState) {
            case 'A':
                if (string[i] == '0') currentState = 'B';
                break;

            case 'B':
                if (string[i] == '1') currentState = 'C';
                break;

            case 'C':
                if (string[i] == '0') currentState = 'B';
                else currentState = 'A';
                break;
        }

        i++;
    }

    if (currentState == 'C')
        printf("Accepted\n");
    else
        printf("Rejected: Does not end in 01\n");

    return 0;
}
