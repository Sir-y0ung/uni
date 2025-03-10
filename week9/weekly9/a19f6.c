#include <stdio.h>

void aver(int N, int arr[N], float *avg, int *diff) {
    int sum = 0;
    int min = arr[0];
    int max = arr[0];
    int i;

    for (i = 0; i < N; i++) {
        sum = sum + arr[i];

        if (min > arr[i]) {
            min = arr[i];
        }
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    *avg = (float) sum / (float) N;

    *diff = max - min;
}

void max_subt_average(int size, int table[size], int N, float *max_average, int *range, int *pos) {

    int sub_table[N];
    float avg;
    int diff;
    *max_average = -1;
    int i;
    int j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < N; j++) {
            sub_table[j] = table[i+j];
        }
        aver(N, sub_table, &avg, &diff);
        if (avg > *max_average) {
            *max_average = avg;
            *pos = i;
            *range = diff;
        }
    }
}

int main() {
    int table[10] = {20,30,40,70,30,50,20,50,30,20};

    int N;
    float max_average = -1;
    int range;
    int pos;

    printf("insert N:");
    scanf("%d", &N);

    max_subt_average(10, table, N, &max_average, &range, &pos);

    printf("N=%d max_average=%.2f range=%d pos=%d", N, max_average, range, pos);
    return 0;
}
