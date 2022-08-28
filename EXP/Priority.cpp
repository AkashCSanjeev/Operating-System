#include <iostream>
using namespace std;

class Process{
    public:
    int arrivalTime;
    int burstTime;
    int priority;

    public:
    Process(int arrivalTime,int burstTime,int priority){
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->priority = priority;
    }

    Process(){}

};
 
int main(){

    Process p1(0,5,10);
    Process p2(1,4,20);
    Process p3(2,2,30);
    Process p4(4,1,40);

    Process p[] = {p1,p2,p3,p4};
    bool processDone[4] = {false};
    int bt[4] = {5,4,2,1};
    int remainingProcess = 4;
    int count = 0;
    int totalCompTime = 0;

    int ct[4] = {0};
    int tat[4];
    int wt[4];


    while(remainingProcess>0){

        int max = 0;

        for(int i = 0 ; i< 4; i++){
            if(processDone[max] == true) max++;

            if((p[max].priority<p[i].priority) && (processDone[i] ==false)){
                if(p[i].arrivalTime<= count)
                    max = i;
            }else if((p[max].priority==p[i].priority) && (processDone[i] == false)){
                if(p[max].arrivalTime>p[i].arrivalTime){
                    max = i;
                }
            }
        }

        if((p[max].arrivalTime <= count) && bt[max]>0){
            bt[max]--;
            ct[max] = totalCompTime + 1;
            totalCompTime++;
            count++;
            if(bt[max] == 0){
                processDone[max] = true;
                tat[max] = ct[max] - p[max].arrivalTime;
                wt[max] = tat[max] - p[max].burstTime;
                remainingProcess--;
            } 
            
        }else{
            count++;
            totalCompTime++;
        }


    }

     for(int i = 0 ; i < 4 ;i++)
        cout<<(i+1)<<" "<<p[i].burstTime<<" "<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;



}