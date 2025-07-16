#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
bool np(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int main() {
    srand(time(0)); 
    int n[100];     
    int p = 0;       
    cout << "Numeros generados:\n";
    for (int i = 0; i < 100; i++) {
        n[i] = rand() % 500 + 1; 
        cout << n[i] << " ";
        if (np(n[i])) { 
            p++;
        }
    }
    cout << "\n\nTotal de numeros primos: " << p << "\n";
    return 0;
}