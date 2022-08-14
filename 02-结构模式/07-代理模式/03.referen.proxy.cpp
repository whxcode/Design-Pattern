/*************************************************************************
> File Name: 03.referen.proxy.cpp
> Author:
> Mail:
> Created Time: 2022年08月14日 星期日 16时01分33秒
 ************************************************************************/

#include <iostream>
using namespace std;
template <typename T> class Pointer {
public:
  Pointer(T *t) {
    this->t = t;
    reference = 1;
  }
  T *get() { return t; }
  void free() {
    if (this->reference == 1) {
      delete t;
      delete this;
      return;
      ;
    }

    this->reference--;
  }

  Pointer *copy() {

    reference++;
    return this;
  }

  void display() { cout << "reference:" << reference << endl; }

private:
  int reference;
  T *t;
};

class Person {
public:
  void speak() { cout << "what do you it!" << endl; }
};

int main() {
  Person *p = new Person;

  Pointer<Person> *p1 = new Pointer<Person>(p);

  p1->get()->speak();
  // p1->free();

  p1->display();

  Pointer<Person >* p2 = p1->copy();

  p1->display();

  p1->free();
  p1->display();

  p2->free();
  p1->display();


  p1->get()->speak();
  return 0;
}
