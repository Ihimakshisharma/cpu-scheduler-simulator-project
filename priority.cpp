#include <iostream>
#include "priority.h"
using namespace std;

void priorityScheduling(int pid[], int at[], int bt[], int pr[], int n) {

    if (n <= 0) {
        cout << "No processes to schedule.\n";
        return;
    }
    if (n > 20) n = 20;

    for (int i = 0; i < n; i++) {
        if (at[i] < 0) at[i] = 0;
        if (bt[i] < 0) bt[i] = 0;
    }

    int ct[20], tat[20], wt[20];
    bool done[20];
    for (int i = 0; i < n; i++) done[i] = false;

    int time = 0;
    int completed = 0;
    int gantt_pid[40];
    int gantt_end[40];
    int gcount = 0;

    while (completed < n) {

        int idx = -1;
        int bestP = 1000000;

        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time) {
                if (pr[i] < bestP) {
                    bestP = pr[i];
                    idx = i;
                } else if (pr[i] == bestP) {
                    if (pid[i] < pid[idx]) idx = i;
                }
            }
        }

        if (idx == -1) {
            int nextArrival = 1000000;
            for (int i = 0; i < n; i++) if (!done[i]) if (at[i] < nextArrival) nextArrival = at[i];
            if (nextArrival > time) {
                gantt_pid[gcount] = 0;
                time = nextArrival;
                gantt_end[gcount] = time;
                gcount++;
            }
            continue;
        }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = true;
        completed++;

        gantt_pid[gcount] = pid[idx];
        gantt_end[gcount] = time;
        gcount++;
    }

    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\t\n";
    }

    cout << "\nGantt Chart:\n";
    cout << " ";
    for (int i = 0; i < gcount; i++) cout << "----";
    cout << "\n|";
    for (int i = 0; i < gcount; i++) {
        if (gantt_pid[i] == 0) cout << " idle |";
        else {
            cout << " P" << gantt_pid[i] << " ";
            if (gantt_pid[i] < 10) cout << " |";
            else cout << "|";
        }
    }
    cout << "\n ";
    for (int i = 0; i < gcount; i++) cout << "----";

    cout << "\n0";
    for (int i = 0; i < gcount; i++) {
        int t = gantt_end[i];
        if (t < 10) cout << "   " << t;
        else if (t < 100) cout << "  " << t;
        else cout << " " << t;
    }
    cout << "\n";
}
