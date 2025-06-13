//C2:P3 2.2.2
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> permutation;
vector<bool> chosen;

void search() {
    if (permutation.size() == n) {
        for (int x : permutation) cout << x << " ";
        cout << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    cin >> n;
    chosen.assign(n + 1, false);
    search();
    return 0;
}