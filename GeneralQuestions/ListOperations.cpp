/**
 ✅ C++ std::vector Operations Summary Table

| **Operation**              | **C++ (`std::vector`) Syntax / Method**       | **Description**               | **Example & Result**                        |
| -------------------------- | --------------------------------------------- | ----------------------------- | ------------------------------------------- |
| **Create vector**          | `vector<int> v = {1,2,3};`                    | Creates a vector              | `{1,2,3}`                                   |
| **Access item**            | `v[i]`                                        | Gets item at index `i`        | `v[0] → 1`                                  |
| **At (with bounds check)** | `v.at(i)`                                     | Gets item at index `i` safely | `v.at(0) → 1`                               |
| **Length / Size**          | `v.size()`                                    | Number of elements            | `3`                                         |
| **Append / Push back**     | `v.push_back(x)`                              | Adds `x` to end               | `{1,2,3} → {1,2,3,x}`                       |
| **Insert at index**        | `v.insert(v.begin()+i, x)`                    | Inserts `x` at index `i`      | `{1,2,3} → {1,x,2,3}`                       |
| **Remove last element**    | `v.pop_back()`                                | Removes last element          | `{1,2,3} → {1,2}`                           |
| **Erase element**          | `v.erase(v.begin()+i)`                        | Removes element at index `i`  | `{1,2,3} → {1,3}`                           |
| **Clear**                  | `v.clear()`                                   | Removes all elements          | `{}`                                        |
| **Index of item**          | Manual search (`std::find`)                   | First index of `x`            | `find(v.begin(), v.end(), 2)-v.begin() → 1` |
| **Count occurrences**      | `std::count(v.begin(), v.end(), x)`           | Number of occurrences         | `count(v.begin(), v.end(), 2) → 2`          |
| **Reverse (in-place)**     | `std::reverse(v.begin(), v.end())`            | Reverses vector in-place      | `{1,2} → {2,1}`                             |
| **Sort (in-place)**        | `std::sort(v.begin(), v.end())`               | Sorts vector                  | `{3,1} → {1,3}`                             |
| **Copy vector**            | `vector<int> v2 = v;`                         | Shallow copy                  | `v2 = {1,2,3}`                              |
| **Join vector of strings** | Manual loop + `ostringstream`                 | Join into string              | `{"a","b"} → "a b"`                         |
| **Repeat vector**          | Manual loop / `insert`                        | Repeat contents               | `{1,2} * 3 → {1,2,1,2,1,2}`                 |
| **Membership**             | `std::find(v.begin(), v.end(), x) != v.end()` | True if `x` in vector         | `2 in {1,2,3} → true`                       |
| **Loop through vector**    | `for(auto x : v)`                             | Iterate each element          | prints all                                  |
| **Enumerate items**        | `for(int i=0; i<v.size(); i++)`               | Index + value pair            | `i, v[i]`                                   |
| **Transform / Map**        | `for(auto &x : v) x = x*x;`                   | Transform items               | `{1,2,3} → {1,4,9}`                         |
| **Filter items**           | Manual loop + push\_back                      | Conditional vector            | `{1,2,3,4} → {3,4}`                         |
| **Nested vector access**   | `v[0][1]`                                     | Access inner vector elements  | `{{1,2},{3,4}} → 2`                         |
*/

/**
🔢 Math / Conversion Utilities in C++:

| **Python Function** | **C++ Equivalent**                               | **Description**                      | **Example (C++)**                                                          |
| ------------------- | ------------------------------------------------ | ------------------------------------ | -------------------------------------------------------------------------- |
| `sum(lst)`          | `accumulate(lst.begin(), lst.end(), 0)`          | Sum of all elements                  | `vector<int> v = {1,2,3}; cout << accumulate(v.begin(), v.end(), 0); // 6` |
| `min(lst)`          | `*min_element(lst.begin(), lst.end())`           | Minimum element                      | `vector<int> v = {1,2,3}; cout << *min_element(v.begin(), v.end()); // 1`  |
| `max(lst)`          | `*max_element(lst.begin(), lst.end())`           | Maximum element                      | `vector<int> v = {1,2,3}; cout << *max_element(v.begin(), v.end()); // 3`  |
| `list(str)`         | `vector<char>(str.begin(), str.end())`           | Convert string to list of characters | `string s = "abc"; vector<char> v(s.begin(), s.end()); // {'a','b','c'}`   |
| `list(range(n))`    | `vector<int> v(n); iota(v.begin(), v.end(), 0);` | Create numeric list                  | `vector<int> v(3); iota(v.begin(), v.end(), 0); // {0,1,2}`                |
*/

