#include <stdio.h>
#include <string.h>

int main(void) {

    FILE *in = fopen("i10f9.dat", "r");
    FILE *out = fopen("o10f9.dat", "w");

    if (in == NULL) {
        perror("File not found");
        return 1;
    }

    int size = 296;
    char buffer[size];
    memset(buffer, '\0', size);
    char ch;
    int index = 0;

    while ((ch = getc(in)) != EOF) {
        buffer[index] = ch;

        if (ch == ',' || ch == '.') {
            if ((ch = getc(in)) != EOF) {
                if (ch != ' ' && ch != EOF) {
                    buffer[++index] = ' ';
                }
                buffer[++index] = ch;
            }
        }
        index++;
    }

    fwrite(buffer, sizeof(char), sizeof(buffer) - 1, out);
    fclose(in);
    fclose(out);

    return 0;
}
