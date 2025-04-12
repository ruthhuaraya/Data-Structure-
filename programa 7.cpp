#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n[10];
    cout << "Ingrese 10 numeros:\n";
    for (int i=0;i<10;i++){
        cout << "Numero "<<i+1<<" : ";
        cin>>n[i];
    }
    int ultimo=n[9];
    for(int i =9;i>0;i--){
        n[i]=n[i-1];
    }
    n[0]=ultimo;
    cout << "Rotado:\n";
    for (int i=0;i<10;i++){
        cout <<n[i]<<" ";
    }
    cout << "\n";
    return 0;
}
