#include <bits/stdc++.h>
using namespace std;
struct Task {
    int duracion;
    int deadline;
    string name;

    bool operator<(const Task& t) const {
        return duracion < t.duracion;
    }
};

int maxTotalScore(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end());

    int currentTime = 0;
    int totalScore = 0;

    for (auto& task : tasks) {
        currentTime += task.duracion;
        int score = task.deadline - currentTime;
        totalScore += score;

        cout << "Tarea " << task.name << ": fin = " << currentTime
             << ", puntaje = " << score << endl;
    }

    return totalScore;
}

int main() {
    vector<Task> tasks = {
        {4, 2, "A"},
        {3, 10, "B"},
        {2, 8, "C"},
        {4, 15, "D"}
    };

    int result = maxTotalScore(tasks);

    cout << "\nPuntaje total maximo: " << result << endl;

    return 0;
}