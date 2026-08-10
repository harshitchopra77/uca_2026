#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in = fopen("test_prg.c", "r");
    FILE *out = fopen("temp.c", "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int ch, next, prev;

    while ((ch = fgetc(in)) != EOF) {
        if (ch == '"') {
            fputc(ch, out);
            while ((ch = fgetc(in)) != EOF) {
                fputc(ch, out);

                if (ch == '\\') {
                    ch = fgetc(in);
                    if (ch != EOF)
                        fputc(ch, out);
                }
                else if (ch == '"')
                    break;
            }
        }
        else if (ch == '\'') {
            fputc(ch, out);

            while ((ch = fgetc(in)) != EOF) {
                fputc(ch, out);
                if (ch == '\\') {
                    ch = fgetc(in);
                    if (ch != EOF)
                        fputc(ch, out);
                }
                else if (ch == '\'')
                    break;
            }
        }
        else if (ch == '/') {
            next = fgetc(in);
            if (next == '/') {
                while ((ch = fgetc(in)) != EOF && ch != '\n'){
                    if (ch == '\n'){
                        fputc('\n', out);
                    }
                }
            }

            else if (next == '*') {
                prev = 0;

                while ((ch = fgetc(in)) != EOF) {
                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }

            else {
                fputc('/', out);

                if (next != EOF)
                    ungetc(next, in);
            }
        }
        else {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);


    printf("Comments removed successfully.\n");

    return 0;
}

// T_T