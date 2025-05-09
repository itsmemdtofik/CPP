/**
 * !Named structure
 *
 * By giving a name to the structure, you can treat it as a data type.
 * This means that you can create variables with this structure anywhere in the
 * program at ay time.
 *
 * ? To create a named structure, put the name of the structure right after the strcut keyword.
 */
#include <iostream>
#include <string>
using namespace std;

struct car
{
    string brand;
    string model;
    int year;
};

int main()
{

    /**
     * !Named strcuture
     *
     * Note down that when using the named structure, you must declare the variable the uses the structure for example car.
     * Create a car structure and store it in car1 and car2.
     *
     */

    car car1;
    car1.brand = "BMW";
    car1.model = "X5";
    car1.year = 1999;

    car car2;
    car2.brand = "Ford";
    car2.model = "Mustag";
    car2.year = 1969;

    cout << car1.brand << " " << car1.model << " " << car1.year << "\n";
    cout << car2.brand << " " << car2.model << " " << car2.year << "\n";
}
