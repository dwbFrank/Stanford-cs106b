#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "error.h"
#include "combinatorics.h"
#include "calendar.h"

using namespace std;

double convertToFahrenheit(double celsius);
void convertToFeetInch(double meter, int &feet, double &inche);
int roundToNearestInt(double x);
int windChill(double v, double t);
void windChill();
void error(string msg);
bool isPerfect(int n);
bool isPrime(int n);
double squareRoot(double x);
void findEaster(int year, string &month, int &day);
void testCalendar();
double randomAverage(int count);
// int permutations(int n, int k);

int main()
{
    int count;
    cin >> count;
    cout << randomAverage(count) << endl;
    return 0;
}

/* 
 * 01
 * If you did not do so the first time around, 
 * rewrite the Celsius-to-Fahrenheit program from exercise 1 in Chapter 1 so that it uses a function to perform the conversion.
 */
double convertToFahrenheit(double celsius)
{
    return 9.0 / 5.0 * celsius + 32.0;
}

/*
 *
 * 02
 * Reimplement the distance-conversion program from exercise 2 in Chapter 1 so that it uses a function. 
 * In this case, the function must produce both the number of feet and the number of inches, 
 * which means that you need to use call by reference to return these values.
 */
void convertToFeetInch(double meter, int &feet, double &inche)
{
    inche = meter / 0.0254;
    feet = int(inche) / 12;
    inche = inche - double(feet) * 12;
}

/*
 * 03
 * When a floating-point number is converted to an integer in C++, 
 * the value is truncated by throwing away any fraction. 
 * Thus, when 4.99999 is converted to an integer, the result is 4. 
 * In many cases, it would be useful to have the option of rounding a floating-point value to the nearest integer. 
 * Given a positive floating-point number x, 
 * you can round it to the closest integer by adding 0.5 and then truncating the result to an integer. 
 * Because truncation always moves toward zero, 
 * rounding negative numbers requires you to subtract 0.5, 
 * rather than adding it.
 * Write a function roundToNearestInt(x) that rounds the floating-point number x to the nearest integer. 
 * Show that your function works by writing a suitable main program to test it.
 */
int roundToNearestInt(double x)
{
    return int(x + 0.5);
}

/* 
 * 04
 * If you are unfortunate enough to be outside in winter weather, 
 * you know that your perception of the cold is dependent on the wind speed as well as the temperature. 
 * The faster the wind blows, the colder you feel. 
 * To quantify the how wind affects temperature perception, 
 * the National Weather Service reports the wind chill, 
 * which is illustrated on their website as shown in Figure 2-15. 
 * At the bottom of the figure, 
 * you can see that the formula for wind chill is 
 * 35.74 + 0.6215 t – 35.75 v 0.16 + 0.4275 t v 0.16
 * where t is the Fahrenheit temperature and v is the wind speed in miles per hour.
 * Write a function windChill that takes the values of t and v and returns the wind chill. 
 * In doing so, your function should take account of two special cases:
 * If there is no wind, windChill should return the original temperature t.
 * If the temperature is greater than 40° F, the wind chill is undefined, 
 * and your function should call error with an appropriate message.
 * Although it will be easier to do so once you learn how to format numeric data in Chapter 4, 
 * you already know enough to generate a table that presents the wind-chill data in columns as shown in Figure 2-15. 
 * If you’re up for more of a challenge, 
 * write a main program that uses windChill to produce that table.
 */
int windChill(int v, int t)
{

    if (v == 0)
    {
        return roundToNearestInt(t);
    }
    else if (t > 40)
    {
        string msg = "Temperature is greater than 40° F, the wind chill is undefined.";
        error(msg);
    }

    double windChill = 35.74 + 0.6215 * t - 35.75 * (pow(v, 0.16)) + 0.4275 * t * (pow(v, 0.16));
    return roundToNearestInt(windChill);
}

// void error(string msg)
// {
//     cerr << msg << endl;
//     exit(EXIT_FAILURE);
// }
/*
 * pirnt +40 ~ -45 F with 5 ~ 60 mph wind Chill in a table.
 */
