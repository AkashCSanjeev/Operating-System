#include <iostream>
using namespace std;
 
int main(){
    int refString[] = {7,0,1,2,0,3,0,4,2,3,0,3,1,2,0};
    int frame[3] = {7,0,1};
    int frameC = 0;

    int pageMiss = 3;
    int pageHit = 0;
    bool hit = false;

    for(int i = 3 ; i < 15 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(refString[i]==frame[j]){
                pageHit++;
                hit = true;
                break;
            }
            
        }

        if(hit == false){
            frame[frameC%3] = refString[i];
            
            pageMiss++;
            frameC++;
            
        }

        hit = false;

        // for(int i = 2 ; i >=0 ;i--)
        //     cout<<frame[i]<<" ";
        // cout<<endl;
    }

    cout<<"Page Miss : "<<pageMiss<<" Page Hit : "<<pageHit;

}