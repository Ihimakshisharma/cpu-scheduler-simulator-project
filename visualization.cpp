#include <iostream>
#include "visualization.h"
using namespace std;

void drawTable(int pid[], int at[], int bt[], int ct[], int tat[], int wt[], int n) {
    cout << "\n--------------------------------------------\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\t\n";
    }
    cout << "--------------------------------------------\n";
}

void drawGantt(int pid[], int end[], int count) {
    cout << "\nGANTT CHART (Visualization Module)\n";
    cout << " ";

    for (int i = 0; i < count; i++) cout << "------";
    cout << "\n|";

    for (int i = 0; i < count; i++) {
        if (pid[i] == 0) cout << " IDLE |";
        else cout << " P" << pid[i] << "  |";
    }

    cout << "\n ";
    for (int i = 0; i < count; i++) cout << "------";

    cout << "\n0";
    for (int i = 0; i < count; i++) {
        int t = end[i];
        if (t < 10) cout << "     " << t;
        else if (t < 100) cout << "    " << t;
        else cout << "   " << t;
    }
    cout << "\n";
}
