#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> array = {1, 3, 8, 2, 9, 2, 5, 6};

    cout << "Array original: ";
    printArray(array);

    bubbleSort(array);

    cout << "Array ordenado: ";
    printArray(array);

    return 0;
}