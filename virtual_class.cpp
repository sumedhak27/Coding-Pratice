#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

class A {
    public: 
    static int count;
        A() {
            count++;
            cout<<"A const called "<<endl;
        }
        ~A() {
            cout<<"A dis called"<<endl;
        }
};

int A :: count = 0;

class B : virtual public A {

    public :
        B() {
            count++;
            cout<<"B const called "<<endl;
        }
        ~B() {
            cout<<"B dis called"<<endl;
        }
};

int main() {
    // A a;
    // B b;
    // cout<<A::count;

    vector<int> v = {10,10,10,20,20,20,30,30};
    cout<<*upper_bound(all(v), 25);


    return 0;
}