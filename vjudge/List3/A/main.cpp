#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;

    cin >> a >> b >> c;

    cout << setprecision(10);
    cout << fixed;

    if (a != 0) {
        double d = b * b - 4 * a * c;

        if (d < 0) {
            cout << 0 << endl;
            return 0;
        }

        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);

        if (d == 0) {
            cout << 1 << endl;
            double x1 = (-b + sqrt(d)) / (2 * a);
            cout << x1 << endl;
        } else {
            cout << 2 << endl;
            if (x1 > x2) {
                swap(x1, x2);
            }

            cout << x1 << endl;
            cout << x2 << endl;
        }
    } else if (b != 0) {
        double x = -c / b;
        cout << 1 << endl;
        cout << x << endl;
    } else if (c != 0) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
 
    return 0;
}
