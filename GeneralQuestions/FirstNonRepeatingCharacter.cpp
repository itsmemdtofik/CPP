#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

/* Method 1: Using unordered_map (like defaultdict) */
char getFirstNonRepeatingCharacterUsingHashMap(const string &s) {
    unordered_map<char, int> freq_map;

    for (char ch: s) {
        freq_map[ch]++; // auto-initializes to 0
    }

    // Order of iteration in unordered_map is not guaranteed,
    // so we must check again in original string order
    for (char ch: s) {
        if (freq_map[ch] == 1) {
            return ch;
        }
    }

    return '\0'; // null char if not found
}

/* Method 2: Manual map (like normal dict with explicit checks) */
char getFirstNonRepeatingCharacterUsingHashMapII(const string &s) {
    unordered_map<char, int> freq_map;

    // Count frequency
    for (char ch: s) {
        if (freq_map.find(ch) != freq_map.end()) {
            freq_map[ch] += 1;
        } else {
            freq_map[ch] = 1;
        }
    }

    // Return first non-repeating in original order
    for (char ch: s) {
        if (freq_map[ch] == 1) {
            return ch;
        }
    }
    return '\0';
}

/* Method 3: Ordered version (like OrderedDict) */
char first_unique_char(const string &s) {
    map<char, int> freq_map; // ordered map preserves key order, not insertion order
    for (char ch: s) {
        freq_map[ch] += 1;
    }

    // To strictly preserve original order (like OrderedDict in Python),
    // we must scan the string again
    for (char ch: s) {
        if (freq_map[ch] == 1) {
            return ch;
        }
    }

    return '\0';
}

int main() {
    string str = "alccohhalz";

    cout << "Using HashMap (defaultdict style): "
            << getFirstNonRepeatingCharacterUsingHashMap(str) << endl;

    cout << "Using HashMap II (manual dict style): "
            << getFirstNonRepeatingCharacterUsingHashMapII(str) << endl;

    cout << "Using Ordered Map (OrderedDict style): "
            << first_unique_char(str) << endl;

    return 0;
}

/**
| **Feature**                 | **Python**                                                               | **C++**                                                                  |
| --------------------------- | ------------------------------------------------------------------------ | ------------------------------------------------------------------------ |
| **Defaultdict Style**       | `defaultdict(int)` auto-initializes missing keys → `freq[char] += 1`     | `unordered_map<char,int>` auto-initializes missing keys → `freq[ch]++`   |
| **Manual Dict Style**       | Normal `dict` → requires `if key in dict` check                          | `unordered_map` → requires `if (map.find(ch) != map.end())` check        |
| **Ordered Dict Style**      | `OrderedDict` → preserves insertion order                                | No direct equivalent → use `map` (sorted keys) + rescan original string  |
| **Preserves String Order**  | `for ch in s:` loop ensures correct order when checking frequencies      | Must explicitly rescan original string after counting                    |
| **Missing Key Handling**    | `KeyError` in `dict` (unless `.get()` used), auto-inits in `defaultdict` | No error → missing key auto-initializes to `0` in `unordered_map`        |
| **Performance**             | `dict` and `defaultdict` = **O(1)** average for lookup                   | `unordered_map` = **O(1)** average, `map` = **O(log n)** (tree-based)    |
| **Memory Usage**            | Python dicts are higher memory due to dynamic nature                     | C++ `unordered_map` is more memory-efficient but still higher than array |
| **Lightweight Alternative** | Use `Counter` from `collections`                                         | Use fixed array `int freq[256]` for ASCII characters (faster & smaller)  |
*/
