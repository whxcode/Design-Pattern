/*************************************************************************
> File Name: 01-system.cpp
> Author:
> Mail:
> Created Time: 2022年07月07日 星期四 20时38分23秒
 ************************************************************************/

#include <iostream>
using namespace std;

class SystemA {
public:
  void operatorA() { cout << "operatorA" << endl; }
};

class SystemB {
public:
  void operatorB() { cout << "operatorB" << endl; }
};

class SystemC {
public:
  void operatorC() { cout << "operatorC" << endl; }
};

class Facade {
public:
  Facade(SystemA *a, SystemB *b, SystemC *c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
  void methodOne() { this->a->operatorA(); }

  void methodTwo() {
    this->b->operatorB();
    this->c->operatorC();
  }

private:
  SystemA *a;
  SystemB *b;
  SystemC *c;
};

int main() {
  Facade *facede = new Facade(new SystemA, new SystemB, new SystemC);

  facede->methodOne();
  facede->methodTwo();
  return 0;
}
