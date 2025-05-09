#include<iostream>
#include<string>
using namespace std;

int main(){
    string myNmae = "Hello";
    cout <<"\n The first character is : " << myNmae[0];
    cout << "\n The last character of it : " << myNmae[myNmae.size() - 1];

    myNmae[0] = 'J';
    cout <<"\n The first character is : " << myNmae[0];

    cout << "\n Printing all the character using at():";
    for(int i = 0; i < myNmae.size(); i++){
        cout << myNmae.at(i);
    }

    cout << "\n Printing the last character using at() : " << myNmae.at(myNmae.length() - 1);

    return 0;
}