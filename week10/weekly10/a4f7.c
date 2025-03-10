#include <stdio.h>
#include <string.h>

int main(void) {
    int number;
    int length;

    printf("Enter a number:");
    scanf("%d", &number);

    printf("Enter the desired length L:");
    scanf("%d", &length);

    char buffer[length];
    memset(buffer, 48, length);
    buffer[length] = '\x0';

    for (int i = length - 1; i >= 0; i--) {
        if (number > 0) {
            buffer[i] = (char) (number % 10 + '0');
            number /= 10;
        }
    }

    printf("Number: %s", buffer);

    return 0;
}
