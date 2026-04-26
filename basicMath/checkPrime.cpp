#include <iostream>
#include <list>

// Basic Approach to find prime
// T.c -> O(√n)
// S.C -> O(1)
bool checkPrime(int n) {
    if (n <= 1) return false;

    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (n / i != i) {
                count++;
            }
        }
    }
    return count == 2;
}

int main() {
    int n;

    std::cout << "Enter a prime number to check : ";
    std::cin >> n;

    if (checkPrime(n)) {
        std::cout << "The number " << n << " is an prime number";
    } else {
        std::cout << "The number is not an prime number";
    }
}