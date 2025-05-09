/**
 * !Pass by value in C++
 * 
 * You are telling the compiler: “When this function is called, make copies.
 * This means:
 * The values of a and b are copied into new variables x and y.
 * Any changes made to x or y only affect the copies, not the originals.
 * 
 */

 #include<iostream>
 #include<string>
 using namespace std;

 void swapint(int &x, int &y){
    int z = x;
    x = y;
    y = z;
 }

void swapstring(string &str1, string &str2){
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

 int main(){

    int first_number = 10;
    int second_number = 20;

    string first_string = "Western";
    string second_string = "SanDisk";


    cout << "\n Before swapping the value are : " << first_number << " and " << second_number;

    swapint(first_number, second_number);
    cout << "\n After swapping the value are : " << first_number << " and " << second_number;

    cout << "\n Before swapping the value are : " << first_string << " and " << second_string;

    swapstring(first_string, second_string);
    cout << "\n After swapping the value are : " << first_string << " and " << second_string;
 }