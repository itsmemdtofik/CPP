/**
| **Operation**                | **Java (`HashMap<K, V>`)**                | **Python (`dict`)**                  | **C++ (`unordered_map<K, V>`)**                                                               |
| ---------------------------- | ----------------------------------------- | ------------------------------------ | --------------------------------------------------------------------------------------------- |
| **Create**                   | `Map<K, V> map = new HashMap<>();`        | `my_dict = {}` or `defaultdict(int)` | `unordered_map<K, V> map;`                                                                    |
| **Insert / Add**             | `map.put(key, value);`                    | `my_dict[key] = value`               | `map[key] = value;`                                                                           |
| **Update**                   | `map.put(key, newValue);`                 | `my_dict[key] = new_value`           | `map[key] = newValue;`                                                                        |
| **Get value by key**         | `map.get(key);`                           | `my_dict.get(key)`                   | `map[key]` (⚠️ undefined if key not present, use `map.at(key)` safely)                        |
| **Check key exists**         | `map.containsKey(key);`                   | `key in my_dict`                     | `map.find(key) != map.end()`                                                                  |
| **Check value exists**       | `map.containsValue(value);`               | `value in my_dict.values()`          | `std::find_if(map.begin(), map.end(), [&](auto &p){ return p.second == value;}) != map.end()` |
| **Remove a key**             | `map.remove(key);`                        | `my_dict.pop(key)`                   | `map.erase(key);`                                                                             |
| **Get all keys**             | `map.keySet();`                           | `my_dict.keys()`                     | Iterate: `for (auto &p : map) cout << p.first;`                                               |
| **Get all values**           | `map.values();`                           | `my_dict.values()`                   | Iterate: `for (auto &p : map) cout << p.second;`                                              |
| **Get all entries**          | `map.entrySet();`                         | `my_dict.items()`                    | Iterate: `for (auto &p : map) cout << p.first << p.second;`                                   |
| **Get size**                 | `map.size();`                             | `len(my_dict)`                       | `map.size();`                                                                                 |
| **Clear all entries**        | `map.clear();`                            | `my_dict.clear()`                    | `map.clear();`                                                                                |
| **Iterate (keys)**           | `for (K key : map.keySet())`              | `for key in my_dict:`                | `for (auto &p : map) cout << p.first;`                                                        |
| **Iterate (key-value)**      | `for (Map.Entry<K,V> e : map.entrySet())` | `for key, value in my_dict.items()`  | `for (auto &p : map) cout << p.first << p.second;`                                            |
| **Default value if missing** | `map.getOrDefault(key, default)`          | `my_dict.get(key, default)`          | `map.count(key) ? map[key] : default;`                                                        |
| **Put if absent**            | `map.putIfAbsent(key, value);`            | `my_dict.setdefault(key, value)`     | `map.insert({key, value});`                                                                   |
| **Check if empty**           | `map.isEmpty();`                          | `not my_dict`                        | `map.empty();`                                                                                |
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Create an unordered_map (like Python dict)
    unordered_map<string, int> my_dict;

    // Accessing a missing key directly is undefined,
    // so we handle safely by checking with find()
    if (my_dict.find("apple") == my_dict.end()) {
        cout << 0 << endl; // Equivalent to defaultdict(int) behavior
    }

    // Insert / Add a Key-Value Pair
    my_dict["apple"] = 10;
    my_dict["banana"] = 11;
    my_dict["mango"] = 12;
    my_dict["orange"] = 13;
    my_dict["papaya"] = 14;

    // Update Value
    my_dict["apple"] = 20; // Overwrites previous value

    // Get Value by Key (safe way)
    if (my_dict.find("apple") != my_dict.end()) {
        int val = my_dict["apple"];
        cout << "Apple value = " << val << endl;
    }

    // Check if Key Exists
    if (my_dict.find("apple") != my_dict.end()) {
        // key exists
    }

    // Check if Value Exists
    bool valueExists = false;
    for (auto &p: my_dict) {
        if (p.second == 20) {
            valueExists = true;
            break;
        }
    }

    // Remove a Key
    my_dict.erase("apple");

    // Get All Keys
    cout << "Keys: ";
    for (auto &p: my_dict) {
        cout << p.first << " ";
    }
    cout << endl;

    // Get All Values
    cout << "Values: ";
    for (auto &p: my_dict) {
        cout << p.second << " ";
    }
    cout << endl;

    // Get All Key-Value Pairs
    for (auto &p: my_dict) {
        cout << p.first << ": " << p.second << endl;
    }

    // Get Size
    cout << "Size = " << my_dict.size() << endl;

    // Clear All Entries
    my_dict.clear();

    // Iterate Over Keys
    for (auto &p: my_dict) {
        cout << p.first << endl;
    }

    // Iterate Over Key-Value Pairs
    for (auto &p: my_dict) {
        cout << p.first << ": " << p.second << endl;
    }

    // Get with Default if Missing
    int val = (my_dict.find("banana") != my_dict.end()) ? my_dict["banana"] : 0;

    // Put If Absent
    if (my_dict.find("banana") == my_dict.end()) {
        my_dict["banana"] = 15;
    }

    // Check if Empty
    if (my_dict.empty()) {
        cout << "Dictionary is empty" << endl;
    }

    return 0;
}
