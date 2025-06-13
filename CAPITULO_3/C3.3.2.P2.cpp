#include <bits/stdc++.h>
using namespace std;

typedef long long ll;          // Definir ll como long long
const ll M = 1e9 + 7;          // Módulo usado para evitar overflow

int main() {
    int n = 10;

    // Cálculo tradicional del factorial (mod M)
    ll f = 1;
    for (int i = 1; i <= n; i++) {
        f = (f * i) % M;
    }
    cout << "Factorial simple: " << f << "\n";

    // Cálculo paralelizado (dos productos separados)
    ll f1 = 1, f2 = 1;
    for (int i = 1; i <= n; i += 2) {
        f1 = (f1 * i) % M;
        if (i + 1 <= n)
            f2 = (f2 * (i + 1)) % M;
    }

    ll f_parallel = (f1 * f2) % M;
    cout << "Factorial paralelizado: " << f_parallel << "\n";

    return 0;
}

