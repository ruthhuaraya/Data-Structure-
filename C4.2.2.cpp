#include <bits/stdc++.h>
using namespace std;
struct Event {
    int start, end;
};

bool compareByEndTime(const Event& a, const Event& b) {
    return a.end < b.end;
}

int maxNonOverlappingEvents(vector<Event>& events) {
    sort(events.begin(), events.end(), compareByEndTime);

    int count = 0;
    int lastEndTime = 0;

    for (const auto& event : events) {
        if (event.start >= lastEndTime) {
            count++;
            lastEndTime = event.end;
        }
    }

    return count;
}

int main() {
    vector<Event> events = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 13},
        {12, 14}
    };

    int result = maxNonOverlappingEvents(events);
    cout << "Maximo numero de eventos sin solaparse: " << result << endl;

    return 0;
}