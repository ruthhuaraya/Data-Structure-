#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <map>
#include <random>
#include <fstream>
#include <numeric>

using namespace std;
using namespace std::chrono;

class Lista {
public:
    vector<int> datos;

    void insertar(int x) { datos.push_back(x); }

    bool buscar(int x) {
        return find(datos.begin(), datos.end(), x) != datos.end();
    }

    void eliminar(int x) {
        auto it = find(datos.begin(), datos.end(), x);
        if (it != datos.end()) datos.erase(it);
    }

    void reemplazar(int viejo, int nuevoValor) {
        auto it = find(datos.begin(), datos.end(), viejo);
        if (it != datos.end()) *it = nuevoValor;
    }
};

class Cola {
    queue<int> q;
public:
    void insertar(int x) { q.push(x); }

    bool buscar(int x) {
        queue<int> copia = q;
        while (!copia.empty()) {
            if (copia.front() == x) return true;
            copia.pop();
        }
        return false;
    }

    void eliminar(int x) {
        queue<int> nueva;
        while (!q.empty()) {
            if (q.front() != x) nueva.push(q.front());
            q.pop();
        }
        q = nueva;
    }

    void reemplazar(int viejo, int nuevoValor) {
        queue<int> nueva;
        while (!q.empty()) {
            int actual = q.front(); q.pop();
            nueva.push(actual == viejo ? nuevoValor : actual);
        }
        q = nueva;
    }
};

class Pila {
    stack<int> s;
public:
    void insertar(int x) { s.push(x); }

    bool buscar(int x) {
        stack<int> copia = s;
        while (!copia.empty()) {
            if (copia.top() == x) return true;
            copia.pop();
        }
        return false;
    }

    void eliminar(int x) {
        stack<int> temporal;
        while (!s.empty()) {
            int actual = s.top(); s.pop();
            if (actual != x) temporal.push(actual);
        }
        while (!temporal.empty()) {
            s.push(temporal.top());
            temporal.pop();
        }
    }

    void reemplazar(int viejo, int nuevoValor) {
        stack<int> temporal;
        while (!s.empty()) {
            int actual = s.top(); s.pop();
            temporal.push(actual == viejo ? nuevoValor : actual);
        }
        while (!temporal.empty()) {
            s.push(temporal.top());
            temporal.pop();
        }
    }
};

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v): valor(v), izq(nullptr), der(nullptr) {}
};

class ArbolBinario {
    Nodo* raiz = nullptr;

    Nodo* insertar(Nodo* nodo, int v) {
        if (!nodo) return new Nodo(v);
        if (v < nodo->valor) nodo->izq = insertar(nodo->izq, v);
        else nodo->der = insertar(nodo->der, v);
        return nodo;
    }

    bool buscar(Nodo* nodo, int v) {
        if (!nodo) return false;
        if (v == nodo->valor) return true;
        return v < nodo->valor ? buscar(nodo->izq, v) : buscar(nodo->der, v);
    }

    Nodo* eliminar(Nodo* nodo, int v) {
        if (!nodo) return nullptr;
        if (v < nodo->valor) nodo->izq = eliminar(nodo->izq, v);
        else if (v > nodo->valor) nodo->der = eliminar(nodo->der, v);
        else {
            if (!nodo->izq) return nodo->der;
            if (!nodo->der) return nodo->izq;
            Nodo* min = nodo->der;
            while (min->izq) min = min->izq;
            nodo->valor = min->valor;
            nodo->der = eliminar(nodo->der, min->valor);
        }
        return nodo;
    }

public:
    void insertar(int v) { raiz = insertar(raiz, v); }
    bool buscar(int v) { return buscar(raiz, v); }
    void eliminar(int v) { raiz = eliminar(raiz, v); }
    void reemplazar(int viejo, int nuevo) {
        eliminar(viejo);
        insertar(nuevo);
    }
};

template <typename Estructura>
void medirTiempo(Estructura estructura, const string& nombre,
                 const vector<int>& datos, int reemplazo, int nuevo,
                 map<string, map<string, long double>>& tiempos,
                 ofstream& csv, int cantidad) {

    for (int val : datos)
        estructura.insertar(val);

    const int REP = (cantidad >= 100000) ? 1 : 10;

    auto inicio = high_resolution_clock::now();
    estructura.insertar(nuevo);
    auto fin = high_resolution_clock::now();
    long double tiempo_ins = duration<double, milli>(fin - inicio).count();
    tiempos[nombre]["Insercion"] = tiempo_ins;
    csv << cantidad << "," << nombre << ",Insercion," << tiempo_ins << "\n";

    inicio = high_resolution_clock::now();
    for (int i = 0; i < REP; ++i)
        estructura.buscar(reemplazo);
    fin = high_resolution_clock::now();
    long double tiempo_busq = duration<double, milli>(fin - inicio).count() / REP;
    tiempos[nombre]["Busqueda"] = tiempo_busq;
    csv << cantidad << "," << nombre << ",Busqueda," << tiempo_busq << "\n";

    inicio = high_resolution_clock::now();
    for (int i = 0; i < REP; ++i) {
        estructura.reemplazar(reemplazo, nuevo);
        estructura.reemplazar(nuevo, reemplazo);
    }
    fin = high_resolution_clock::now();
    long double tiempo_rep = duration<double, milli>(fin - inicio).count() / REP;
    tiempos[nombre]["Reemplazo"] = tiempo_rep;
    csv << cantidad << "," << nombre << ",Reemplazo," << tiempo_rep << "\n";

    inicio = high_resolution_clock::now();
    for (int i = 0; i < REP; ++i) {
        estructura.insertar(nuevo);
        estructura.eliminar(nuevo);
    }
    fin = high_resolution_clock::now();
    long double tiempo_eli = duration<double, milli>(fin - inicio).count() / REP;
    tiempos[nombre]["Eliminacion"] = tiempo_eli;
    csv << cantidad << "," << nombre << ",Eliminacion," << tiempo_eli << "\n";
}

