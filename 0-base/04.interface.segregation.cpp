/*************************************************************************
> File Name: 0-base/04.interface.segregation.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 08时50分52秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*
struct Tools {
public:
  virtual void op1() = 0;
  virtual void op2() = 0;
  virtual void op3() = 0;
  virtual void op4() = 0;
  virtual void op5() = 0;
};

struct B : public Tools {
public:
  void op1() override { cout << "B -> 1" << endl; }
  void op2() override { cout << "B -> 2" << endl; }
  void op3() override { cout << "B -> 3" << endl; }
  void op4() override { cout << "B -> 4" << endl; }
  void op5() override { cout << "B -> 5" << endl; }
};

// A 类使用了 B 类，三个方法。但现在可以访问全部方法。
class A {
public:
  void depend1(Tools *t) { t->op1(); }
  void depend2(Tools *t) { t->op2(); }
  void depend3(Tools *t) { t->op3(); }
};

class C {
public:
  void depend3(Tools *t) { t->op3(); }
  void depend4(Tools *t) { t->op4(); }
};
*/

struct BA {
public:
  virtual void op1() = 0;
  virtual void op2() = 0;
  virtual void op3() = 0;
};

struct CD {
public:
  virtual void op4() = 0;
  virtual void op5() = 0;
};

// 将 他们拆成独立的接口。
struct Tools : public BA, CD {
public:
};

struct B : public Tools {
public:
  void op1() override { cout << "B -> 1" << endl; }
  void op2() override { cout << "B -> 2" << endl; }
  void op3() override { cout << "B -> 3" << endl; }
  void op4() override { cout << "B -> 4" << endl; }
  void op5() override { cout << "B -> 5" << endl; }
};

class A {
public:
  void depend1(BA *t) { t->op1(); }
  void depend2(BA *t) { t->op2(); }
  void depend3(BA *t) { t->op3(); }
};

class C {
public:
  void depend3(CD *t) { t->op5(); }
  void depend4(CD *t) { t->op4(); }
};

int main() {
  B *b = new B;
  A *a = new A;

  a->depend1(b);

  delete a;
  delete b;

  return 0;
}
