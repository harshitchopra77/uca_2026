#include <stdio.h>

void reverse_string(char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    int i = 0, j = length - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    reverse_string(str);

    printf("Reversed string: %s\n", str);

    return 0;
}