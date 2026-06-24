#include <iostream>
#include <vector>
using namespace std;

int FindNumber(int n, vector<int> arr) {
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (arr[i] == n) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {4, 2, 3, 4, 2, 4, 5};
    int n = 4;
    int ans = FindNumber(n, arr);
    cout << ans;
    return 0;
}