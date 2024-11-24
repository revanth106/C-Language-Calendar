#include <stdio.h>


int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return (year % 400 == 0); 
        }
        return 1; 
    }
    return 0; 
}


int getStartingDay(int year) {


    int century = year / 100;
    int yearOfCentury = year % 100;

    
    int dayOfWeek = (1 + (13 * (1 + 1)) / 5 + yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century) % 7;
    return dayOfWeek;
}


void printMonth(int month, int year, int startDay, int daysInMonth) {
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    
    printf("\n   %s %d\n", months[month - 1], year);
    printf(" Su Mo Tu We Th Fr Sa\n");

    
    for (int i = 0; i < startDay; i++)
    {
        printf("   ");
    }

    
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        startDay++;
        if (startDay > 6) { 
            startDay = 0;
            printf("\n");
        }
    }
    printf("\n");
}


void printCalendar(int year) {
    int startDay = getStartingDay(year);
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    
    if (isLeapYear(year)) {
        daysInMonths[1] = 29;
    }

    
    for (int month = 1; month <= 12; month++) {
        printMonth(month, year, startDay, daysInMonths[month - 1]);
        startDay = (startDay + daysInMonths[month - 1]) % 7;
    }
}

int main() {
    int year;

    
    printf("Enter a year: ");
    scanf("%d", &year);

    
    if (isLeapYear(year)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    
    printCalendar(year);
    return 0;
}
