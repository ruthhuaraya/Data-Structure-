#include <bits/stdc++.h>
using namespace std;

// Algoritmo lineal O(n)
void AL(int n) {
    for (int i = 0; i < n; i++) {
            }
}

// Algoritmo cuadrático O(n^2)
void AC(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        }
    }
}

// Algoritmo logarítmico O(log n)
void ALOG(int n) {
    while (n > 1) {
        n /= 2;
    }
}

int main() {
    int n1 = 10000;  // tamaño para lineal y logarítmico
    int n2 = 300;    // tamaño reducido para cuadrático

    cout << "\nEjecucion de algoritmos\n";

    AL(n1);
    cout << "Algoritmo Lineal (O(n)) ejecutado\n";

    AC(n2);
    cout << "Algoritmo Cuadratico (O(n^2)) ejecutado\n";

    ALOG(n1);
    cout << "Algoritmo Logaritmico (O(log n)) ejecutado\n";

    return 0;
}