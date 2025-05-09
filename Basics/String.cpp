#include<iostream>
using namespace std;

int main(){
    string firstname = "Western Digital";
    string lastName = " SanDisk";

    string fullName = firstname + lastName;
    cout << "\t"+fullName <<"\n";

    string appendString = firstname.append(lastName);
    cout << " The append string is : " + appendString;

    //We can also get the length of the string using length() funtion
    cout << "\n The length of the string is : "<< fullName.length();

    //Tip: You might see some C++ programs that use the size() function to get the length of a string. 
    //This is just an alias of length(). It is completely up to you if you want to use length() or size():
    cout << "\n The size of the string using size() is : " << fullName.size();
    return 0;
}