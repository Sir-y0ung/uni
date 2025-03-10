#include <stdio.h>

#define tab1_rows 5
#define tab1_cols 7

#define tab2_rows 4
#define tab2_cols 5

void populate_array(int rows, int cols, int arr[rows][cols]) {
    int iterator, j_iterator;
    for (iterator = 0; iterator < rows; iterator++) {
        for (j_iterator = 0; j_iterator < cols; j_iterator++) {
            arr[iterator][j_iterator] = iterator * cols + j_iterator;
        }
    }
}

void print_part_of_array(int rows, int cols, int arr[rows][cols], int sub_rows, int sub_cols) {
    int i, j;
    for (i = 0; i < sub_rows; i++) {
        printf("row( %d ):: ", i);
        for (j = 0; j < sub_cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void sum_columns(int rows, int cols, int arr[rows][cols], int sub_rows, int sub_cols, int result[sub_cols]) {
    int i, j;

    for (j = 0; j < sub_cols; j++) {
        result[j] = 0;
    }

    for (i = 0; i < sub_rows; i++) {
        for (j = 0; j < sub_cols; j++) {
            result[j] += arr[i][j];
        }
    }
}

int main() {
    int rows, columns, tab1[tab1_rows][tab1_cols], tab2[tab2_rows][tab2_cols];
    int temp1[7] = {0}, temp2[5] = {0};

    printf("Give rows: ");
    scanf("%d", &rows);
    printf("Give columns: ");
    scanf("%d", &columns);


    populate_array(tab1_rows, tab1_cols, tab1);
    populate_array(tab2_rows, tab2_cols, tab2);


    print_part_of_array(tab1_rows, tab1_cols, tab1, tab1_rows, tab1_cols);
    printf("\n");
    print_part_of_array(tab2_rows, tab2_cols, tab2, tab2_rows, tab2_cols);
    printf("\n");


    print_part_of_array(tab1_rows, tab1_cols, tab1, rows, columns);
    printf("\n");
    sum_columns(tab1_rows, tab1_cols, tab1, rows, columns, temp1);
    printf("sum(tab1)= ");
    for (int i = 0; i < columns; i++) {
        printf("%d ", temp1[i]);
    }
    for (int k = 0; k < 7 - columns;k++) {
        printf("0 ");
    }
    printf("\n");
    printf("\n");


    print_part_of_array(tab2_rows, tab2_cols, tab2, rows, columns);
    printf("\n");
    sum_columns(tab2_rows, tab2_cols, tab2, rows, columns, temp2);
    printf("sum(tab2)= ");
    for (int i = 0; i < columns; i++)
    {
        printf("%d ", temp2[i]);
    }
    for (int k = 0; k < 5 - columns;k++)
        {
            printf("0 ");
        }
    printf("\n");

    return 0;
}