/**
 * Prime Factorization: Trial Division
 * Time complexity: O(√n), Space complexity: O(1)
 */

#include <iostream>
#include <cmath>
using namespace std;

class PrimeFactorization {
public:
    static bool isPrime(const int num) {
        if (num <= 1)
            return false;
        if (num == 2)
            return true;
        if (num % 2 == 0)
            return false;

        for (int i = 3; i <= sqrt(num); i += 2) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
};

int main() {
    int n = 17;
    cout << "This is prime number: "
            << boolalpha << PrimeFactorization::isPrime(n) << endl;

    n = 18;
    cout << "This is prime number: "
            << boolalpha << PrimeFactorization::isPrime(n) << endl;

    return 0;
}
