/**
 * !Pass by reference in C++
 * 
 * You are telling the compiler: “When this function is called, don’t make copies. Use the original variables.
 * 
 * So inside the function:
 * x is now a reference to the original firstNum
 * y is a reference to the original secondNum
 * z is just a temporary local variable
 */

 #include<iostream>
 #include<string>
 using namespace std;

 void swap(int &x, int &y){
    int z = x;
    x = y;
    y = z;
 }

 int main(){

    int first_number = 10;
    int second_number = 20;

    cout << "\n Before swapping the value are : " << first_number << " and " << second_number;

    swap(first_number, second_number);
    cout << "\n After swapping the value are : " << first_number << " and " << second_number;
 }