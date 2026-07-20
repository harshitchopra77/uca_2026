#include <stdio.h>

void url_encode(char *str, int true_length) {
    int spaceCount = 0;
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ')
            spaceCount++;
    }
    int newLength = true_length + (spaceCount * 2);
    str[newLength] = '\0';
    int i = true_length - 1;
    int j = newLength - 1;

    while (i >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
        i--;
    }
}

int main() {
    char str[100] = "Hello World";
    int true_length = 11;
    url_encode(str, true_length);
    printf("%s\n", str);

    return 0;
}