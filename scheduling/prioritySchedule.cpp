/*
Main thing in the priority scheduling is the sorting of the processes for the scheduling according to the priority..
*/
#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid; // process id
    int bt; // burst time
    int priority; 
};

bool comparison(Process a,Process b)
{
    return (a.priority>b.priority); // is it True or False
}

void findWaitingTime(Process proc[],int n, int wt[])  // the time required for the process to be executed for the first time == burst time of i-1 th process + waittime[i-1]
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++) 
        wt[i] =  proc[i-1].bt + wt[i-1] ; 
}

void findTurnAroundTime( Process proc[], int n,int wt[], int tat[])  // time required for the process to finidh its execution
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i]; 
}

void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function to find waiting time of all processes 
    findWaitingTime(proc, n, wt); 
  
    //Function to find turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    //Display processes along with all details 
    cout << "\nProcesses  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << proc[i].pid << "\t\t"<< proc[i].bt << "\t    " << wt[i] 
             << "\t\t  " << tat[i] <<endl; 
    } 
    cout << "\nAverage waiting time = "<< (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 

void priorityScheduling(Process proc[], int n) 
{ 
    // Sort processes by priority 
    sort(proc, proc + n, comparison); // third operator is used in the case of the  we have to sort but dont have correct method
  
    cout<< "Order in which processes gets executed \n"; 
    for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].pid <<" " ; 
  
    findavgTime(proc, n); 
} 

int main() 
{ 
    cout<<"higher priority gets executed first\n";
    Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1},{4,6,4}}; 
    int n = sizeof proc / sizeof proc[0]; 
    priorityScheduling(proc, n); 
    return 0; 
}