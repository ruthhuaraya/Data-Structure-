#include <bits/stdc++.h>
using namespace std;
bool binarySearchClassic(const vector<int>& array, int x) { // Búsqueda binaria clasica
    int a = 0, b = array.size() - 1;
    while (a <= b) {
        int k = (a + b) / 2;
        if (array[k] == x) return true;
        if (array[k] < x) a = k + 1;
        else b = k - 1;
    }
    return false;
}

bool binarySearchJump(const vector<int>& array, int x) { // Búsqueda binaria por saltos
    int n = array.size();
    int k = 0;
    for (int b = n / 2; b >= 1; b /= 2) {
        while (k + b < n && array[k + b] <= x) {
            k += b;
        }
    }
    return array[k] == x;
}

int main() {
    vector<int> array = {1, 3, 4, 5, 5, 6, 9, 10, 12, 12, 15};

    int x;
    cout << "Ingrese el numero a buscar: ";
    cin >> x;

    cout << "\nUsando busqueda binaria clasica:\n";
    if (binarySearchClassic(array, x))
        cout << x << " fue encontrado.\n";
    else
        cout << x << " no se encuentra en el arreglo.\n";

    cout << "\nUsando busqueda binaria por saltos:\n";
    if (binarySearchJump(array, x))
        cout << x << " fue encontrado.\n";
    else
        cout << x << " no se encuentra en el arreglo.\n";

    return 0;
}