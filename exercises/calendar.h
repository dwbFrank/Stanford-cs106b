#ifndef _calendar_h
#define _calendar_h
#include <string>
enum Month{JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
int daysInMonth(int year, Month month);
bool isLeapYear(int year);
std::string monthToString(Month month);
#endif