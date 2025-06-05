#include <bits/stdc++.h>
using namespace std;

// Búsqueda simple sin break 
bool BS(const vector<int>& a, int x) {
    bool ok = false;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == x) ok = true;
    }
    return ok;
}

// Búsqueda con break (más eficiente)
bool BCB(const vector<int>& a, int x) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == x) return true;
    }
    return false;
}

// Búsqueda con sentinela
bool BCS(vector<int>& a, int x) {
    int n = (int)a.size();
    a.push_back(x);
    int i = 0;
    while (a[i] != x) {
        i++;
    }
    a.pop_back(); 
    return i < n;
}

int main() {
    int n, x;
    cout << "Ingrese medida del arreglo: ";
    cin >> n;
    cout << "Ingrese elemento a buscar: ";
    cin >> x;

    vector<int> a(n);

    cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool R1 = BS(a, x);
    bool R2 = BCB(a, x);
    bool R3 = BCS(a, x);

    cout << "\nResultados:\n";
    cout << "1. Simple sin break: " << (R1 ? "Encontrado " : "No encontrado ") << "\n";
    cout << "2. Con break       : " << (R2 ? "Encontrado " : "No encontrado ") << "\n";
    cout << "3. Con sentinela   : " << (R3 ? "Encontrado " : "No encontrado ") << "\n";

    return 0;
}
