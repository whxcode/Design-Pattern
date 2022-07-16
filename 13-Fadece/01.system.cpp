/*************************************************************************
> File Name: 13-Fadece/01.system.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 11时07分06秒
 ************************************************************************/

#include <iostream>
using namespace std;

class SystemA {
public:
  void doThing() { cout << "System A" << endl; }
};

class SystemB {
public:
  void doThing() { cout << "System B" << endl; }
};

class SystemC {
public:
  void doThing() { cout << "System C" << endl; }
};

class Fadece {
public:
  Fadece(SystemA *a, SystemB *b, SystemC *c) : a(a), b(b), c(c) {}
  ~Fadece() {
    delete a;
    delete b;
    delete c;
  }

public:
  void doThing() {
    a->doThing();
    b->doThing();
    c->doThing();
  }

private:
  SystemA *a;
  SystemB *b;
  SystemC *c;
};

int main() {
  Fadece *whx = new Fadece(new SystemA, new SystemB, new SystemC);
  whx->doThing();

  return 0;
}
