#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 123456;
    long long b = (long long)a * a;
    cout << b << "\n";

    int n, m;
    cin >> n >> m;
    long long x = 1;
    for (int i = 1; i <= n; i++) {
        x = (x * i) % m;
    }
    cout << x << "\n";

    double o, l;
    cin >> o >> l;
    if (abs(o - l) < 1e-9) {
        cout << "Iguales\n";
    } else {
        cout << "Diferentes\n";
    }
    return 0;
}