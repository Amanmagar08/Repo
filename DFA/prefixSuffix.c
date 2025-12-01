#include <stdio.h>

void prefix(char str[]) {
    int len = strlen(str);
    printf("\nPrefixes:\n");
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void suffix(char str[]) {
    int len = strlen(str);
    printf("\nSuffixes:\n");
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void substring(char str[]) {
    int len = strlen(str);
    printf("\nSubstrings:\n");
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            for (int k = i; k <= j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[20];

    printf("Aman thapa magar\n");
    printf("Enter a string: ");
    scanf("%s", str); 

    prefix(str);
    suffix(str);
    substring(str);

    return 0;
}