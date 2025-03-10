#include <stdio.h>
#include <string.h>

#define str_max_size 30

int main(void) {

    char email[str_max_size];
    char username[str_max_size];
    char domain[str_max_size];
    int i;
    int c = 0;

    memset(email, 0, str_max_size);
    memset(username, 0, str_max_size);
    memset(domain, 0, str_max_size);

    fgets(email, str_max_size, stdin);

    email[strlen(email) - 1] = '\0';

    for (i = 0; i < strlen(email); i++) {
        if (i == 0 && email[i] == ' ') {
            continue;
        }
        if (email[i] == '@') {
            i += 1;
            break;
        }
        username[c] = email[i];
        c += 1;
    }

    printf("Username: %s length: %d\n", username, strlen(username));

    c = 0;
    for (; i < strlen(email); i++) {
        if (i == strlen(email) - 1 && email[i] == ' ') {
            continue;
        }
        domain[c] = email[i];
        c += 1;
    }

    printf("Domain: %s length: %d \n", domain, strlen(domain));
    return 0;
}
