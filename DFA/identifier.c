#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of C keywords (minimal set for demo, you can expand it)
const char *keywords[] = {
    "int", "float", "char", "double", "if", "else", "while", "for",
    "do", "return", "switch", "case", "break", "continue", "void",
    "static", "struct", "sizeof", "long", "short", "unsigned", "signed",
    "typedef", "enum", "const", "volatile", "default", "goto", "auto",
    "register", "extern"
};
int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

// Check if string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// DFA to check if valid identifier
int isIdentifier(const char *str) {
    int i = 0;

    // State 0 -> Expect first char: letter or underscore
    if (isalpha(str[i]) || str[i] == '_') {
        i++;
        // State 1 -> Accept letters, digits, underscore
        while (str[i] != '\0') {
            if (isalnum(str[i]) || str[i] == '_') {
                i++;
            } else {
                return 0; // Invalid transition
            }
        }
        return 1; // Accept
    }
    return 0; // Reject
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("\"%s\" is a keyword.\n", input);
    } else if (isIdentifier(input)) {
        printf("\"%s\" is a valid identifier.\n", input);
    } else {
        printf("\"%s\" is not a valid identifier.\n", input);
    }

    printf("\n\n");

        printf("Enter a string: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("\"%s\" is a keyword.\n", input);
    } else if (isIdentifier(input)) {
        printf("\"%s\" is a valid identifier.\n", input);
    } else {
        printf("\"%s\" is not a valid identifier.\n", input);
    }

    return 0;
}
