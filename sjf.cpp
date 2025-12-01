#include <iostream>
#include "sjf.h"
using namespace std;

void sjf(int pid[], int at[], int bt[], int n) {

    if (n <= 0) {
        cout << "No processes.\n";
        return;
    }
    if (n > 20) n = 20;

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
        int bestBT = 1000000;

        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time) {
                if (bt[i] < bestBT) {
                    bestBT = bt[i];
                    idx = i;
                } else if (bt[i] == bestBT) {
                    if (pid[i] < pid[idx]) idx = i;
                }
            }
        }

        if (idx == -1) {
            int nextArrival = 1000000;
            for (int i = 0; i < n; i++)
                if (!done[i] && at[i] < nextArrival)
                    nextArrival = at[i];

            gantt_pid[gcount] = 0;
            time = nextArrival;
            gantt_end[gcount] = time;
            gcount++;
            continue;
        }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        gantt_pid[gcount] = pid[idx];
        gantt_end[gcount] = time;
        gcount++;

        done[idx] = true;
        completed++;
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" 
             << at[i] << "\t" 
             << bt[i] << "\t" 
             << ct[i] << "\t" 
             << tat[i] << "\t" 
             << wt[i] << "\t\n";
    }

    cout << "\nGantt Chart:\n ";
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
