#include "queue.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    Queue<int> queue1;
    Queue<float> queue2;
    Queue<string> queue3;

    for(int i =1; i < 5; i++){
        queue1.push(i);
        queue2.push(i*0.1);
        queue3.push("asd");
    }
    queue1.print();

    cout << endl;

    queue2.print();
    queue2.pop();
    cout << endl <<queue2.front() << endl;
    queue2.print();
    cout << endl;

    queue3.print();
    cout << endl;

    return 0;
}