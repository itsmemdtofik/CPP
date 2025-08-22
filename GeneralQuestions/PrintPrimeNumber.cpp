#include <iostream>
using namespace std;

// Optimized prime check (6k ± 1)
bool getPrimeII(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    int i = 5, w = 2;
    while (i * i <= number) {
        if (number % i == 0) return false;
        i += w;
        w = 6 - w; // alternates between +2 and +4
    }
    return true;
}

// Generate all primes up to 'number'
vector<int> getAllPrimeNumbers(int number) {
    vector<int> primes;
    for (int num = 2; num <= number; num++) {
        if (getPrimeII(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}

int main() {
    vector<int> primes1 = getAllPrimeNumbers(20);
    for (int p: primes1) cout << p << " ";
    cout << endl; // Output: 2 3 5 7 11 13 17 19

    vector<int> primes2 = getAllPrimeNumbers(100);
    for (int p: primes2) cout << p << " ";
    cout << endl; // Output: all primes ≤ 100

    return 0;
}
