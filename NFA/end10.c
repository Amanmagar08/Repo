#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int doSomething() {
        char string[100];
    printf("Enter the string over the language {0,1}: ");
    scanf("%99s", string);

    // Validate input alphabet
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != '0' && string[i] != '1') {
            printf("Rejected! String not over language {0,1}\n");
            return 1;
        }
    }

    bool currentStates[3] = {true, false, false}; // A active initially
    bool nextStates[3];
    char stateNames[3] = {'A', 'B', 'C'};

    // Print initial states
    printf("A");

    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        char c = string[i];
        for (int s = 0; s < 3; s++) {
            nextStates[s] = false;
        }

        // NFA transitions
        for (int state = 0; state < 3; state++) {
            if (currentStates[state]) {
                switch(state) {
                    case 0: // A
                        if (c == '1') {nextStates[1] = true; nextStates[0] = true;} // A -> B on '1'
                        else if (c == '0') nextStates[0] = true; // A -> A on '0'
                        break;
                    case 1: // B
                        if (c == '0') nextStates[2] = true; // B -> C on '0'
                        break;
                    case 2: // C
                        if (c == '0') nextStates[0] = true; // B -> C on '0'
                        else if (c == '1') nextStates[1] = true; // B -> B on '1'
                        break;
                }
            }
        }

        // Update current states
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

        // Print active states
        bool first = true;
        printf("(");
        for (int s = 0; s < 3; s++) {
            if (currentStates[s]) {
                if (!first) printf(",");
                printf("%c", stateNames[s]);
                first = false;
            }
        }
        printf(")");
    }

    printf("\n");

    // Accept if final states include C
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
