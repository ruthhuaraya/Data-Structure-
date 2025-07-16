#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n[20],f[20]={0};
    cout << "Ingrese 20 numeros:\n";
    for (int i =0 ;i<20;i++){
        cout <<"Numero "<<i+1<<": ";
        cin >>n[i];
    }
    cout <<"\nFrecuencia de cada numero:\n";
    for(int i;i<20;i++){
        double c=false;
        for(int j=0;j<i;j++){
            if (n[i]==n[j]){
                c=true;
                break;
            }
        }
        if (!c){
            int contador=0;
            for (int k=0;k<20;k++){
                if (n[k]==n[i])contador++;
            }
            cout <<"El numero "<<n[i]<<" se repite " <<contador<<" ocasiones.\n";
        }
    }
    return 0;
}
