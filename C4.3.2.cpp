#include <bits/stdc++.h>
using namespace std;
// Función que verifica si se pueden procesar al menos k trabajos en tiempo x
bool valid(long long x, const vector<int>& times, int k) {
    long long total = 0;
    for (int t : times) {
        total += x / t;
        if (total >= k) return true; // ya es suficiente
    }
    return false;
}

// Búsqueda binaria sobre la respuesta
long long minTimeToProcessJobs(const vector<int>& times, int k) {
    long long low = 0;
    long long high = 1LL * *min_element(times.begin(), times.end()) * k; // z seguro válido
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (valid(mid, times, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    // Ejemplo: 3 máquinas con tiempos p1=2, p2=3, p3=7 y 8 trabajos
    vector<int> processingTimes = {2, 3, 7};
    int k = 8;

    long long result = minTimeToProcessJobs(processingTimes, k);

    cout << "Tiempo minimo necesario para procesar " << k << " trabajos: " << result << " unidades de tiempo." << endl;

    return 0;
}