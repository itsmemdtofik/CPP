/**
 * ! Structure in C++
 *
 * Structures (also called structs) are a way to group several related variables into one place.
 * Each variable in the structure is known as a member of the structure.
 * Unlike an array, a structure can contain many different data types (int, string, bool, etc.).
 * To create a structure, use the struct keyword and declare each of its members inside curly braces.
 * After the declaration, specify the name of the structure variable (myStructure in the example below):
 */

#include <iostream>
#include <string>
using namespace std;

struct
{
    int myNumber;
    string myName;
} myStructure;

// We can also create one structure in multiple variables
struct
{
    int myNum;
    string myName;
} struct1, struct2, struct3;

int main()
{
    myStructure.myNumber = 1;
    myStructure.myName = "SanDisk";

    struct1.myNum = 12;
    struct1.myName = "Western Digital";

    struct2.myNum = 14;
    struct2.myName = "Western";

    struct3.myNum = 16;
    struct3.myName = "Digital";

    cout << "\n My name is : " << myStructure.myName;
    cout << "\n My number is : " << myStructure.myNumber;

    cout << "\n My name is : " << struct1.myNum;
    cout << "\n My number is : " << struct1.myName;

    cout << "\n My name is : " << struct2.myNum;
    cout << "\n My number is : " << struct2.myName;

    cout << "\n My name is : " << struct3.myNum;
    cout << "\n My number is : " << struct3.myName;

    return 0;
}
