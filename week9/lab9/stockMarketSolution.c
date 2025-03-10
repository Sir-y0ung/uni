/* Stock Market Analysis
 */
 
#include <stdio.h>
float find_max(int size,float table[size]);
 
int find_inter_values(int size ,float table[size],float max,float interesting_tab[size]){
 
    int i;
 
    int ni_x=0;
    for(i=0;i<size;i++){
      if (table[i] > max / 2)
          {interesting_tab[ni_x++] = table[i];}
 
          }
 
    return ni_x;
 
}
void print_delimeter(int size, char *delimiter){
    int i = 0;
 
    for (i=0;i<size;i++) {
        printf("%s", delimiter);
    }
    printf("\n");
 
}

void print_tab_with_max(int size, float prices[],float max){
 
    int i;
 
    printf("Max Price:: %4.2f \n",max);
    for(i=0;i<10;i++)
      printf("%s(%3.2f) ",(max == prices[i] ? "-Max-" : ""),prices[i]);
    printf("\n");
 
 
 
}

float find_max(int size,float table[size]){
    int i;
    float max = table[0];
    for(i=1;i<size;i++)
        if (table[i] > max)
        {max = table[i];}
    return max;



}
float comp_value(int size,float cds[size],int risk[size],int i)
{
    if(cds[i]<20&&risk[i]<50)
        return 20;

    if(cds[i]>=20&&risk[i]<80)
        return  10 + (cds[i] * risk[i])/100;

    return 100 + (cds[i]*risk[i])/100;
}



void printCDS_assessment(float cds_prices[11],int risk[11])     {
    int i;
    for (i=0;i<11;i++)  {
        printf("CDS assessment: cds %2.2f Risk %2.2d Value %2.2f \n",cds_prices[i],risk[i], comp_value(11,cds_prices,risk,i));
    }
}

void high_low(float deriv_day_data[5][10], int *max, int *min, int index) {
    int j;
    float close_value = deriv_day_data[index][9];
    for (j =0; j < 9; j++) {
        if (deriv_day_data[index][j] > close_value) {
            (*max)++;
        }
        if (deriv_day_data[index][j] < close_value) {
            (*min)++;
        }
    }
}


int main(){
   float stock_prices[10] = {34.5, 22.4, 77.8, 22.1, 10.0, 11.25, 12, 13, 16, 20.5 };
   float deriv_prices[5] = {30.5, 21.4, 89.8, 20.1, 10.0};
   float cds_prices[11] = {38.5, 33.4, 67.8, 12.1, 16.0, 10.25, 11, 23, 36, 10.1 ,30.4};
   int risk[11] = {90,10,20,30,50,60,30,30,30,10,10};

   float deriv_day_data[5][10] = {
                {30.5,25,22,32.3,30.5,32.6,38.9,40,22,30.5},
                {22.5,21.4,14,40.3,22.5,12.6,38.9,40,39,21.4},
                {30.5,25,22,89.8,34.5,89.8,38.9,40,30,89.8},
                {20.2,35,20.1,12.3,20.1,32.6,38.9,40,22,20.1},
                {45.5,10.0,22,10.0,14.5,23.6,48.9,8,10.0,10.0}
   };


   float interesting_stock[10];
   int ni_stock;
   float interesting_cds[11];
   int ni_cds;


   int i;
   float max_stock, max_deriv, max_cds;

    /* Calculating Max Values */
    max_stock=find_max(10,stock_prices);
    max_deriv=find_max(5,deriv_prices);
    max_cds=find_max(5,cds_prices);

    /* Finding Interesting Values */
    ni_stock = find_inter_values(10,stock_prices,max_stock,interesting_stock);
    ni_cds  = find_inter_values(5,cds_prices,max_cds,interesting_cds);


   /* Printing */

    printf("Stock Prices.\n");

    print_delimeter(30, "-");

    print_tab_with_max(10,stock_prices,max_stock);


    printf("Interesting Stock Prices:");
    for(i=0;i<ni_stock;i++)
        printf("[%4.2f] ",interesting_stock[i]);

    printf("\n");

    print_delimeter(10, "-");

   /* Derivatives */
    printf("Derivative Prices.\n");

    print_delimeter(30, "-");

    print_tab_with_max(5,deriv_prices,max_deriv);

    print_delimeter(10, "-");

   /* Cds Prices */

     printf("CDS Prices.\n");

    print_delimeter(30, "-");

    print_tab_with_max(11,cds_prices,max_cds);



    printf("Interesting CDS Prices:");

    for(i=0;i<ni_cds;i++) printf("[%4.2f] ",interesting_cds[i]);
        printf("\n");

    print_delimeter(10, "-");

    printf("CDS assessment\n");
    printCDS_assessment(cds_prices,risk);
    print_delimeter(30, "-");


    printf("Derivative Low High \n");

    i = 0;
    int max;
    int min;

    for (;i< 5;i++) {
        max=0;
        min=0;
        high_low(deriv_day_data, &max, &min, i);
        printf("Devirative %d, high %d / low %d values.\n", i, max, min);
    }

    return 0;
}