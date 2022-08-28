#include <iostream>
using namespace std;

int buffer[100];
    int in = 0 , out = 0 ;
    int mutex = 1 ;
    int full = 0,empty = 100;
    int bufferSize = 0;
    int x = 0;

int wait(int i){
    return --i;
}
int signal(int i){
    return ++i;
}

void produce(){
    bufferSize++;
    mutex = wait(mutex);
    buffer[in] = ++x;
    full = signal(full);
    empty = wait(empty);
    in = (in+1)%100;
    cout<<"Produced : "<<x;
    mutex = signal(mutex);
}

void consumer(){
    bufferSize--;
    mutex = wait(mutex);
    
    full = wait(full);
    empty = signal(empty);
    out = (out+1)%100;
    cout<<"Produced : "<<x;
    x--;
    mutex = signal(mutex);
}
 
int main(){

    int choice;

    cout<<"Enter :\n";
    cout<<"\t 1. Produce\n";
    cout<<"\t 2. Consume\n";
    cout<<"\t 3. Show Buffer\n";
    cout<<"\t 4. Exit\n";

    while(true){
        cin>>choice;
        switch (choice)
        {
        case 1:
            if((mutex == 1)&&(empty!=0)){
                produce();
            }else{
                cout<<"Buffer is full\n";
            }
            break;
        case 2:
            if((mutex == 1)&&(full!=0)){
                consumer();
            }else{
                cout<<"Buffer is empty\n";
            }
            break;
        case 3:
            for(int i = out ; i<bufferSize;i++){
                cout<<buffer[i]<<" ";
            }
            break;
        case 4:
            return 0;
            
        }
    }
    
}