#include <string>
#include "calendar.h"
int daysInMonth(int year, Month month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
        int days;
        return isLeapYear(year) ? 29 : 28;
    default:
        return 30;
    }
}

bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string monthToString(Month month)
{

    switch (month)
    {
    case 1:
        return "JANUARY";
    case 2:
        return "FEBRUARY";
    case 3:
        return "MARCH";
    case 4:
        return "APRIL";
    case 5:
        return "MAY";
    case 6:
        return "JUNE";
    case 7:
        return "JULY";
    case 8:
        return "AUGUST";
    case 9:
        return "SEPTEMBER";
    case 10:
        return "OCTOBER";
    case 11:
        return "NOVEMBER";
    case 12:
        return "DECEMBER";
    default:
        break;
    }
}