void windChill()
{
    static const int upperTemp = 40;
    static const int lowerTemp = -45;
    static const int upperMph = 60;
    static const int lowerMph = 5;
    cout << "Calm \t";
    for (int j = upperTemp; j >= lowerTemp; j -= 5)
    {
        cout << j << '\t';
    }
    cout << endl;

    for (int i = lowerMph; i <= upperMph; i += 5)
    {
        cout << i << '\t';

        for (int j = upperTemp; j >= lowerTemp; j -= 5)
        {
            cout << windChill(i, j) << '\t';
        }
        cout << endl;
    }
}

/* 
 * 05
 * Greek mathematicians took a special interest in numbers that are equal to the sum of their proper divisors 
 * (a proper divisor of n is any divisor less than n itself). They called such numbers perfect numbers. 
 * For example, 6 is a perfect number because it is the sum of 1, 2, and 3, 
 * which are the integers less than 6 that divide evenly into 6. Similarly, 
 * 28 is a perfect number because it is the sum of 1, 2, 4, 7, and 14.
 * Write a predicate function isPerfect that takes an integer n and returns true if n is perfect, and false otherwise. 
 * Test your implementation by writing a main program that uses the isPerfect function to check for 
 * perfect numbers in the range 1 to 9999 by testing each number in turn. 
 * When a perfect number is found, 
 * your program should display it on the screen. The first two lines of output should be 6 and 28. 
 * Your program should find two other perfect numbers in the range as well.
 */
bool isPerfect(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return sum == n;
}

/*
 * 06
 * An integer greater than 1 is said to be prime if it has no divisors other than itself and one. 
 * The number 17, for example, is prime, because there are no numbers other than 1 and 17 that divide evenly into it. 
 * The number 91, however, is not prime because it is divisible by 7 and 13. 
 * Write a predicate method isPrime(n) that returns true if the integer n is prime, 
 * and false otherwise. To test your algorithm, write a main program that lists the prime numbers between 1 and 100.
 */
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

/*
 * 07
 * Even though clients of the <cmath> library typically don’t need to understand how functions like sqrt work internally, 
 * the implementers of that library have to be able to design an effective algorithm and write the necessary code. 
 * If you were asked to implement the sqrt function without using the library version, 
 * there are many strategies you could adopt. 
 * One of the easiest strategies to understand is successive approximation in which you make a guess 
 * at the solution and then refine that guess by choosing new values that move closer to the solution.
 */
double squareRoot(double x)
{
    double guess = x / 2.0;
    while (true)
    {
        double newGuess = (guess + x / guess) / 2;

        if (guess == x / newGuess || guess == newGuess)
        {
            return guess;
        }
        guess = newGuess;
    }
}

void findEaster(int year, string &month, int &day)
{

    int m, n;
    int a, b, c, d, e;

    if (year >= 1583 && year <= 1699)
    {
        m = 22;
        n = 2;
    }
    else if (year >= 1700 && year <= 1799)
    {
        m = 23;
        n = 3;
    }
    else if (year >= 1800 && year <= 1899)
    {
        m = 23;
        n = 4;
    }
    else if (year >= 1900 && year <= 2099)
    {
        m = 24;
        n = 5;
    }
    else if (year >= 2100 && year <= 2199)
    {
        m = 24;
        n = 6;
    }
    else if (year >= 2200 && year <= 2299)
    {
        m = 25;
        n = 0;
    }
    else
    {
        string msg = "Undefined year";
        error(msg);
    }

    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (19 * a + m) % 30;
    e = (2 * b + 4 * c + 6 * d + n) % 7;
    if (d + e < 10)
    {
        month = "March";
        day = d + e + 22;
    }
    else
    {
        int date = d + e - 9;
        month = "April";
        if (date == 26)
        {
            day = 19;
        }
        else if (date == 25 && d == 28 && e == 6 && a > 10)
        {
            day = 18;
        }
        else
        {
            day = date;
        }
    }
}

// int permutations(int n, int k)
// {
//     int result = 1;
//     for (int i = 0; i < k; i++)
//     {
//         result *= (n - i);
//     }

//     return result;
// }

// 11
void testCalendar()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;
    for (int i = 1; i < 13; i++)
    {
        Month month = Month(i);
        cout << monthToString(month) << " has " << daysInMonth(year, month) << " days." << endl;
    }
}

// 12
double randomAverage(int count)
{
    double sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        sum += rand() / (double(RAND_MAX) + 1);
    }
    return sum / count;
}