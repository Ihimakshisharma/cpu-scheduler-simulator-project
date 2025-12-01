CPU Scheduler Simulator
This project is a simulation of basic CPU scheduling algorithms.
It was developed as part of the Operating Systems course (CSE316).
Team Members
Himakshi Sharma
Erdenejargal T

CPU Scheduler Simulator
This project is a simulation of basic CPU scheduling algorithms.
It was developed as part of the Operating Systems course (CSE316).
Team Members
Himakshi Sharma
Erdenejargal T

Algorithms Implemented
1. FCFS (First Come First Serve)
Non-preemptive
Processes are executed in order of arrival time
Includes idle CPU handling
Prints table + ASCII Gantt chart
2. SJF (Shortest Job First) – Non-Preemptive
Selects the shortest burst time among arrived processes
Breaks ties by arrival time, then PID
3. Priority Scheduling – Non-Preemptive
CPU picks the process with the highest priority (lower number = higher priority)
Handles arrival-time based selection and tie-breaking
4. Round Robin (RR)
Time-slice based
Uses a ready queue implemented with arrays

PROJECT STRUCTURE
src/
│
├── fcfs.h
├── fcfs.cpp
├── sjf.h
├── sjf.cpp
├── priority.h
├── priority.cpp
├── rr.h
├── rr.cpp
└── main.cpp

How to Use
Enter the number of processes
Enter Arrival Time and Burst Time for all processes
If using Priority Scheduling, enter Priority also
Choose the scheduling algorithm from the menu
View the table and Gantt chart in the console

How to Use
Enter the number of processes
Enter Arrival Time and Burst Time for all processes
If using Priority Scheduling, enter Priority also
Choose the scheduling algorithm from the menu
View the table and Gantt chart in the console


