#include <iostream>
using namespace std;

class A {
    char as;
    short a,b,c;
};

class B : public A {
    protected:
    int b;
};

class D : public B {
    int d = b;
    public : 
};

class C : virtual public A {

};

int main() {
    A a;
    B b;

    cout<<sizeof(A)<<endl;
    cout<<sizeof(B)<<endl;
    cout<<sizeof(C)<<endl;
    cout<<sizeof(D)<<endl;
    return 0;
}