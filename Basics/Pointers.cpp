/**
 * ! Pointer in C++
 * 
 * Pointer is a varibale that store the memory address of another variable.
 * A pointer variable points to a data type (like int or string) of the same type, and is created with the * operator. 
 * The address of the variable you're working with is assigned to the pointer:
 */

 #include<iostream>
 #include<string>
 using namespace std;

 int main(){

    string food = "Nihari";
    string *ptr = &food;

    cout <<"Output the value food: "<< food << "\n";

    cout <<"Output the memory address of the food: " << &food << "\n";

    cout << "Output the memory address of food with pointer " << ptr << "\n";

    cout << "Output the value of food using pointer (Dereference) : " << *ptr << "\n";

    return 0;
 }