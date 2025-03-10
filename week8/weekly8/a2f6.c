#include <stdio.h>

int readData(int arr[100]) {
    unsigned int input;
    int i =0;

    printf("? ");
    scanf("%u", &input);
    while (input != -1) {
        arr[i] = input;
        printf("? ");
        scanf("%u", &input);
        i++;
    }

    return i;
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void findMinMax(int arr[100], int *min, int *max, int len) {
    int i, j;
    int swapped;

    for (i = 0; i < len - 1; i++) {
        swapped = 0;
        for (j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }

    *min = arr[0];
    *max = arr[len-1];
}

int main1() {
    unsigned int arr[100];
    int min;
    int max;

    printf("Enter the elements of the array, one per line.\n");
    printf("Use -1 to signal the end of the list.\n");

    int numbers_pl = readData(arr);
    findMinMax(arr, &min, &max, numbers_pl);
    printf("The range of values is %d-%d", min, max);

    return 0;
}