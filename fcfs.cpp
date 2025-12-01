#include <iostream>
#include "fcfs.h"
using namespace std;

void fcfs(int pid[], int at[], int bt[], int n) {

    int ct[20], tat[20], wt[20];
    int time = 0;

    
    for (int i = 0; i < n; i++) {

        if (time < at[i]) {
            time = at[i]; 
        }

        time += bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
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
}