void imprimirTablaTiempos(const map<string, map<string, long double>>& tiempos, int cantidad) {
    cout << "\nResultados para " << cantidad << " elementos:\n";
    cout << left << setw(15) << "Estructura"
         << right << setw(15) << "Insercion"
         << setw(15) << "Busqueda"
         << setw(15) << "Eliminacion"
         << setw(15) << "Reemplazo" << "\n";
    for (auto it = tiempos.begin(); it != tiempos.end(); ++it) {
        const string& estructura = it->first;
        const map<string, long double >& tiempos_op = it->second;
        cout << left << setw(15) << estructura;
        for (const string& op : {"Insercion", "Busqueda", "Eliminacion", "Reemplazo"}) {
            cout << right << setw(15) << fixed << setprecision(2) << tiempos_op.at(op);
        }
        cout << "\n";
    }
}

void imprimirTablaComplejidad() {
    cout << "\nTabla de Complejidades Teoricas (Big O):\n";
    cout << left << setw(15) << "Estructura"
         << setw(15) << "Insercion"
         << setw(15) << "Busqueda"
         << setw(15) << "Eliminacion"
         << setw(15) << "Reemplazo" << "\n";
    cout << setw(15) << "Lista" << setw(15) << "O(1)" << setw(15) << "O(n)" << setw(15) << "O(n)" << setw(15) << "O(n)" << "\n";
    cout << setw(15) << "Cola" << setw(15) << "O(1)" << setw(15) << "O(n)" << setw(15) << "O(n)" << setw(15) << "O(n)" << "\n";
    cout << setw(15) << "Pila" << setw(15) << "O(1)" << setw(15) << "O(n)" << setw(15) << "O(n)" << setw(15) << "O(n)" << "\n";
    cout << setw(15) << "Arbol Binario" << setw(15) << "O(log n)" << setw(15) << "O(log n)" << setw(15) << "O(log n)" << setw(15) << "O(log n)" << "\n";
}

void guardarDatosEnR(const map<int, map<string, map<string, long double >>>& registros) {
    ofstream archivo("analisis.R");

    vector<string> operaciones = {"Insercion", "Busqueda", "Eliminacion", "Reemplazo"};
    vector<string> estructuras = {"Arbol Binario", "Cola", "Lista", "Pila"};
    map<string, string> prefijoVar = {
        {"Insercion", "insert"},
        {"Busqueda", "busq"},
        {"Eliminacion", "elim"},
        {"Reemplazo", "reemp"}
    };

    for (size_t opIndex = 0; opIndex < operaciones.size(); ++opIndex) {
        string operacion = operaciones[opIndex];
        archivo << "# " << operacion << " en diferentes tamaños (Arbol, Cola, Lista, Pila)\n";

        for (map<int, map<string, map<string, long double>>>::const_iterator it = registros.begin(); it != registros.end(); ++it) {
            int tam = it->first;
            archivo << prefijoVar[operacion] << "_" << tam << " <- c(";
            for (size_t i = 0; i < estructuras.size(); ++i) {
                long double valor = it->second.at(estructuras[i]).at(operacion);
                archivo << fixed << setprecision(0) << valor;
                if (i < estructuras.size() - 1) archivo << ", ";
            }
            archivo << ")\n";
        }

        archivo << "\n";

        map<int, map<string, map<string, long double>>>::const_iterator it1 = registros.begin();
        map<int, map<string, map<string, long double>>>::const_iterator it2 = ++registros.begin();
        while (it2 != registros.end()) {
            archivo << "t.test(" << prefijoVar[operacion] << "_" << it1->first
                    << ", " << prefijoVar[operacion] << "_" << it2->first << ")\n";
            ++it1;
            ++it2;
        }

        archivo << "\n\n";
    }

    archivo.close();
}

int main() {
    vector<int> tamanos = {100, 1000, 10000, 100000, 1000000, 10000000};
    mt19937 gen(random_device{}());
    map<int, map<string, map<string, long double>>> registros;
    ofstream csv("tiempos_crudos.csv");
    csv << "Tama\u00f1o,Estructura,Operacion,Tiempo_ns\n";

    cout << "COMPARADOR AUTOMATICO DE ESTRUCTURAS\n";

    for (int cantidad : tamanos) {
        vector<int> datos(cantidad);
        iota(datos.begin(), datos.end(), 1);
        shuffle(datos.begin(), datos.end(), gen);

        int reemplazo = datos[cantidad / 2];
        int nuevo = -9999;

        map<string, map<string, long double>> tiempos;

        medirTiempo(Lista(), "Lista", datos, reemplazo, nuevo, tiempos, csv, cantidad);
        medirTiempo(Cola(), "Cola", datos, reemplazo, nuevo, tiempos, csv, cantidad);
        medirTiempo(Pila(), "Pila", datos, reemplazo, nuevo, tiempos, csv, cantidad);
        medirTiempo(ArbolBinario(), "Arbol Binario", datos, reemplazo, nuevo, tiempos, csv, cantidad);

        registros[cantidad] = tiempos;

        imprimirTablaTiempos(tiempos, cantidad);
        imprimirTablaComplejidad();
        cout << "\n------------------------------------------\n";
    }

    guardarDatosEnR(registros);
    csv.close();
    cout << "\nArchivo 'analisis.R' generado con exito para usar en RStudio.\n";
    cout << "Archivo 'tiempos_crudos.csv' generado para analisis en Excel.\n";
    return 0;
}