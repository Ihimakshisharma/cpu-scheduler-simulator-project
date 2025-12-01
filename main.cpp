#include <iostream>
#include "fcfs.h"
#include "priority.h"
#include "sjf.h"
#include "rr.h"
using namespace std;

int main() {

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[20], at[20], bt[20], pr[20];
    
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time for P" << i+1 << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for P" << i+1 << ": ";
        cin >> bt[i];
        cout << "Enter Priority for P" << i+1 << ": ";
        cin >> pr[i];
    }

    cout << "\nChoose Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF (Non-Preemptive)\n";
    cout << "3. Priority Scheduling\n";
    cout << "4. Round Robin\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        fcfs(pid, at, bt, n);
    }
    else if (choice == 2) {
        sjf(pid, at, bt, n);
    }
    else if (choice == 3) {
        priorityScheduling(pid, at, bt, pr, n);
    }
    else if (choice == 4) {
        int q;
        cout << "Enter Time Quantum: ";
        cin >> q;
        roundRobin(pid, at, bt, n, q);
    }
    else {
        cout << "Invalid option selected.";
    }

    return 0;
}

