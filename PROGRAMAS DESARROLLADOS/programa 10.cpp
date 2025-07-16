#include <iostream>
#include <string>
using namespace std;

// Estructuras
struct Lapicero {
    string tipo_punta, color, marca;
    float precio;
};

struct Carpeta {
    string tamano, color, marca;
    int anillos;
};

struct Mochila {
    string tamano, color, marca;
    float capacidad;
};

struct Lenguaje {
    string nombre, tipo, anio;
    bool orientado_objetos;
};

struct Laptop {
    string marca, procesador, ram;
    float precio;
};

struct ServidorWeb {
    string sistema_operativo, lenguaje, servidor;
    bool en_produccion;
};

struct USB {
    string marca, tipo;
    int capacidad;
    bool es_3_0;
};

struct CableUTP {
    string categoria, longitud;
    bool blindado;
    string color;
};

void imprimirLapiceros() {
    const int tamano = 3;
    Lapicero lista[tamano] = {
        {"fina", "negro", "artesco", 1.0},
        {"roma", "roja", "pailot", 5.0},
        {"roma", "azul", "layconsa", 2.0}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "Lapicero " << i + 1 << ":\n"
             << "  Tipo de punta: " << lista[i].tipo_punta << "\n"
             << "  Color: " << lista[i].color << "\n"
             << "  Marca: " << lista[i].marca << "\n"
             << "  Precio: " << lista[i].precio << " soles\n\n";
    }
}

void imprimirCarpetas() {
    const int tamano = 3;
    Carpeta lista[tamano] = {
        {"A4", "rojo", "Standford", 3},
        {"Oficio", "azul", "Artesco", 2},
        {"A5", "verde", "Layconsa", 4}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "Carpeta " << i + 1 << ":\n"
             << "  Dimension: " << lista[i].tamano << "\n"
             << "  Color: " << lista[i].color << "\n"
             << "  Marca: " << lista[i].marca << "\n"
             << "  Anillos: " << lista[i].anillos << "\n\n";
    }
}

void imprimirMochilas() {
    const int tamano = 3;
    Mochila lista[tamano] = {
        {"Grande", "negra", "Nike", 30.0},
        {"Mediana", "roja", "Adidas", 20.5},
        {"Pequeña", "azul", "Reebok", 15.0}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "Mochila " << i + 1 << ":\n"
             << "  Dimension: " << lista[i].tamano << "\n"
             << "  Color: " << lista[i].color << "\n"
             << "  Marca: " << lista[i].marca << "\n"
             << "  Capacidad: " << lista[i].capacidad << " L\n\n";
    }
}

void imprimirLenguajes() {
    const int tamano = 3;
    Lenguaje lista[tamano] = {
        {"C++", "Compilado", "1985", true},
        {"Python", "Interpretado", "1991", true},
        {"Assembly", "Bajo nivel", "1950", false}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "Lenguaje " << i + 1 << ":\n"
             << "  Nombre: " << lista[i].nombre << "\n"
             << "  Tipo: " << lista[i].tipo << "\n"
             << "  Periodo: " << lista[i].anio << "\n"
             << "  Orientado a objetos : " << (lista[i].orientado_objetos ? "Si" : "No") << "\n\n";
    }
}

void imprimirLaptops() {
    const int tamano = 3;
    Laptop lista[tamano] = {
        {"HP", "i5", "8GB", 2500},
        {"Dell", "i7", "16GB", 3200},
        {"Asus", "Ryzen 5", "8GB", 2800}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "Laptop " << i + 1 << ":\n"
             << "  Marca: " << lista[i].marca << "\n"
             << "  Procesador: " << lista[i].procesador << "\n"
             << "  RAM: " << lista[i].ram << "\n"
             << "  Precio: S/" << lista[i].precio << "\n\n";
    }
}

void imprimirServidores() {
    const int tamano = 3;
    ServidorWeb lista[tamano] = {
        {"Linux", "PHP", "Apache", true},
        {"Windows", "ASP.NET", "IIS", true},
        {"Linux", "Python", "Nginx", false}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "Servidor Web " << i + 1 << ":\n"
             << "  SO: " << lista[i].sistema_operativo << "\n"
             << "  Lenguaje: " << lista[i].lenguaje << "\n"
             << "  Servidor: " << lista[i].servidor << "\n"
             << "  En produccion: " << (lista[i].en_produccion ? "Si" : "No") << "\n\n";
    }
}

void imprimirUSBs() {
    const int tamano = 3;
    USB lista[tamano] = {
        {"Kingston", "USB-A", 32, true},
        {"SanDisk", "USB-C", 64, true},
        {"HP", "USB-A", 16, false}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "USB " << i + 1 << ":\n"
             << "  Marca: " << lista[i].marca << "\n"
             << "  Tipo: " << lista[i].tipo << "\n"
             << "  Capacidad: " << lista[i].capacidad << " GB\n"
             << "  3.0: " << (lista[i].es_3_0 ? "Si" : "No") << "\n\n";
    }
}

void imprimirCables() {
    const int tamano = 3;
    CableUTP lista[tamano] = {
        {"Cat5", "1m", false, "Gris"},
        {"Cat6", "3m", true, "Azul"},
        {"Cat7", "5m", true, "Negro"}
    };
    for (int i = 0; i < tamano; ++i) {
        cout << "Cable UTP " << i + 1 << ":\n"
             << "  Categoria: " << lista[i].categoria << "\n"
             << "  Longitud: " << lista[i].longitud << "\n"
             << "  Blindado: " << (lista[i].blindado ? "Si" : "No") << "\n"
             << "  Color: " << lista[i].color << "\n\n";
    }
}

// Menú principal
int main() {
    int opcion;

    cout << "Seleccione una estructura:\n";
    cout << "1. Lapicero\n2. Carpeta\n3. Mochila\n4. Lenguaje\n5. Laptop\n";
    cout << "6. Servidor Web\n7. USB\n8. Cable UTP\n";
    cout << "Ingrese una opcion entre 1 y 8: ";
    cin >> opcion;
    cout << "\n";

    if (cin.fail() || opcion < 1 || opcion > 8) {
        cout << "Opción no valida. Por favor ingrese un numero entre 1 y 8.\n";
        return 1; // Salir con error si la entrada no es válida
    }

    switch (opcion) {
        case 1: imprimirLapiceros(); break;
        case 2: imprimirCarpetas(); break;
        case 3: imprimirMochilas(); break;
        case 4: imprimirLenguajes(); break;
        case 5: imprimirLaptops(); break;
        case 6: imprimirServidores(); break;
        case 7: imprimirUSBs(); break;
        case 8: imprimirCables(); break;
    }

    return 0;
}
