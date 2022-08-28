#include <iostream>
using namespace std;
 
int main(){
    int refString[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int frame[4] = {7,0,1,2};

    int pageMiss = 4;
    int pageHit = 0;

    int count = 0;
    int index;

    bool hit = false;
    

    for(int i = 4 ; i < 20 ; i++){
    bool match[4] = {false};
        for(int j = 0 ; j < 4 ; j++){
            if(refString[i]==frame[j]){
                pageHit++;
                hit = true;
                break;
            }
            
        }

        if(hit == false){
            for(int j = i-1 ; j >=0 ; j--){
                for(int k = 0 ; k < 4 ; k++){
                    
                    if((refString[j]==frame[k]) && (match[k] == false)){
                        count++;
                        index = k;
                        match[k] = true;
                        break;
                    }

                    

                }
                if(count == 4){
                        frame[index] = refString[i];
                        pageMiss++;
                        hit = true;
                        break;
                }
                if(hit == true) break;
            }
        }

        hit = false;
        count = 0;
        
      

    }

    cout<<"Page Miss : "<<pageMiss<<" Page Hit : "<<pageHit;
}