#include <stdio.h>
#include <string.h>

struct Company {
    char brand[20];
    int cubic;
    char rent_name[20];
    int rent_dates;
    int price_day;
};


void view_results(int rents, struct Company company[rents]) {

    float sum = 0;
    int index = -1;

    printf("Number      Name        Type        CC      Days     Price       Total\n");
    printf("-------------------------------------------------------------------------\n");


    for (int i = 0; i < rents; i++) {
        float price = (float)company[i].price_day * (float) company[i].rent_dates;
        printf("%d      %s      %s      %d      %d      %.2f    %.2f\n", i, company[i].rent_name, company[i].brand, company[i].cubic, company[i].rent_dates, (float) company[i].price_day, price);
        sum += price;
        if (index == -1) {
            index = i;
        }
        else {
            if (company[i].price_day < company[index].price_day && company[i].rent_dates > company[index].rent_dates) {
                index = i;
            }
        }
    }

    printf("-------------------------------------------------------------------------\n");
    printf("                                                            Total   %.2f\n", sum);

    printf("Best car: %s %d rented for %.2f Euros.", company[index].brand, company[index].cubic, (float)company[index].price_day * (float) company[index].rent_dates);
}



int main(void)  {
    int rents;
    char brand[20];
    int cubic;
    char rent_name[20];
    int rent_dates;
    int price_day;
    char clear;

    printf("Dose ton arithmo ton enoikiaseon: ");
    scanf("%d", &rents);

    struct Company company[rents];

    for (int i = 0 ; i< rents; i++) {

        printf("Dose ta stoixeia tis enoikiasis %d\n", i);

        printf("Dose marka: ");
        gets(&clear);
        fgets(brand,20 , stdin );
        brand[strlen(brand)-1] = '\0';

        printf("Dose kyvika: ");
        scanf("%d", &cubic);

        printf("Dose onoma pelati:");
        scanf("%s", &rent_name);

        printf("Dose imeres enoikiasis:");
        scanf("%d", &rent_dates);

        printf("Dose timi ana imera:");
        scanf("%d", &price_day);

        printf("\n");

        strcpy(company[i].brand, brand);
        company[i].cubic = cubic;
        strcpy(company[i].rent_name, rent_name);
        company[i].rent_dates = rent_dates;
        company[i].price_day = price_day;

    }

    view_results(rents, company);

    return 0;
}
