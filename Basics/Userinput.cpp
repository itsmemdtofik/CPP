#include<iostream>
#include<string>
using namespace std;

int main(){

    string firstName;
    cout << "\nType your first name : ";
    cin >> firstName;

    cout << "\n Yout name is : " << firstName;

    //However cin consider a space (whitespace, tabs, etc) as a terminating character, which means it
    //can only store a single word(even if you type many words) thats why we use getline() when working with string.

    getline(cin, firstName);

    cout << "\n The first name is : " << firstName;


    return 0;
}