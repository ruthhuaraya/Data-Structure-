#include <bits/stdc++.h>
using namespace std;

// Función Collatz simple
int collatz(int n) {
    if (n % 2 == 0) return n / 2;
    else return 3 * n + 1;
}

int main() {
    int n;
    cout << "Ingrese un numero entero: ";
    cin >> n;

    int resultado = collatz(n);
    cout << "Resultado de collatz(" << n << ") = " << resultado << "\n";

    return 0;
}
