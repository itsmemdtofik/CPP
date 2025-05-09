/**
 * ! Reference in C++
 * 
 * A reference variable is a "reference" to an existing variable, 
 * and it is created with the & operator:
 * 
 * 
 */

 #include<iostream>
 #include<string>
 using namespace std;

 int main(){

    string a = "Pizza";
    string &b = a;

    cout << a << "\n";
    cout << b << "\n";
    return 0;
 }