#include <stdio.h>

void GetTime(long SysSecs, int *hours,int *minutes,int *seconds);

int main(void) {
    long passed_seconds;

    int hours;
    int minutes;
    int seconds;

    printf("Enter Device Secs: ");
    scanf("%ld",&passed_seconds);

    GetTime(passed_seconds, &hours, &minutes, &seconds);
    printf("Time is %.2d:%.2d:%.2d", hours, minutes, seconds);
    return 0;
}

void GetTime(long SysSecs, int *hours,int *minutes,int *seconds) {
    int mins = SysSecs / 60;
    int secs = SysSecs % 60;
    int hrs = mins / 60;

    *hours =   (hrs + 12) % 12;
    *minutes = mins - hrs * 60;
    *seconds = secs;
}
