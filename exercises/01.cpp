#include <iostream>
using namespace std;

void convertToFahrenheit();
void convertToFeetInch();
void gauss();
void oddSum();
void findLargest();
void findSecondLargest();
void averageList();
void reverseInt();
bool factorHelp(int n);
void factor();
void hailstone();
void leibnizFormula();

const int SENTINEL = 0;
int main()
{
    /* code */
    leibnizFormula();
    return 0;
}

/*
 * 01
 * Write a program that reads in a temperature in degrees Celsius and displays the
 * corresponding temperature in degrees Fahrenheit. The conversion formula is
 * F = 9 / 5 * C + 32
 */
void convertToFahrenheit(){
    cout << "Celsius to fahrenheit" << endl;
    cout << " ? ";
    double celsius;
    cin >> celsius;
    double fahrenheit = 9.0 / 5.0 * celsius + 32;
    cout << fahrenheit;
}

/*
 * 02
 * Write a program that converts a distance in meters to the corresponding English
 * distance in feet and inches. The conversion factors you need are
 * 1 inch = 0.0254 meters
 * 1 foot = 12 inches
 */
void convertToFeetInch(){
    cout << "Convert a distance in meters to the corresponding English distance in feet and inches." << endl;
    cout << " ? ";
    double meters;
    cin >> meters;

    double inches = meters / 0.0254;
    int foot = int(inches) / 12;
    cout << foot << " feets " << inches - foot << " inches " << endl;
}

/*
 * 03
 * As mathematical historians have told the story, 
 * the German mathematician Carl Friedrich Gauss (1777-1855) 
 * began to show his mathematical talent at a very early age. 
 * When he was in elementary school, 
 * Gauss was asked by his teacher to compute the sum of the numbers between 1 and 100. 
 * Gauss is said to have given the answer instantly: 5050. 
 * Write a program that computes the answer to the question Gauss’s teacher posed.
 */ 
void gauss(){
    cout << "The sum of the numbers between 1 and 100." << endl;
    int number = 100;
    int result = (1 + number) * number / 2;
    cout << result;
}

/*
 * 04
 * Write a program that reads in a positive integer N and then calculates and displays the sum of the first N odd integers. 
 * For example, if N is 4, your program should display the value 16, which is 1 + 3 + 5 + 7.
 */
void oddSum(){
    cout << "Sum of the frist N odd integers" << endl;
    int number;
    cout << " ? ";
    cin >> number;
    cout << number * number;
}

/*
 * 05
 * Write a program that reads in a list of integers from the user until the user enters the value 0 as a sentinel. 
 * When the sentinel appears, your program should display the largest value in the list, as illustrated in the following sample run:
 */
void findLargest(){
    int largest = 0;
    cout << "This program finds the largest integer in a list." << endl;
    cout << "Enter 0 to signal the end of list." << endl;
    while(true){
        int number;
        cout << " ? ";
        cin >> number;
        if(number == SENTINEL) break;
        if(number > largest)  largest = number;
    }
    cout << "The largest value was " << largest << "." << endl;
}

/*
 * 06
 * For a slightly more interesting challenge, 
 * write a program that finds both the largest and the second-largest number in a list, 
 * prior to the entry of a sentinel. Once again using 0 as the sentinel, 
 * a sample run of this program might look like this:
 */
void findSecondLargest(){
    int largest = 0;
    int secondLargest = 0;
    cout << "This program find the largest integer and the second largest integer in a list." << endl;
    cout << "Enter 0 to signal the end of list." << endl;
    while(true){
        int number;
        cout << " ? ";
        cin >> number;
        if(number == SENTINEL) break;
        if(number > largest){
            secondLargest = largest;
            largest = number;
        }else if(number > secondLargest){
            secondLargest = number;
        }
    }
    cout << "The largest value was " << largest << "." << endl;
    cout << "The second largest value was " << secondLargest << "." << endl;
}

