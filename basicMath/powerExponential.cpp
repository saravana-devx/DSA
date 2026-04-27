#include <iostream>
using namespace std;

double getExponential(double x, int y) {
    double ans = 1;
    long long power = y;  // For INT_MIN
    if (power < 0) {
        power = -power;
        x = 1 / x;
    }
    while (power) {
        if (power) {
            ans = ans * x;
            power = power - 1;
        } else {
            power = power / 2;
            x = x * x;
        }
    }
    return ans;
}

int main() {
    double x;
    int y;
    cout << "Enter value of x : ";
    cin >> x;

    cout << "Enter exponential number y : ";
    cin >> y;

    double ans = getExponential(x, y);

    cout << "exponential of " << x << " to the power " << y << " is " << ans;
}