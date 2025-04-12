#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n=5;
    int a[n], b[n];
    int suma[n];
    int productoesc = 0;
    for (int i=0; i<n; i++){
        cout << "coloque un numero a["<< i<<"]:";
        cin >> a[i];
        cout << "coloque un numero b["<< i<<"]:";
        cin >> b[i];
    }
    for (int i=0; i<n; i++){
        suma [i] = a[i]*b[i];
        cout << "producto a["<<i<<"]*b["<<i<< "] ="<<suma[i]<<endl;
    }
    cout<<"Producto escalar:"<< productoesc<< endl;
    return 0;
}
