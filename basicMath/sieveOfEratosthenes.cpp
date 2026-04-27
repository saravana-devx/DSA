#include <iostream>
#include <vector>
using namespace std;

// T.C -> O(N log(log N)) -> N=10⁷ which is soo small therefore the actuall T.C will be O(N)
// S.C -> O(N)
vector<int> sieveOfEratosthenes(int n) {
    std::vector<int> prime(n + 1, 1);
    std::vector<int> nums;

    if (n >= 0) prime[0] = 0;
    if (n >= 1) prime[1] = 0;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
        }
    }
            }

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            nums.push_back(i);
        }
    }

    return nums;
}

int main() {
    int n;

    cout << "Enter number to get all prime number upto n: ";
    cin >> n;

    std::vector<int> prime = sieveOfEratosthenes(n);
    std::cout << "print all prime number upto " << n << " : ";
    for (auto& factor : prime) {
        std::cout << factor << " ";
    }
    return 0;
}