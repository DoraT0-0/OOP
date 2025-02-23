#include <iostream>
using namespace std;

class B{
    public: 
        B(int ab = 0): b(ab) {cout << "cstr B" << endl;}
        void show(){
            cout << "B = " << b << endl;
        }
    private:
        int b;
};

class D1: private virtual B{
    public:
        D1(int ab, int ad1 = 0): B(ab), d1(ad1) {cout << "cstr D1" << endl;}
        void show(){
            cout << "D1 = " << d1 << endl;
        }
    private:
        int d1;
};

class D2: public virtual B{
    public:
        D2(int ab, int ad2 = 0): B(ab), d2(ad2) {cout << "cnstr D2" << endl;}
        void show(){
            cout << "D2 = " << d2 << endl;
        }
    private:
        int d2;
};

class D3: protected D1{
    public:
        D3(int ab, int ad1, int ad3): D1(ab, ad1), d3(ad3){cout << "cstr D3" << endl;}
        void show(){
            cout << "D3 = " << d3 << endl; 
        }
    private:
        int d3;
};

class D4: protected virtual B, public D1, protected D2{
    public:
        D4(int ab, int ad1, int ad2, int ad4) : B(ab),D1(ad1),D2(ad2),d4(ad4){ cout << "cstr D4" << endl;}
        void show(){
            cout << "D4 = " << d4 << endl;
        }
    private:
        int d4;
};



int main(){
    //D4 ObjD4(1, 2, 3, 4);
    D3 ObjD3(1, 2, 3);
    return 0;
}