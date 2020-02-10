#include <iostream>
using namespace std;

class Mother {
 public:
  virtual void MotherFoo() {}
};

class Father {
 public:
  virtual void FatherFoo() {}
};

class Child : virtual public Mother, virtual public Father {
 public:
  virtual void ChildFoo(){}
};

int main() {

    cout<<sizeof(Mother)<<endl;
    cout<<sizeof(Father)<<endl;
    cout<<sizeof(Child)<<endl;
    cout<<sizeof(long)<<endl;
    return 0;   
}