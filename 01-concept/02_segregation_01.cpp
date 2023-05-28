/*************************************************************************
> File Name: 01-concept/02_segregation.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 11:27:31 2023
 ************************************************************************/

#include<iostream>
using namespace std;

class Operation {
  public:
    virtual void op1() = 0;
    virtual void op2() = 0;
    virtual void op3() = 0;
    virtual void op4() = 0;
    virtual void op5() = 0;
};

class B :public Operation {
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

    void op4() override {
      cout << "Op 4 B()" << endl;
    }

    void op5() override {
      cout << "Op 5 B()" << endl;
    }
};

class C :public Operation {
  public:
    void op1() override {
      cout << "Op 1 C()" << endl;
    }

    void op2() override {
      cout << "Op 2 C()" << endl;
    }

    void op3() override {
      cout << "Op 3 C()" << endl;
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
    void run(Operation &c) {
      c.op1();
      c.op2();
    }

};

class D {
  public:
    void run(Operation &c) {
      c.op3();
      c.op4();
      c.op5();
    }
};


int main(){
   B b;
   C c;
  
   A a;
  D d;

  a.run(b);
  a.run(c);

  cout << endl;
  d.run(b);
  d.run(c);
return 0;
}
