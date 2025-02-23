#include <iostream>
#include <string>
using namespace std;

class Flora{
    public:
        virtual void print() = 0;
};

class Tree : public Flora{
    public:
        Tree(string atype, int aage): type(atype), age(aage){}
        void print() override {
            cout << "class Tree: [" << "type: " << type << ", age: " << age << "]" << endl;
        }
    private:
        string type;
        int age;
};

class Shrub : public Flora{
    public:
        Shrub(string atype, int aisFruit): type(atype), isFruit(aisFruit){}
        void print() override {
            cout << "class Shrub: [" << "type: " << type << ", isFruit: " << isFruit << "]" << endl;
        }
    private:
        string type;
        bool isFruit;
};

class Grass: public Flora {
    public:
        Grass(string atype, int aisHeal): type(atype), isHeal(aisHeal){}
        void print() override {
            cout << "class Grass: [" << "type: " << type << ", isHeal: " << isHeal << "]" << endl;
        }
    private:
        string type;
        bool isHeal;
};


int main() {

    Flora *_flora[3];

    _flora[0] = new Tree("tree1", 7);
    _flora[1] = new Shrub("shrub1", true);
    _flora[2] = new Grass("grass1", false);
    

    for(int i = 0;i < 3; i++){
        _flora[i]->print();
    }

    return 0;
}