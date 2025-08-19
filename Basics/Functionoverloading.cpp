/**
 * ! Function overloading in C++
 *
 * Function overloading means you can create multiple function with the same name but different parameter.
 * Or With function overloading, mutiple functions can the same name with different parameter
 * but with different parameters (type or number)
 * The compiler automatically decides which function to call based on the arguments.
 *
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * Consider the following example, which have two functions that add numbers of different types.
 */

int addInt(int x, int y)
{
    return (x + y);
}

double addDouble(double x, double y)
{
    return (x + y);
}

/**
 * Instead fof defining two functions that should do the same thing, it is better to overload one.
 * In the example below, we overload the plusFunc functions to work for both int and double.
 */

int plusFunc(int x, int y)
{
    return (x + y);
}

double plusFunc(double x, double y)
{
    return (x + y);
}
// Overload 1: add two integers
int add(int a, int b)
{
    return a + b;
}

// Overload 2: add two floats
float add(float a, float b)
{
    return a + b;
}

// Overload 3: add three integers
int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    int num1 = plusFunc(8, 5);
    double num2 = plusFunc(4.3, 6.26);

    cout << "Integer addition is: " << num1 << "\n";
    cout << "Double addition is: " << num2 << "\n";

    return 0;
}