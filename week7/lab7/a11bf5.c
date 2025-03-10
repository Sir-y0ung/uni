#include <stdio.h>
#include <math.h>

#define CTS 10
#define S 3

void ReadData(double temper[CTS][S]) {
    int i, j;

    for (i=0; i<CTS; i++) {
        for (j=0; j<S; j++) {
            printf("Temp of City %d During %d 8-hour period: ",i,j);
            scanf("%lf",&temper[i][j]);
        }
    }
}

double CalculateAvg(double temper[CTS][S]) {
    double natavg;
    int i, j;
    natavg = 0;
    for (i=0; i<CTS; i++)
        for (j=0; j<S; j+=1)
            natavg += temper[i][j];

    natavg = natavg/(CTS*S);
    return natavg;
}

void computeAverage(double average[CTS], double temper[CTS][S]) {
    int i, j;

    for (i=0; i<CTS; i++) {
        average[i] = 0;
        for (j=0; j<S; j++) {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/S;
    }
}

void devitation(double devnat[CTS][S], double temper[CTS][S], double natavg) {
    int i,j;

    for (i=0; i < CTS; i++)
        for (j=0; j<S; j++)
            devnat[i][j] = fabs(natavg-temper[i][j]);
}

void max_devitation(double devnat[CTS][S], double mdeviation[CTS]) {
    int i,j;

    for (i=0; i<CTS; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<S; j++)
            if (mdeviation[i] < devnat[i][j])
                mdeviation[i] = devnat[i][j];
    }
}

void print_arr(double natavg, double average[CTS], double mdeviation[CTS]) {
    int i;
    printf("%3.1f\n", natavg);
    for (i=0; i<CTS; i+=1)
        printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
}

int main()
{
    double devnat[CTS][S], temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;

    ReadData(temper); // Reading data

    /*Calculating The Average of all Cities&Temps*/
    natavg = CalculateAvg(temper);

    /*Calculating Average temp on each City*/
    computeAverage(average, temper);

    /*Calculating Standard Deviation*/

    devitation(devnat,temper,natavg);

    /*Calculating max Deviation*/
    max_devitation(devnat,mdeviation);

    /*Printing results*/
    print_arr(natavg,average,mdeviation);
    return 0;
}
