#include <stdio.h>
#include <math.h>

int get_code(){
    int kwdikos;

    printf("Dwse ton kwdiko:");
    scanf("%d",&kwdikos);

    while (kwdikos > 2000 | kwdikos < 0){
        printf("Lathos kwdikos (0-2000)\n");

        printf("Dwse ton kwdiko:");
        scanf("%d",&kwdikos);
    }

    return kwdikos;
}

int discount_percentage(int kwdikos){
    int pososto;

    if (kwdikos<=300)
        pososto = 5;
    else if (kwdikos<=500)
        pososto = 10;
    else if (kwdikos<=1000)
        pososto = 15;
    else if (kwdikos<=2000)
        pososto = 20;

    return pososto;
}

int product_points(int kwdikos,long timh){
    int points = 1;

    if (kwdikos >= 1000 && kwdikos <= 1500) {
        points += ceil(timh / 5);
    }

    return points;

}

int main() {
    int kwdikos = 1;
    int pontoi, sum_points;

    double timh,sum_price,sum_discount,ekptwsh, pososto;

    while (kwdikos != 0) {

        kwdikos = get_code();
        if (kwdikos==0){
            break;
        }

        printf("Dwse timh:");
        scanf("%lf", &timh);

        pososto=discount_percentage(kwdikos);
        ekptwsh= timh * pososto / 100;

        timh = timh - ekptwsh;
        pontoi = product_points(kwdikos,timh);
        sum_price += timh;
        sum_points += pontoi;
        sum_discount += ekptwsh;
    }

    printf("------------------\n");
    printf("Teliko synolo %.2lf\n", sum_price);
    printf("Ekptwsh %.2lf\n", sum_discount);
    printf("Pontoi: %d", sum_points);

    return 0;
}