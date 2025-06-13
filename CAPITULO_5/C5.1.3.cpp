#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main() {
    deque<int> cola_doble;
    cola_doble.push_back(5);
    cola_doble.push_front(3);
    cola_doble.push_back(7);

    cout << "Elementos en la cola doble: ";
    for (int x : cola_doble) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Primer elemento: " << cola_doble.front() << "\n";
    cout << "Ultimo elemento: " << cola_doble.back() << "\n";
}