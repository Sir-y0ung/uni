#include <stdio.h>
#include <stdlib.h>

struct EventT {
    unsigned int day;
    unsigned int month;
    unsigned int year;
    char description[10];

};

struct EventT * read_event_data() {
    struct EventT *event = malloc(sizeof(struct EventT));

    printf("on day: ");
    scanf("%d", &(event->day));
    printf("Month: ");
    scanf("%d", &event->month);
    printf("Year: ");
    scanf("%d", &event->year);
    printf("EventName: ");
    scanf("%10s", &event->description);

    return event;
}

void print_event(struct EventT *event) {
    printf("(%02d/%02d/%04d) :: %s \n", event->day, event->month, event->year, event->description);
}


int cmp_events(struct EventT *event1, struct EventT *event2) {
    char full_day1[9];
    char full_day2[9];

    sprintf(full_day1, "%04d%02d%02d",event1->year, event1->month, event1->day);
    sprintf(full_day2, "%04d%02d%02d",event2->year, event2->month, event2->day);

    if (atoi(full_day1) < atoi(full_day2))
        return -1;
    if (atoi(full_day1) > atoi(full_day2))
        return 1;

    return 0;
}

int main() {
    struct EventT *event1;
    struct EventT *event2;

    event1 = read_event_data();
    event2 = read_event_data();

    printf("-----\n");
    print_event(event1);
    print_event(event2);
    printf("-----\n");

    if (cmp_events(event1, event2) == -1) {
        printf("Event %s is before event %s", event1->description, event2->description);
    }
    else if (cmp_events(event1, event2) == 1) {
        printf("Event %s is after event %s", event1->description, event2->description);
    }
    else {
        printf("Event %s is at the same day as event %s", event1->description, event2->description);
    }

    return 0;
}
