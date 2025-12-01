#include <iostream>
#include "roundrobin.h"
using namespace std;

void roundRobin(int pid[], int at[], int bt[], int n, int quantum) {

    if (n <= 0) {
        cout << "No processes to schedule.\n";
        return;
    }
    if (n > 20) n = 20;
    if (quantum <= 0) quantum = 1;

    int rem_bt[20];
    bool finished[20];
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
        finished[i] = false;
        if (at[i] < 0) at[i] = 0;
        if (rem_bt[i] < 0) rem_bt[i] = 0;
    }

    int ct[20], tat[20], wt[20];
    int time = 0;
    int completed = 0;

    int q[200];
    int front = 0, back = 0;
    bool inQueue[20];
    for (int i = 0; i < n; i++) inQueue[i] = false;

    for (int i = 0; i < n; i++) {
        if (at[i] <= time && !inQueue[i]) {
            q[back++] = i;
            inQueue[i] = true;
            if (back >= 200) back = 0;
        }
    }

    int gantt_pid[400];
    int gantt_end[400];
    int gcount = 0;

    int lastPid = -1;
    int total_tat = 0;
    int total_wt = 0;
    int total_idle = 0;

    while (completed < n) {

        if (front == back) {
            int nextArrival = 1000000;
            for (int i = 0; i < n; i++) if (!finished[i]) if (at[i] < nextArrival) nextArrival = at[i];
            if (nextArrival > time) {
                total_idle += (nextArrival - time);
                gantt_pid[gcount] = 0;
                time = nextArrival;
                gantt_end[gcount] = time;
                gcount++;
            }
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && !inQueue[i] && !finished[i]) {
                    q[back++] = i;
                    inQueue[i] = true;
                    if (back >= 200) back = 0;
                }
            }
            continue;
        }

        int idx = q[front++];
        if (front >= 200) front = 0;
        inQueue[idx] = false;

        int slice = (rem_bt[idx] > quantum) ? quantum : rem_bt[idx];
        rem_bt[idx] -= slice;
        time += slice;

        for (int i = 0; i < n; i++) {
            if (!finished[i] && !inQueue[i] && at[i] <= time && i != idx) {
                q[back++] = i;
                inQueue[i] = true;
                if (back >= 200) back = 0;
            }
        }

        if (rem_bt[idx] == 0) {
            finished[idx] = true;
            ct[idx] = time;
            completed++;
        } else {
            q[back++] = idx;
            inQueue[idx] = true;
            if (back >= 200) back = 0;
        }

        if (lastPid == pid[idx]) {
            gantt_end[gcount-1] = time;
        } else {
            gantt_pid[gcount] = pid[idx];
            gantt_end[gcount] = time;
            gcount++;
            lastPid = pid[idx];
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\t\n";
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
    int makespan = ct[n - 1] - at[0];
    double throughput = 0.0;
    if (makespan > 0) throughput = (double)n / (double)makespan;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "\nAverage Turnaround Time: " << avg_tat << "\n";
    cout << "Average Waiting Time: " << avg_wt << "\n";
    cout << "Total CPU Idle Time: " << total_idle << "\n";
    cout << "Makespan: " << makespan << "\n";
    cout << "Throughput: " << throughput << "\n";
}
