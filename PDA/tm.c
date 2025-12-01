#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100

int doSomething() {
        char tape[MAX_LEN];
    printf("Enter the string over the language {0,1}: ");
    scanf("%99s", tape);

    int len = strlen(tape);

    // Validate input
    for (int i = 0; i < len; i++) {
        if (tape[i] != '0' && tape[i] != '1') {
            printf("Rejected! String not over language {0,1}\n");
            return 1;
        }
    }

    if (len < 2) {
        printf("Rejected\n");
        return 0;
    }

    int head = 0;
    char state = 'q'; // start state
    int count0 = 0, count1 = 0;

    while (state != 'h') {  // 'h' = halt
        switch(state) {
            case 'q':  // find leftmost unmarked '0'
                if (head >= len) {
                    state = 'r'; // no unmarked zero found, check tape
                } else if (tape[head] == '0') {
                    tape[head] = 'X'; // mark 0 as matched
                    state = 'r';
                    head++;
                } else if (tape[head] == 'X' || tape[head] == 'Y') {
                    head++;
                } else {
                    state = 'reject';
                }
                break;

            case 'r':  // move right to find unmarked '1'
                if (head >= len) {
                    state = 'reject';
                } else if (tape[head] == '1') {
                    tape[head] = 'Y'; // mark 1 as matched
                    state = 'l';
                    head--;
                } else {
                    head++;
                }
                break;

            case 'l':  // move left to beginning to find next zero
                if (head < 0) {
                    head = 0;
                    state = 'q';
                } else if (tape[head] == 'X' || tape[head] == 'Y') {
                    head--;
                } else if (tape[head] == '0' || tape[head] == '1') {
                    state = 'q';
                } else {
                    head--;
                }
                break;

            case 'reject':
                printf("Rejected\n");
                state = 'h';
                break;
        }

        if (state == 'r' && head >= len) {
            bool done = true;
            for (int i = 0; i < len; i++) {
                if (tape[i] == '0' || tape[i] == '1') {
                    done = false;
                    break;
                }
            }
            if (done) {
                printf("Accepted\n");
                state = 'h';
            } else {
                printf("Rejected\n");
                state = 'h';
            }
        }
    }
}

int main() {
    printf("Aman Thapa Magar\n");

    doSomething();
    printf("\n\n");
    doSomething();

    return 0;
}