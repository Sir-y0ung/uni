#include <stdio.h>

#define SALESP 4
#define PRODUCTS 5

void calculateSales(int S, int P, int salesTable[S][P],int price[],int sp[]){
    int i,j;

    for (i = 0; i < S; i++){
        sp[i] = 0;
        for(j = 0; j < P; j++){
            sp[i]+= salesTable[i][j] * price[j];
        }
    }
}

void calculateProductSales(int S,int P,int sales[S][P], int prods[]){
    int i,j;

    for(i=0; i < P; i++){

        prods[i]=0;

        for(j=0; j < S;j++){

            prods[i] += sales[j][i];
        }
    }
}

void maxArray(int size,int table[],int* max,int* pos){
    int i;

    *max =table[0];
    *pos = 0;

    for(i = 1; i < size; i++){

        if (*max < table[i]) {
            *max=table[i];
            *pos=i;
        }
    }
}
void printArray(int table[],int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d %d \n", i , table[i]);

    }
}

int main(){
    int sales[SALESP][PRODUCTS] = {{10,4,5,6,7,},{7,0,12,1,3},{4,19,5 ,0,8}, {3,2,1,5,6}};
    int salesPerson[SALESP];
    int price[] = {250, 150, 320, 210 , 920};
    int productSale[PRODUCTS];
    int pos,max;

    calculateSales(SALESP,PRODUCTS,sales, price, salesPerson);
    calculateProductSales( SALESP, PRODUCTS, sales,productSale);
    maxArray(SALESP,salesPerson, &max, &pos);

    printf("Salesman-Sales\n");
    printArray(salesPerson,SALESP);

    printf("Best SalesMan was %d with %d sales\n",pos,max);
    printf("Product-Items\n");
    printArray(productSale,PRODUCTS);

    maxArray(PRODUCTS,productSale,&max,&pos);
    printf("Best Product was %d with %d items", pos, max);

    return 0;
}