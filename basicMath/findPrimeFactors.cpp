#include <iostream>
#include <list>

// Checks if a number is prime
// Time Complexity: O(√n)
// Space Complexity: O(1)
bool isPrime(int n) {
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

// Finds all distinct prime factors using brute force
// Time Complexity: O(n * √n)
// Space Complexity: O(k)
std::list<int> getPrimeFactorsBruteForce(int n) {
    std::list<int> nums;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                nums.push_back(i);
            }
        }
    }
    return nums;
}

// Finds all distinct prime factors using √n optimization
// Time Complexity: O(n)
// Space Complexity: O(k)
std::list<int> getPrimeFactorsUsingSqrt(int n) {
    std::list<int> nums;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                nums.push_back(i);
                if (n / i != i) {
                    if (isPrime(n / i)) {
                        nums.push_back(n / i);
                    }
                }
            }
        }
    }
    return nums;
}

// Finds distinct prime factors by reducing n
// Time Complexity: O(n)
// Space Complexity: O(k)
std::list<int> getPrimeFactorsWithReduction(int n) {
    std::list<int> nums;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                nums.push_back(i);
                while (n % i == 0) {
                    n = n / i;
                }
            }
        }
    }
    return nums;
}

// Finds distinct prime factors using √n optimization and reduction
// Time Complexity: O(√n)
// Space Complexity: O(k)
std::list<int> getPrimeFactorsOptimized(int n) {
    std::list<int> nums;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                nums.push_back(i);
                while (n % i == 0) {
                    n = n / i;
                }
            }
        }
    }

    if (n != 1) nums.push_back(n);

    return nums;
}

int main() {
    int n;

    std::cout << "Enter a number to get prime factors: ";
    std::cin >> n;

    std::list<int> nums = getPrimeFactorsOptimized(n);

    std::cout << "Distinct prime factors: ";
    for (auto& factor : nums) {
        std::cout << factor << " ";
    }

    return 0;
}