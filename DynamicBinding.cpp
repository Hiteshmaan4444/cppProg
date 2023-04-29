#include<iostream>
using namespace std;

class A{
public:
    virtual void show(){cout<<"Class A";}
};
class B: public A{
    void show(){cout<<"Class B";}
};
int main(){
    B a;
    A &obj=a;
    obj.show();
}

