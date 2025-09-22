/**
 * ! Functions in C++
 * 
 * A function is a block of code which only runs when it is called.
 * They are imporant for reusing code. 
 * Define the code once, and use it many times.
 * C++ provides some pre-defined functions, such as main(), which is used to execute code. But we can create our own to create our own functions.
 * 
 * !Note: if a user-defined function, such as foo() is declared after main() function, an error will occur.
 */

 #include<iostream>
 #include<string>
 using namespace std;

 void foo(){//Declaration
    int count = 0;
    count++;
    cout << "I just got executed! " << count;//definition
 }

 int main(){
    foo();
    foo();
    foo();
    return 0;
 }