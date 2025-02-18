#include <iostream> 
using namespace std; 
#include "queue.h"

Queue::Queue()
{
    queue = new int[size_queue];
    head = tail = 0;
}

Queue::~Queue()
{
    cout << "clear ram" << endl;
}

void Queue::print(){
    for(int i = head+1;i <tail+1;i++){
        cout << " " << queue[i]; 
    }
}

void Queue::push(int n){
    if (tail+1 == head || (tail+1 == size_queue && !head)){
        cout << "очередь полна" << endl;
        return;
    }
    tail++;
    if (tail == size_queue) tail = 0;
    queue[tail] = n;
}

void Queue::pop(){
    if(head == tail) {
        cout << "Очередь пуста" << endl;
    }else{
    head++;
    if(head == size_queue) head = 0;
    }
}

int Queue::size(){
    return tail-head-1;
}

int Queue::front(){
    return queue[head+1];
}

int Queue::back(){
    return queue[tail];
}
