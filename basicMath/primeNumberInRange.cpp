#include <iostream>
#include <vector>
using namespace std;

int isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> getSieve(int n) {
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

    return prime;
}

void primeNumberInRange(vector<pair<int, int>> queries) {
    int q = queries.size();
    int maxR = 0;
    for (auto& p : queries) {
        maxR = max(maxR, p.second);
    }
    vector<int> nums = getSieve(maxR);

    int count = 0;
    for (int i = 2; i < nums.size(); i++) {
        count = nums[i] + count;
        nums[i] = count;
    }

    for (int i = 0; i <= q; i++) {
        int l = queries[i].first;
        int r = queries[i].second;
        cout << "count is : " << i << " "<< (nums[r] - nums[l - 1]) << endl;
    }
}

int main() {
    vector<pair<int, int>> queries;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
    }

    primeNumberInRange(queries);
}