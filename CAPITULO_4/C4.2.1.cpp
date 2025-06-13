#include <bits/stdc++.h>
using namespace std;

struct Event {
    int tiempo;
    int type;

    bool operator<(const Event& e) const {
        if (tiempo == e.tiempo)
            return type < e.type; 
        return tiempo < e.tiempo;
    }
};

int maxSimultaneousCustomers(const vector<pair<int, int>>& tiempos) {
    vector<Event> events;

    for (auto& t : tiempos) {
        events.push_back({t.first, +1});  
        events.push_back({t.second, -1}); 
    }

    sort(events.begin(), events.end());

    int current = 0;
    int maxCustomers = 0;

    for (auto& e : events) {
        current += e.type;
        maxCustomers = max(maxCustomers, current);
    }

    return maxCustomers;
}

int main() {
    vector<pair<int, int>> customers = {
        {1, 5},  // A
        {2, 6},  // B
        {4, 7},  // C
        {5, 8}   // D
    };

    int result = maxSimultaneousCustomers(customers);

    cout << "Maximo numero de clientes simultaneos: " << result << endl;

    return 0;
}