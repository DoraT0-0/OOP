#ifndef queue_H
#define queue_H


class Queue{
    public:
        Queue();
        ~Queue();

        void push(int);
        void pop();

        int size();
        int front();
        int back();
        void print();

    private:
        int *queue;
        int head, tail;
        const int size_queue = 100;
};


#endif