/**
 * !Copy in C++
 * To copy elements from one vector to another, you can use the copy() function:
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  // Create a vector called numbers that will store integers
  vector<int> numbers = {1, 7, 3, 5, 9, 2};
  
  // Create a vector called copiedNumbers that should store 6 integers
  vector<int> copiedNumbers(6);
  
  // Copy elements from numbers to copiedNumbers
  copy(numbers.begin(), numbers.end(), copiedNumbers.begin()); 

  // Print elements of copiedNumbers 
  for (int num : copiedNumbers) {
    cout << num << "\n";
  }
  
  return 0;
}
