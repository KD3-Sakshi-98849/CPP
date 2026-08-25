#include <stdio.h>
struct Date
{
    int day;
    int month;
    int year;
};
void initDate(struct Date *ptrDate)
{
    ptrDate->day = 0;
    ptrDate->month = 0;
    ptrDate->year = 0;
}
void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter Day:");
    scanf("%d", &ptrDate->day);

    printf("Enter Month:");
    scanf("%d", &ptrDate->month);

    printf("Enter year");
    scanf("%d", &ptrDate->year);
}
void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date:%d%d%d\n",
           ptrDate->day,
           ptrDate->month,
           ptrDate->year);
}
int menulist()
{
    int choice;
    printf("\n0.Exit\n");
    printf("1.Init Date\n");
    printf("2.Accept Date\n");
    printf("3.Print Date\n");

    printf("Enter choice");
    scanf("%d", &choice);

    return choice;
}
int main()
{
    struct Date d;
    int choice;
    while ((choice = menulist()) != 0)
    {
        switch (choice)
        {
        case 1:
            initDate(&d);
            printf("Data initialized\n");
            break;

        case 2:
            acceptDateFromConsole(&d);
            break;

        case 3:
            printDateOnConsole(&d);
            break;

        default:
            printf("invalid choice!\n");
        }
    }
    return 0;
}