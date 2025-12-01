#include <iostream>
#include "fcfs.h"
using namespace std;

void fcfs(int pid[], int at[], int bt[], int n) {

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

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {

                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    int time = 0;
    int gantt_pid[40];
    int gantt_end[40];
    int gcount = 0;
    int total_tat = 0;
    int total_wt = 0;

    for (int i = 0; i < n; i++) {

        if (time < at[i]) {
            gantt_pid[gcount] = 0;
            time = at[i];
            gantt_end[gcount] = time;
            gcount++;
        }

        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];

        gantt_pid[gcount] = pid[i];
        gantt_end[gcount] = time;
        gcount++;
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

    double avg_tat = (double)total_tat / n;
    double avg_wt = (double)total_wt / n;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\nAverage Turnaround Time: " << avg_tat << "\n";
    cout << "Average Waiting Time: " << avg_wt << "\n";
}
