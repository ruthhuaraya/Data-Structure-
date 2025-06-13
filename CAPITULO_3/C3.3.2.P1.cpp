#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1000;
    vector<vector<int>> x(n, vector<int>(n, 1));
    long long s = 0;

    // Acceso cache-friendly
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += x[i][j];
        }
    }
    cout << "Suma cache-friendly: " << s << endl;

    s = 0;
    // Acceso menos eficiente
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += x[j][i];
        }
    }
    cout << "Suma menos eficiente: " << s << endl;

    return 0;
}
