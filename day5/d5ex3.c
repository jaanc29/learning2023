#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

typedef struct Time Time;

Time TimeDifference(Time time1, Time time2) {
    Time diff;

    int t1 = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
    int t2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;

    int diffSec=0;
    if(t1>t2){
        diffSec =t1-t2;
    }
    else{
        diffSec =t2-t1;
    }

    diff.hours = diffSec / 3600;
    diffSec %= 3600;
    diff.minutes = diffSec / 60;
    diff.seconds = diffSec % 60;

    return diff;
}

int main() {
    Time startingTime, endingTime, diffTime;

    printf("Enter start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &startingTime.hours, &startingTime.minutes, &startingTime.seconds);
    //input format 12:23:34;

    printf("Enter end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &endingTime.hours, &endingTime.minutes, &endingTime.seconds);
    //input format 12:23:34;

    diffTime = TimeDifference(startingTime, endingTime);

    printf("Time difference: %02d:%02d:%02d\n", diffTime.hours, diffTime.minutes, diffTime.seconds);

    return 0;
}