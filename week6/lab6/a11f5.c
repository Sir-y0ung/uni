#include<stdio.h>
#include<math.h>

int main() {
    double temp;
    double temperatures[10][3];
    double temperatures_average[10]; //
    double temperatures_divergence[10];
    double city_avg;
    double global_tmp_avg = 0.0;

    for (int i = 0; i < 10;i++) {
            for (int j = 0; j < 3;j++) {
                printf("Temp of City %d During %d 8-hour period:", i, j);
                scanf("%lf", &temp);
                temperatures[i][j] = temp;
            }
    }


    for (int i = 0;i < 10;i++) { //
        double sum1 = 0;
        for (int j =0;j < 3;j++) {
            sum1 += temperatures[i][j];
        }
        temperatures_average[i] = sum1;
    }

    for (int i =0;i< 10;i++) {  // compute global_tmp_avg
        global_tmp_avg += temperatures_average[i];
    }
    global_tmp_avg /= 30;

    for (int i =0;i < 10;i++) {
        double max1 = 0;
        for (int j =0;j < 3;j++) {
            if (fabs(temperatures[i][j] - global_tmp_avg) > (double) max1) {
                max1 = fabs(temperatures[i][j] - global_tmp_avg);
            }
        }
        temperatures_divergence[i] = max1;
    }

    printf("%.1f\n", global_tmp_avg); // print avg
    for (int i = 0;i<10;i++) {
        city_avg = temperatures_average[i] / 3;
        printf("City %d %.1lf %.1lf\n", i, city_avg, temperatures_divergence[i]);
    }


    return 0;
}