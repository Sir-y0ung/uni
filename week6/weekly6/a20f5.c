#include <stdio.h>

int main(void) {
    int aray_w_int[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter number:");
        scanf("%d", &aray_w_int[i]);
    }

    int temp_last_item =  aray_w_int[4];
    for (int i =4; i > 0; i--) {
        aray_w_int[i] = aray_w_int[i-1];
    }
    aray_w_int[0] = temp_last_item;

    for (int i = 0; i < 5; i++) {
        printf("%d ", aray_w_int[i]);
    }

    return 0;
}
