#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& array, int left, int mid, int right) {
    vector<int> temp;
    int i = left;    
    int j = mid + 1;  

    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp.push_back(array[i]);
            i++;
        } else {
            temp.push_back(array[j]);
            j++;
        }
    }

    while (i <= mid) temp.push_back(array[i++]);
    while (j <= right) temp.push_back(array[j++]);

    for (int k = 0; k < temp.size(); k++) {
        array[left + k] = temp[k];
    }
}

void mergeSort(vector<int>& array, int left, int right) {
    if (left >= right) return; 

    int mid = (left + right) / 2;
    mergeSort(array, left, mid);        
    mergeSort(array, mid + 1, right);   
    merge(array, left, mid, right);    
}

void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    vector<int> array = {1, 3, 6, 2, 8, 2, 5, 9};

    cout << "Array original: ";
    printArray(array);

    mergeSort(array, 0, array.size() - 1);

    cout << "Array ordenado: ";
    printArray(array);

    return 0;
}