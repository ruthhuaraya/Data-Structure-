#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumN3(const vector<int>& array) {
    int n = array.size();
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            int sum = 0;
            for (int k = a; k <= b; k++) {
                sum += array[k];
            }
            best = max(best, sum);
        }
    }
    return best;
}

int maxSubarraySumN2(const vector<int>& array) {
    int n = array.size();
    int best = 0;
    for (int a = 0; a < n; a++) {
        int sum = 0;
        for (int b = a; b < n; b++) {
            sum += array[b];
            best = max(best, sum);
        }
    }
    return best;
}

int maxSubarraySumN(const vector<int>& array) {
    int n = array.size();
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    return best;
}

int main() {
    int n;
    cout << "Ingrese medida del arreglo: ";
    cin >> n;
    vector<int> array(n);

    cout << "Ingrese los elementos del arreglo (pueden ser negativos):\n";
    for (int i = 0; i < n; i++) cin >> array[i];
    
    int RN3 = maxSubarraySumN3(array);
    int RN2 = maxSubarraySumN2(array);
    int RN = maxSubarraySumN(array);

    cout << "\nResultados:\n";
    cout << "O(n^3) suma maxima: " << RN3 << "\n";
    cout << "O(n^2) suma maxima: " <<RN2<< " \n";
    cout << "O(n) suma maxima: " << RN << "\n";

    return 0;
}