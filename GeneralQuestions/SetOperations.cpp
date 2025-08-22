/**
✅ C++ Set Operations Summary Table:

| Operation                      | Syntax (C++)                                                                              | Description                              | Example (Output shown as comments) |
| ------------------------------ | ----------------------------------------------------------------------------------------- | ---------------------------------------- | ---------------------------------- |
| **Create a set**               | `std::set<int> s = {1, 2, 3};`                                                            | Creates a set                            | `s = {1, 2, 3}`                    |
| **Add an element**             | `s.insert(x);`                                                                            | Adds element `x` to the set              | `s.insert(4); // {1, 2, 3, 4}`     |
| **Remove an element (safe)**   | `s.erase(x);`                                                                             | Removes element `x` if it exists         | `s.erase(2); // {1, 3, 4}`         |
| **Check element existence**    | `s.count(x)`                                                                              | Returns 1 if `x` exists, 0 otherwise     | `s.count(2) // 0`                  |
| **Erase using iterator**       | `s.erase(it);`                                                                            | Removes element at iterator `it`         |                                    |
| **Clear all elements**         | `s.clear();`                                                                              | Empties the set                          | `s.clear(); // {}`                 |
| **Set size**                   | `s.size();`                                                                               | Number of elements in the set            | `{1,2,3}.size() // 3`              |
| **Check empty**                | `s.empty();`                                                                              | Returns `true` if set is empty           |                                    |
| **Union**                      | `std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));` | Combines elements from both sets         | `{1,2} ∪ {2,3} // {1,2,3}`         |
| **Intersection**               | `std::set_intersection(...);`                                                             | Elements common to both sets             | `{1,2} ∩ {2,3} // {2}`             |
| **Difference**                 | `std::set_difference(...);`                                                               | Elements in `s1` but not in `s2`         | `{1,2} - {2,3} // {1}`             |
| **Symmetric difference**       | `std::set_symmetric_difference(...);`                                                     | Elements in either set but not both      | `{1,2} ^ {2,3} // {1,3}`           |
| **Subset check**               | `std::includes(s2.begin(), s2.end(), s1.begin(), s1.end());`                              | Checks if `s1 ⊆ s2`                      | `{1,2} ⊆ {1,2,3} // true`          |
| **Proper subset**              | `includes(...) && s1.size() < s2.size()`                                                  | True if `s1` is a proper subset          | `{1,2} < {1,2,3} // true`          |
| **Superset check**             | `includes(s1.begin(), s1.end(), s2.begin(), s2.end());`                                   | Checks if `s1 ⊇ s2`                      | `{1,2,3} ⊇ {2} // true`            |
| **Proper superset**            | `includes(...) && s1.size() > s2.size()`                                                  | True if `s1` is a proper superset        | `{1,2,3} > {2} // true`            |
| **Equality**                   | `s1 == s2`                                                                                | True if both sets have the same elements | `{1,2} == {2,1} // true`           |
| **Inequality**                 | `s1 != s2`                                                                                | True if sets are not equal               | `{1,2} != {1,3} // true`           |
| **Iterate over set**           | `for(auto x : s) cout << x;`                                                              | Loops through elements in sorted order   |                                    |
| **Set with custom comparator** | `std::set<int, std::greater<int>> s;`                                                     | Stores elements in descending order      | `{3,2,1}`                          |
| **Immutable set**              | Not available (closest: `const std::set`)                                                 | No direct `frozenset` equivalent in C++  |                                    |
*/

