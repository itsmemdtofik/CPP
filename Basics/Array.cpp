#include <iostream>
#include <string>
using namespace std;

int main()
{

    // Create an array of string
    string cars[5] = {
        "volvo", "BMW", "Ford", "Mazda", "Tesla"};

    // Loop through strings
    for (int i = 0; i < 5; i++)
    {
        cout << " Index " <<  i << " = " << cars[i] << "\n";
    }
    
    return 0;
}