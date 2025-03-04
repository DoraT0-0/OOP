#ifndef queue_H
#define queue_H
#include <string>
#include <iostream>
using namespace std;

template<class T>
class Queue{
    public:
        Queue()
        {
            queue = new T[size_queue];
            head = tail = 0;
        }
        
        ~Queue()
        {
            delete[] queue;
        }
        
        void print(){
            for(int i = head+1;i <tail+1;i++){
                cout << " " << queue[i]; 
            }
        }
        
        void push(T n){
            if (tail+1 == head || (tail+1 == size_queue && !head)){
                cout << "очередь полна" << endl;
                return;
            }
            tail++;
            if (tail == size_queue) tail = 0;
            queue[tail] = n;
        }
        
        void pop(){
            if(head == tail) {
                cout << "Очередь пуста" << endl;
            }else{
            head++;
            if(head == size_queue) head = 0;
            }
        }
        
        int size(){
            return tail-head-1;
        }
        
        T front(){
            return queue[head+1];
        }
        
        
        T back(){
            return queue[tail];
        }
        

    private:
        T *queue;
        int head, tail;
        const int size_queue = 100;
};


#endif