/**
| Feature                    | `set` (std::set) | `unordered_set` (std::unordered\_set) |
| -------------------------- | ---------------- | ------------------------------------- |
| **Order**                  | Sorted           | Unordered (depends on hash)           |
| **Duplicates**             | Not allowed      | Not allowed                           |
| **Implementation**         | Red-Black Tree   | Hash Table                            |
| **Insertion/Search/Erase** | O(log n)         | O(1) average (O(n) worst)             |
| **Iteration**              | Sorted order     | Random/unpredictable order            |
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    // Creating a Set
    set<int> seen;

    // Add elements
    seen.insert(10);
    seen.insert(20);
    seen.insert(30);
    seen.insert(40);

    // Remove elements
    seen.erase(2); // erase() won't throw error if element not present
    seen.clear(); // removes all

    // Add elements again
    seen.insert(10);
    seen.insert(20);
    seen.insert(30);
    seen.insert(40);

    // Check Membership (iterate)
    for (int i: seen) {
        // pass
    }

    // Update the set: add multiple elements
    vector<int> arr = {5, 6};
    seen.insert(arr.begin(), arr.end());
    cout << "Updated set: ";
    for (int v: seen) cout << v << " ";
    cout << "\n";

    // Size of set
    cout << "Size: " << seen.size() << "\n";

    // Iteration
    cout << "Iteration: ";
    for (int v: seen) cout << v << " ";
    cout << "\n";

    // Set Union
    set<int> set1 = {1, 2, 3};
    set<int> set2 = {3, 4, 5};

    set<int> union_set;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
              inserter(union_set, union_set.begin()));

    cout << "Union: ";
    for (int v: union_set) cout << v << " ";
    cout << "\n";

    // Intersection
    set<int> intersection_set;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     inserter(intersection_set, intersection_set.begin()));

    cout << "Intersection: ";
    for (int v: intersection_set) cout << v << " ";
    cout << "\n";

    // Difference (set1 - set2)
    set<int> diff_set;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   inserter(diff_set, diff_set.begin()));

    cout << "Difference (set1 - set2): ";
    for (int v: diff_set) cout << v << " ";
    cout << "\n";

    // Symmetric Difference
    set<int> sym_diff_set;
    set_symmetric_difference(set1.begin(), set1.end(),
                             set2.begin(), set2.end(),
                             inserter(sym_diff_set, sym_diff_set.begin()));

    cout << "Symmetric Difference: ";
    for (int v: sym_diff_set) cout << v << " ";
    cout << "\n";

    // Subset / Superset
    bool is_subset = includes(set1.begin(), set1.end(), set2.begin(), set2.end());
    bool is_superset = includes(set2.begin(), set2.end(), set1.begin(), set1.end());
    cout << "set2 is subset of set1? " << (is_subset ? "true" : "false") << "\n";
    cout << "set1 is superset of set2? " << (is_superset ? "true" : "false") << "\n";

    // Equality check
    cout << "set1 == set2? " << (set1 == set2 ? "true" : "false") << "\n";

    // Convert list to set (deduplication)
    vector<int> nums = {1, 2, 2, 3};
    set<int> nums_set(nums.begin(), nums.end());

    cout << "Original List: ";
    for (int v: nums) cout << v << " ";
    cout << "\n";
    cout << "After converting into set: ";
    for (int v: nums_set) cout << v << " ";
    cout << "\n";

    // Set comprehension (square elements)
    set<int> squared;
    for (int x: nums_set) squared.insert(x * x);

    cout << "Set comprehension (squared): ";
    for (int v: squared) cout << v << " ";
    cout << "\n";

    // Subset check
    cout << "{1,2} ⊆ {1,2,3}? "
            << (includes(set<int>{1, 2, 3}.begin(), set<int>{1, 2, 3}.end(),
                         set<int>{1, 2}.begin(), set<int>{1, 2}.end())
                    ? "true"
                    : "false") << "\n";

    // Superset check
    cout << "{1,2,3} ⊇ {1,2}? "
            << (includes(set<int>{1, 2, 3}.begin(), set<int>{1, 2, 3}.end(),
                         set<int>{1, 2}.begin(), set<int>{1, 2}.end())
                    ? "true"
                    : "false") << "\n";

    // Equality check (order doesn't matter)
    cout << "{1,2} == {2,1}? " << (set<int>{1, 2} == set<int>{2, 1} ? "true" : "false") << "\n";

    // Inequality
    cout << "{1,2} != {1,3}? " << (set<int>{1, 2} != set<int>{1, 3} ? "true" : "false") << "\n";

    // Immutable set equivalent: use const set
    const set<int> fs = {1, 2, 3};
    cout << "Immutable Set: ";
    for (int v: fs) cout << v << " ";
    cout << "\n";

    // Iterate through a set
    cout << "Iterating {1,2,3}: ";
    for (int item: set<int>{1, 2, 3}) {
        cout << item << " ";
    }
    cout << "\n";

    return 0;
}
