#include <iostream>
#include <vector>
using namespace std;

vector<int> smallestPrimeFactor(vector<int> queries) {
    int n = queries.size();
    if (n <= 0) return {};

    int maxR = 0;
    for (auto p : queries) {
        maxR = max(maxR, p);
    }

    std::vector<int> prime(maxR + 1);

    for (int i = 0; i <= maxR; i++) {
        prime[i] = i;
    }

    for (int i = 2; i * i <= maxR; i++) {
        if (prime[i] == i) {
            for (int j = i * i; j <= maxR; j += i) {
                if (prime[j] == j) {
                    prime[j] = i;
                }
            }
        }
    }

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        nums.push_back(prime[queries[i]]);
    }

    return nums;
}

int main() {
    vector<int> queries;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        queries.push_back(x);
    }

    vector<int> smallestNumbers = smallestPrimeFactor(queries);

    for (auto n : smallestNumbers) {
        cout << n << endl;
    }

    return 0;
}