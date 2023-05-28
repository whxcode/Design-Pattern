/*************************************************************************
> File Name: 01-concept/02_segregation.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 11:27:31 2023
 ************************************************************************/

#include<iostream>
using namespace std;

class Operation1 {
  public:
    virtual void op1() = 0;
};

class Operation2 {
  public:
    virtual void op2() = 0;
    virtual void op3() = 0;
};

class Operation3 {
  public:
    virtual void op4() = 0;
    virtual void op5() = 0;
};

class B :public Operation1,public Operation2 {
  public:
    void op1() override {
      cout << "Op 1 B()" << endl;
    }

    void op2() override {
      cout << "Op 2 B()" << endl;
    }

    void op3() override {
      cout << "Op 3 B()" << endl;
    }
};

class C :public Operation1,public Operation3 {
  public:
    void op1() override {
      cout << "Op 1 C()" << endl;
    }

    void op4() override {
      cout << "Op 4 C()" << endl;
    }

    void op5() override {
      cout << "Op 5 C()" << endl;
    }
};

class A {
  public:
    void run1(Operation1 &c) {
      c.op1();
    }
    
    void run2(Operation2 &c) {
      c.op2();
      c.op3();
    }

};

class D {
  public:
    void run1(Operation1 &c) {
      c.op1();
    }

    void run2(Operation3 &c) {
      c.op4();
      c.op5();
    }
};


int main(){
   B b;
   C c;
  
   A a;
  D d;

  a.run1(b);
  a.run2(b);

  cout << endl;
  d.run1(b);
  d.run2(c);

return 0;
}
