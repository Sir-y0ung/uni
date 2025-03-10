#include <stdio.h>

int main() {
    long code;
    double salary;
    int working_hours;
    double salary_per_hour;
    double weekly_salary;

    printf("Dwse ton kwdiko: ");
    scanf("%ld",&code);

    if (code >= 1000) {
        printf("Dwse ton ethsio mistho:");
        scanf("%lf", &salary);

        weekly_salary = salary / 52; 
    }
    else {
        printf("Dwse tis wres ebdomadiaias ergasias:");
        scanf("%d", &working_hours);

        printf("Dwse thn amoibh ana wra:");
        scanf("%lf", &salary_per_hour);

        if (working_hours > 40) {
            weekly_salary =  (salary_per_hour * 40) + (working_hours - 40) * (salary_per_hour * 1.5);      
        }
        else {
            weekly_salary =working_hours * salary_per_hour;
        } 
    }

    printf("H ebdomadiaia amoibh einai %g", weekly_salary);


    return 0;
}