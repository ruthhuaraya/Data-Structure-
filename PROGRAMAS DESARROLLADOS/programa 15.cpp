#include <bits/stdc++.h>
#include <stack>
#include <queue>

using namespace std;

void transferColaAPila(queue<int>& cola, stack<int>& pila, int n) {
    for (int i = 0; i < n && !cola.empty(); ++i) {
        int elemento = cola.front();
        cola.pop();
        pila.push(elemento);
        cout << "Transferido de cola a pila: " << elemento << endl;
    }
}

void transferPilaACola(stack<int>& pila, queue<int>& cola, int n) {
    for (int i = 0; i < n && !pila.empty(); ++i) {
        int elemento = pila.top();
        pila.pop();
        cola.push(elemento);
        cout << "Transferido de pila a cola: " << elemento << endl;
    }
}

void mostrarPila(stack<int> pila) {
    cout << "Pila (top -> bottom): ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
}

void mostrarCola(queue<int> cola) {
    cout << "Cola (front -> back): ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
}

int main() {
    stack<int> pila;
    queue<int> cola;

    for (int i = 1; i <= 5; ++i) {
        pila.push(i);     
        cola.push(i + 10);   
    }

    cout << "Estado inicial:\n";
    mostrarPila(pila);
    mostrarCola(cola);

    int opcion, n;

    cout << "\nOPERACION\n";
    cout << "1. Transferir de pila a cola\n";
    cout << "2. Transferir de cola a pila\n";
    cout << "Opcion: ";
    cin >> opcion;

    cout << "Cantidad de elementos a transferir: ";
    cin >> n;

    if (opcion == 1) {
        transferPilaACola(pila, cola, n);
    } else if (opcion == 2) {
        transferColaAPila(cola, pila, n);
    } else {
        cout << "Opcion no valida.\n";
    }

    cout << "\nEstado final:\n";
    mostrarPila(pila);
    mostrarCola(cola);

    return 0;
}
