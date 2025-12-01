#include <iostream>
using namespace std;

#include "fcfs.h"
#include "priority.h"
#include "sjf.h"
#include "rr.h"

int main() {

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[20], at[20], bt[20], pr[20];
    int quantum;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "\nProcess " << pid[i] << ":\n";
        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority (lower = higher): ";
        cin >> pr[i];
    }

    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF (Non-Preemptive)\n";
    cout << "3. Priority Scheduling\n";
    cout << "4. Round Robin\n";
    cout << "Enter choice: ";

    int ch;
    cin >> ch;

    switch (ch) {
        case 1:
            fcfs(pid, at, bt, n);
            break;

        case 2:
            sjf(pid, at, bt, n);
            break;

        case 3:
            priorityScheduling(pid, at, bt, pr, n);
            break;

        case 4:
            cout << "Enter Time Quantum: ";
            cin >> quantum;
            roundRobin(pid, at, bt, n, quantum);
            break;

        default:
            cout << "Invalid choice.";
    }

    return 0;
}
