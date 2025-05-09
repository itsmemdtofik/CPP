#include<iostream>
using namespace std;
int main(){
    cout << "Hello World!";
    return 0;
}

/**
 * Line 1: #include <iostream> is a header file library that lets us work with input and output objects, such as cout (used in line 5). 
 * Header files add functionality to C++ programs.
 * Line 2: using namespace std means that we can use names for objects and variables from the standard library.
 * Line 3: A blank line. C++ ignores white space. But we use it to make the code more readable.
 * Line 4: Another thing that always appear in a C++ program is int main(). This is called a function. Any code inside its curly brackets {} will be executed.
 * Line 5: cout (pronounced "see-out") is an object used together with the insertion operator (<<) to output/print text. In our example, it will output "Hello World!".
 * !Note: C++ is case-sensitive: "cout" and "Cout" has different meaning.
 * !Note: The body of int main() could also been written as: int main () { cout << "Hello World! "; return 0; }
 */