/**
✅ Advanced List Tricks: Python → C++

| **Trick**       | **Python Code**               | **C++ Equivalent**                                                                                               | **Result / Notes**              |
| --------------- | ----------------------------- | ---------------------------------------------------------------------------------------------------------------- | ------------------------------- |
| Reverse copy    | `lst[::-1]`                   | `vector<int> rev(lst.rbegin(), lst.rend());`                                                                     | Returns reversed copy of vector |
| Unique items    | `list(set(lst))`              | `set<int> s(lst.begin(), lst.end()); vector<int> unique(s.begin(), s.end());`                                    | Removes duplicates (unordered)  |
| Flatten 2D list | `[y for x in lst for y in x]` | `vector<int> flat; for(auto &x : lst) flat.insert(flat.end(), x.begin(), x.end());`                              | Flattens a 2D vector            |
| Zip lists       | `zip(list1, list2)`           | `vector<pair<int,int>> zipped; for(size_t i=0;i<min(v1.size(),v2.size());i++) zipped.push_back({v1[i], v2[i]});` | Pairs items from both vectors   |
| Unpack list     | `a, b, c = lst`               | `int a = v[0], b = v[1], c = v[2];`                                                                              | Assign each element to variable |
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "All List Operations:\n" << endl;

    // Create a vector (like Python list)
    vector<int> nums = {1, 2, 3};

    // Access item (Indexing)
    cout << "First Element: " << nums[0] << endl;

    // Negative indexing (simulate: last element)
    cout << "Last element in the list: " << nums[nums.size() - 1] << endl;

    // List slicing [1:3] -> print manually
    cout << "[";
    for (int i = 1; i < 3; i++) cout << nums[i] << (i < 2 ? ", " : "");
    cout << "]" << endl; // Output: [2, 3]

    // Insert an item from end (append)
    nums.push_back(4);

    // Adds multiple items
    nums.push_back(5);
    nums.push_back(6);
    for (int x: nums) cout << x << " ";
    cout << endl; // Output: 1 2 3 4 5 6

    // Insert item at index 2
    nums.insert(nums.begin() + 2, 10);
    for (int x: nums) cout << x << " ";
    cout << endl; // Output: 1 2 10 3 4 5 6

    // Remove first occurrence of 10
    auto it = find(nums.begin(), nums.end(), 10);
    if (it != nums.end()) nums.erase(it);
    for (int x: nums) cout << x << " ";
    cout << endl; // Output: 1 2 3 4 5 6

    // Pop last element
    int x = nums.back();
    nums.pop_back();
    cout << x << endl; // Output: 6
    for (int y: nums) cout << y << " ";
    cout << endl; // Output: 1 2 3 4 5

    // Clear the list
    nums.clear();
    cout << "Size after clear: " << nums.size() << endl; // Output: 0

    // Index of first 2
    nums = {1, 2, 3, 2};
    cout << "Index of 2: " << (find(nums.begin(), nums.end(), 2) - nums.begin()) << endl;

    // Count occurrences of 2
    cout << "Count of 2: " << count(nums.begin(), nums.end(), 2) << endl;

    // Reverse in place
    reverse(nums.begin(), nums.end());
    for (int y: nums) cout << y << " ";
    cout << endl; // Output: 2 3 2 1

    // Sort in place
    sort(nums.begin(), nums.end());
    for (int y: nums) cout << y << " ";
    cout << endl; // Output: 1 2 2 3

    // Sorted copy
    vector<int> lst = {3, 1, 2};
    vector<int> new_lst = lst;
    sort(new_lst.begin(), new_lst.end());
    for (int y: new_lst) cout << y << " ";
    cout << endl; // Output: 1 2 3

    // Copy list
    vector<int> copy_lst = lst;
    for (int y: copy_lst) cout << y << " ";
    cout << endl; // Output: 3 1 2

    // Join list of strings
    vector<string> words = {"hello", "world"};
    cout << words[0] + " " + words[1] << endl; // Output: hello world

    // Multiply list [0]*5
    vector<int> mul(5, 0);
    for (int y: mul) cout << y << " ";
    cout << endl; // Output: 0 0 0 0 0

    // Membership (find 2 in lst)
    cout << (find(lst.begin(), lst.end(), 2) != lst.end() ? "True" : "False") << endl;

    // Loop through list
    for (int y: lst) cout << y << " ";
    cout << endl;

    // Enumerate
    for (int i = 0; i < lst.size(); i++)
        cout << "Index is: " << i << ", Value is: " << lst[i] << endl;

    // List comprehension: squares
    vector<int> squares;
    for (int i = 0; i < 5; i++) squares.push_back(i * i);
    for (int y: squares) cout << y << " ";
    cout << endl; // Output: 0 1 4 9 16

    // Filter evens
    vector<int> evens;
    for (int i = 0; i < 10; i++) if (i % 2 == 0) evens.push_back(i);
    for (int y: evens) cout << y << " ";
    cout << endl; // Output: 0 2 4 6 8

    // Nested list
    vector<vector<int> > matrix = {{1, 2}, {3, 4}};
    cout << matrix[1][0] << endl; // Output: 3

    // Flatten
    vector<int> flat;
    for (auto &row: matrix) for (int y: row) flat.push_back(y);
    for (int y: flat) cout << y << " ";
    cout << endl; // Output: 1 2 3 4

    // Zip two lists
    vector<string> names = {"a", "b"};
    vector<int> ages = {10, 20};
    for (int i = 0; i < names.size(); i++)
        cout << "(" << names[i] << ", " << ages[i] << ") ";
    cout << endl; // Output: (a, 10) (b, 20)

    // Unpack list
    int a, b, c;
    tie(a, b, c) = tuple<int, int, int>(1, 2, 3);
    cout << a << " " << b << " " << c << endl;

    // Reverse copy
    lst = {1, 2, 3};
    vector<int> rev = lst;
    reverse(rev.begin(), rev.end());
    for (int y: rev) cout << y << " ";
    cout << endl; // Output: 3 2 1

    return 0;
}
