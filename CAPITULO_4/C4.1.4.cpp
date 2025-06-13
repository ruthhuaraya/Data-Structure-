#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int>& array) {
    if (array.empty()) return;

    int maxValue = *max_element(array.begin(), array.end());

    vector<int> count(maxValue + 1, 0);
    for (int num : array) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= maxValue; i++) {
        while (count[i] > 0) {
            array[index++] = i;
            count[i]--;
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
    vector<int> array = {1, 3, 6, 9, 9, 3, 5, 9};

    cout << "Array original: ";
    printArray(array);

    countingSort(array);

    cout << "Array ordenado: ";
    printArray(array);

    return 0;
}
