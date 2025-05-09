/**
 * !Pass array to a function in C++
 * 
 */

 #include<iostream>
 #include<string>
 using namespace std;

 void sandisk(int arr[]){
    for(int i = 0; i < 5; i++){
        cout << arr[i] << "\n";
    }
 }

 int main(){
    int arr[5] = {10, 20, 30, 40, 50};
    sandisk(arr);
    return 0;
 }