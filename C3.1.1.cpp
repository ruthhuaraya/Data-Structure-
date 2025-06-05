#include <bits/stdc++.h>
using namespace std;

// Función recursiva con complejidad O(n)
void linearRecursion(int n) {
    if (n == 1) return;
    linearRecursion(n - 1);
}

// Función recursiva con complejidad O(2^n)
void exponentialRecursion(int n) {
    if (n == 1) return;
    exponentialRecursion(n - 1);
    exponentialRecursion(n - 1);
}

int main() {
    int n = 5, m = 4;

    //Comandos simples O(1)
    int a = 1;
    int b = 2;
    int c = a + b;

    //Bucle simple O(n)
    for (int i = 1; i <= n; i++) {
        cout << "Linea " << i << " del bucle O(n)" << endl;
    }

    //Bucle anidado O(n^2)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int temp = i + j;
        }
    }

    //Bucle que ejecuta 3n veces (O(n))
    for (int i = 1; i <= 3 * n; i++) {
    }

    //Bucle que ejecuta n/2 veces (O(n))
    for (int i = 1; i <= n; i += 2) {
    }

    //Bucle triangular O(n^2) con sumatoria 1+2+...+n
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
        }
    }

    //Bucle doble con variables n y m (O(nm))
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
        }
    }

    //Recursividad O(n)
    linearRecursion(n);

    //Recursividad O(2^n)
    exponentialRecursion(5);

    return 0;
}
