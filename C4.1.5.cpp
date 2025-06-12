#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

bool compByLength(const string& a, const string& b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void printVector(const vector<int>& v) {
    for (int num : v) cout << num << " ";
    cout << "\n";
}

int main() {
    vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    sort(v.begin(), v.end());
    cout << "1. Vector ordenado ascendente: ";
    printVector(v);

    sort(v.rbegin(), v.rend());
    cout << "2. Vector ordenado descendente: ";
    printVector(v);

    int a[] = {4, 2, 5, 3, 5, 8, 3};
    int n = 7;
    sort(a, a + n);
    cout << "3. Array ordenado: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    string s = "monkey";
    sort(s.begin(), s.end());
    cout << "4. String ordenado: " << s << "\n";

    vector<pair<int, int>> pairs = {{1, 5}, {2, 3}, {1, 2}};
    sort(pairs.begin(), pairs.end());
    cout << "5. Pares ordenados: ";
    for (auto& p : pairs) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";

    // 6. Vector de tuplas
    vector<tuple<int, int, int>> tuples = {{2, 1, 4}, {1, 5, 3}, {2, 1, 3}};
    sort(tuples.begin(), tuples.end());
    cout << "6. Tuplas ordenadas: ";
    for (auto& t : tuples) cout << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ") ";
    cout << "\n";

    // 7. Vector de structs
    vector<Point> points = {{3, 4}, {1, 7}, {3, 2}, {2, 5}};
    sort(points.begin(), points.end());
    cout << "7. Structs ordenados (Point): ";
    for (auto& p : points) cout << "(" << p.x << "," << p.y << ") ";
    cout << "\n";

    // 8. Vector<string> con comparación personalizada
    vector<string> words = {"pear", "apple", "fig", "banana", "kiwi"};
    sort(words.begin(), words.end(), compByLength);
    cout << "8. Strings ordenados por longitud: ";
    for (const string& w : words) cout << w << " ";
    cout << "\n";

    return 0;
}
