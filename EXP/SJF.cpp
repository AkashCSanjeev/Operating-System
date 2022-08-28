#include <iostream>
using namespace std;

class Process{
    public:
    int arrivalTime;
    int burstTime;

    public:
    Process(int arrivalTime,int burstTime){
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
    }

    Process(){}

};
 
int main(){

    Process p1(1,3);
    Process p2(2,4);
    Process p3(1,2);
    Process p4(4,4);

    Process p[] = {p1,p2,p3,p4};
    bool processDone[4] = {false};

    int remainingProcess = 4;
    int count = 0;
    int totalCompTime = 0 ;

    int ct[4];
    int tat[4];
    int wt[4];

    while(remainingProcess>0){

        int min = 0;

        for(int i = 0 ; i < 4 ; i ++){
            if(processDone[min] == true) min++;
            if((p[min].burstTime>p[i].burstTime) && (processDone[i] == false)){

                min = i;
            }else if((p[min].burstTime==p[i].burstTime) && (processDone[i] == false)){
                if(p[min].arrivalTime>p[i].arrivalTime){
                    min = i;
                }
            }
        }

        if((p[min].arrivalTime <= count)){
            processDone[min] = true;
            ct[min] = totalCompTime + p[min].burstTime;
            tat[min] = ct[min] - p[min].arrivalTime;
            wt[min] = tat[min] - p[min].burstTime;
            totalCompTime = ct[min];
            count = count + p[min].burstTime;
            remainingProcess--;
        }else{
            count++;
            totalCompTime++;
        }

    }

     for(int i = 0 ; i < 4 ;i++)
        cout<<(i+1)<<" "<<p[i].burstTime<<" "<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;


}