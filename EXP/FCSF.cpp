#include <iostream>
using namespace std;
 
int main(){
    int numProcess;
    cout<<"Enter Num of process: ";
    cin>> numProcess;

    int bt[numProcess];
    int at[numProcess];
    int ct[numProcess];
    int tat[numProcess];
    int wt[numProcess];

    cout<<"Enter Burst Time: ";
    for( int i = 0 ; i < numProcess;i++)
        cin>>bt[i];

    cout<<"Enter Arrival Time: ";
    for( int i = 0 ; i < numProcess;i++)
        cin>>at[i];

    int remainingProcess = numProcess;
    int count = 0;
    int totalCompTime = 0;
    while(remainingProcess>0){
     int minArrivalIndex = 0;
     for (int j = 0; j < numProcess; j++)
     {
        if(at[j]<at[minArrivalIndex]){
            minArrivalIndex = j;
        }
     }

     if(at[minArrivalIndex]<= count){
        ct[minArrivalIndex] = totalCompTime + bt[minArrivalIndex];
        tat[minArrivalIndex] = ct[minArrivalIndex] - at[minArrivalIndex];
        wt[minArrivalIndex] = tat[minArrivalIndex] - bt[minArrivalIndex];
        totalCompTime = ct[minArrivalIndex];
        at[minArrivalIndex] = 100;
        count = count + bt[minArrivalIndex];
        remainingProcess--;
     }else{
        count++;
        totalCompTime++;
     }

     
    }

    for(int i = 0 ; i < numProcess ;i++)
        cout<<(i+1)<<" "<<bt[i]<<" "<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;


}