/*
 * 07
 * Using the AddIntegerList program from Figure 1-5 as a model, 
 * write a program AverageList that reads in a list of integers representing exam scores and then prints out the average. 
 * Because some unprepared student might actually get a score of 0, 
 * your program should use −1 as the sentinel to mark the end of the input.
 */
void averageList(){
    cout << "This program adds a list of numbers." << endl;
    cout << "Use " << SENTINEL << " to signal the end." << endl;
    int total = 0;
    int count = 0;
    while(true){
        int value;
        cout << " ? ";
        cin >> value;
        if(value == SENTINEL) break;
        total += value;
        count ++;
    }
    
    double average = double(total) / double(count);

    cout << "The avearga is " << average << endl;
}

/*
 * 08
 * Using the digitSum function from the section entitled “The while statement” as a model, 
 * write a program that reads in an integer and then displays the number that has the same digits in the reverse order, 
 * as illustrated by this sample run:
 */
void reverseInt(){
    int input;
    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> input;
    int reverse = 0;
    while(input > 0){
        int digit =  input % 10;
        reverse = reverse * 10 + digit;
        input /= 10;
    }
    cout << reverse << endl;
}

/*
 * 09
 * Every positive integer greater than 1 can be expressed as a product of prime numbers. 
 * This factorization is unique and is called the prime factorization. For example, 
 * the number 60 can be decomposed into the factors 2 x 2 x 3 x 5, 
 * each of which is prime. 
 * Note that the same prime can appear more than once in the factorization.
 */
void factor(){
    int input;
    cout << "This program factors a number." << endl;
    cout << "Enter number to be factored: ";
    cin >> input;
    int i = 2;
    while(true){
        if(i == input){
            cout << i << endl;
            break;
        }
        if(input % i == 0){
            input = input / i;
            if(factorHelp(i)){
            cout << i << " x ";
            }
        }else{
            i++;
        }
    }
}

/*
 * return true if N is prime number
 */
bool factorHelp(int n){
    int i = 2;
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

/*
 * 10
 * In 1979, Douglas Hofstadter, 
 * Professor of Cognitive Science at the University of Indiana, wrote Gödel, Escher, Bach, 
 * which he described as “a metaphorical fugue on minds and machines in the spirit of Lewis Carroll.” 
 * The book won the Pulitzer Prize for Literature and has over the years become one of the classics of computer science. 
 * Much of its charm comes from the mathematical oddities and puzzles it contains, 
 * many of which can be expressed in the form of computer programs. 
 * Of these, one of the most interesting concerns the sequence of numbers formed by repeatedly executing the following rules for some positive integer n:
 * • If n is equal to 1, you’ve reached the end of the sequence and can stop.
 * • If n is even, divide it by two.
 * • If n is odd, multiply it by three and add one.
 * Although it also goes by several other names, 
 * this sequence is often called the hailstone sequence because the values tend to go up and down before coming back to 1, much as hailstones do in the clouds in which they form.
 */
void hailstone(){
    int number;
    cout << "Enter a number: ";
    cin >> number;
    while(number != 1){
        
        if (number % 2 == 0) {
            cout << number << " is even, so I devided it by 2 to get " << number / 2 << endl;
            number /= 2;
        }
        else {
            cout << number << " is odd, so I multiply by 3 and add 1 to get " << number * 3 + 1 << endl;
            number *= 3;
            number++;
        }
        
    }
}

/*
 * 11
 * The German mathematician Leibniz (1646–1716) 
 * discovered the rather remarkable fact that the mathematical constant π can be computed using the following mathematical relationship:
 * The formula to the right of the equal sign represents an infinite series; 
 * each fraction represents a term in that series. 
 * If you start with 1, subtract one-third, add one-fifth, and so on, for each of the odd integers, you get a number that gets closer and closer to the value of π/4 as you go along.
 */
void leibnizFormula(){
    double num = 4.0;
    double den = 1.0;
    double result = 0.0;
    double symbol = 1.0;
    double term;
    
    
    for(int i = 0; i < 10000; i++)
    {
        term = num / den;
        term *= symbol;
        result += term;
        symbol = -symbol;
        den += 2.0;
    }
    cout << result << endl;
}