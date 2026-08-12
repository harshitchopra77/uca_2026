#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

const char table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

char* base64Encode(const char *input)
{
    int n = strlen(input);
    int outputLen = 4 * (ceil(n/3));
    char *output = malloc(outputLen + 1);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        int remaining = n - i;
        unsigned int b1 = input[i++];
        unsigned int b2 = (remaining > 1) ? input[i++] : 0;

        unsigned int b3 = (remaining > 2)? input[i++] : 0;

        unsigned int bits =(b1 << 16) |(b2 << 8) |b3;

        output[j++] = table[(bits >> 18) & 63];

        output[j++] = table[(bits >> 12) & 63];
        if (remaining > 1){
            output[j++] = table[(bits >> 6) & 63];
        }
        else{
            output[j++] = '=';
        }
        if (remaining > 2){
            output[j++] = table[bits & 63];
        }
        else{
            output[j++] = '=';
        }

    }

    output[j] = '\0';
    return output;
}

int main()
{
    char input[1000];
    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    char *result = base64Encode(input);
    printf("Encoded: %s\n", result);
    free(result);
}