#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arg1[10],arg2[10],iguales=0;
    cout <<"Primer arreglo.- Ingrese 10 numeros:\n";
    for (int i=0;i<10;i++){
        cout<<"Arreglo 1."<<i+1<<" : ";
        cin >> arg1[i];
    }
    cout <<"Segundo arreglo.- Ingrese 10 numeros:\n";
    for (int i=0;i<10;i++){
        cout<<"Arreglo 2."<<i+1<<" : ";
        cin >> arg2[i];
    }
    for (int i=0;i<10;i++){
        if(arg1[i]==arg2[i]){
            iguales++;
        }
    }  
    cout<< "Elementos iguales en la misma posicion: "<<iguales<<"\n";  
    return 0;
}
