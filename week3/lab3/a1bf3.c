#include<stdio.h>
#include<math.h>
 
 
int main() {
    long Arithmo_Aytok;
    double rate;
    long orio;
    int years = 0;


    printf("Dwse ton arxiko arithmo autokinhtwn:");
    scanf("%ld",&Arithmo_Aytok);
    printf("Dwse ton ethsio rythmo ayxhshs:");
    scanf("%lf",&rate);
    printf("Dwse to orio:");
    scanf("%ld",&orio);



    while (Arithmo_Aytok <= orio) {
        Arithmo_Aytok = ceil(Arithmo_Aytok * (1.0  + rate));
        ++years;
    }

    printf("%d\n", years);
    printf("%ld\n", Arithmo_Aytok);
 
    return 0;
}