#include <stdio.h>
#include <math.h>

void print_array(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");
}


int main(void) {
    double aray_w_doubles[5];
    double aray_w_abs_values[4];

    for (int i = 0; i < 5; i++) {
        printf("Enter number:");
        scanf("%lf", &aray_w_doubles[i]);
    }

    for (int i = 0; i < 4; i++) {
        aray_w_abs_values[i] = fabs( aray_w_doubles[i] - aray_w_doubles[i+1]);
    }

    print_array(aray_w_doubles, 5);
    print_array(aray_w_abs_values, 4);

    return 0;
}
