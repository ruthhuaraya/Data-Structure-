#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int x;
    cout << "ingresa nota del alumno : ";
    cin >> x;
    if (x>=11){
        cout << "alumno aprobado"<< endl;
    }
    else {
        cout << "alumno desaprobado"<<endl;
    }
    return 0;
}
