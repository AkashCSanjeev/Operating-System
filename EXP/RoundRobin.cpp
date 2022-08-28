#include <iostream>

using namespace std;
 
class Process{
    public:
    int arrivalTime;
    int burstTime;
    int runningBurstTime;
    int complitionTime = 0;
    int tatTime = 0;

    public:
    Process(int arrivalTime,int burstTime){
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        runningBurstTime = burstTime;
        
    }

    Process(){}

};
 
int main(){

    Process p1(0,5);
    Process p2(1,3);
    Process p3(2,1);
    Process p4(4,4);
    Process p[] = {p1,p2,p3,p4};

    Process queue[4];
    bool inQueue[4] = {false};
    int addC=0,removeC=0;
    
    int count = 0;
    int timeQuantam = 2;
    
  
    Process running;
    bool allocated = false;

    while(1){

       for(int i = 0 ; i < 4 ;i++){
        if((p[i].arrivalTime<=count)&&(inQueue[i] == false)){
            queue[addC%4] = p[i];
            addC++;
            inQueue[i] = true;
        }
       }

       if(count % timeQuantam == 0){
        running = queue[removeC%4];
        if(running.runningBurstTime>= timeQuantam){

        if(allocated == false){
            
            removeC++;
            allocated = true;
        }else{
            queue[addC%4] = running;
            addC++;
            allocated = false;
            running.runningBurstTime = running.runningBurstTime - timeQuantam;
        }
        }else{

        }

       }


    }

    

    for(int i = 0 ; i < 4 ;i++){
        cout<<(i+1)<<" "<<p[i].burstTime<<" "<<p[i].tatTime<<endl;
    }


} 