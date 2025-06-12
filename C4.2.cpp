#include <bits/stdc++.h>
using namespace std;
bool allUniqueBruteForce(const vector<int>& array) { // Fuerza bruta O(n^2)
    int n = array.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) return false;
        }
    }
    return true;
}

bool allUniqueSorted(vector<int> array) { // Ordenando primero O(n log n)
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size() - 1; i++) {
        if (array[i] == array[i + 1]) return false;
    }
    return true;
}

void printResult(bool result) {
    if (result)
        cout << "Todos los elementos son unicos.\n";
    else
        cout << "Hay elementos duplicados.\n";
}

int main() {
    vector<int> array = {3, 1, 4, 2, 5, 3};

    cout << "Usando fuerza bruta:\n";
    printResult(allUniqueBruteForce(array));

    cout << "\nUsando ordenamiento:\n";
    printResult(allUniqueSorted(array));

    return 0;
}