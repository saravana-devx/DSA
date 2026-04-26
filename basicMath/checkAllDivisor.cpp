#include <iostream>
#include <vector>
using namespace std;

void printDivisors(std::vector<int>& arr, int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            arr.push_back(i);
            if (n / i != i) {
                arr.push_back(n / i);
            }
        }
    }
    cout << "All  dvisiors for value " << n << " is : ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    std::vector<int> arr;
    int n;

    std::cout << "Input value for n :: ";
    std::cin >> n;

    printDivisors(arr, n);
}