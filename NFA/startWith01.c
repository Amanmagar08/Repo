#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int doSomething() {
    char string[100];
    printf("Enter the string over the language {0,1}: ");
    scanf("%99s", string);

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != '0' && string[i] != '1') {
            printf("Rejected! String not over language {0,1}\n");
            return 1;
        }
    }

    bool currentStates[3] = {true, false, false};
    bool nextStates[3];
    char stateNames[3] = {'A', 'B', 'C'};

    printf("A");

    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        char c = string[i];
        for (int s = 0; s < 3; s++) {
            nextStates[s] = false;
        }

        for (int state = 0; state < 3; state++) {
            if (currentStates[state]) {
                switch(state) {
                    case 0:
                        if (c == '0') nextStates[1] = true;
                        break;
                    case 1:
                        if (c == '1') nextStates[2] = true;
                        break;
                    case 2:
                        if (c == '0' || c == '1') nextStates[2] = true;
                        break;
                }
            }
        }

        bool anyActive = false;
        for (int s = 0; s < 3; s++) {
            currentStates[s] = nextStates[s];
            if (nextStates[s]) anyActive = true;
        }

        printf(" -> ");
        if (!anyActive) {
            printf("(no next state)\nRejected\n");
            return 0;
        }

        bool first = true;
        for (int s = 0; s < 3; s++) {
            if (currentStates[s]) {
                if (!first) printf(",");
                printf("%c", stateNames[s]);
                first = false;
            }
        }
    }

    printf("\n");

    if (currentStates[2]) {
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
