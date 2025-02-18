#include "queue.h"

int main(){

    Queue queue;

    for(int i =1; i < 5; i++){
        queue.push(i);
    }

    queue.print();
    queue.pop();
    queue.print();
    queue.push(7);
    queue.print();

    return 0;
}