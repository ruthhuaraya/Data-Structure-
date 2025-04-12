#include <iostream>
using namespace std;
double area (double radio){
    double pi=3.14;
    double r=pi*(radio*radio);
    return r;
}
int main(int argc, char const *argv[])
{
    int p;
    cout << "ingresa el radio : ";
    cin >> p;
    double a=area(p);
    cout << "el area es : "<<a;
    return 0;
}
