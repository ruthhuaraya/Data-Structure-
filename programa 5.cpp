#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    double c[30], suma = 0, promedio;
    int mp = 0;
    cout << "Ingresar nota:\n";

    int i;
    for (i = 0; i < 30; i++) {
        cout << "Estudiante (" << i + 1 << "): ";
        cin >> c[i];
        suma += c[i];
    }

    promedio = suma / 30;
    cout << "\nPromedio: " << promedio << "\n";

    for (i = 0; i < 30; i++) {
        if (c[i] > promedio) {
            mp++;
        }
    }

    cout << "Estudiantes sobre el promedio: " << mp << "\n";
    return 0;
}