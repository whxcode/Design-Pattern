#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Prototpye {
public:
  virtual Prototpye *clone() = 0;
  virtual void dispay() = 0;
};

class Person : public Prototpye {
public:
  Person(string name) { this->name = name; }

  Prototpye *clone() override { return new Person(name); }
  void dispay() override { cout << "name:" << name << endl; }

public:
  string name;
};

int main() {
  Prototpye *p1 = new Person("王恒星");
  Prototpye *p2 = p1->clone();

  p1->dispay();
  p2->dispay();

  ((Person *)p2)->name = "恒星王";
  cout << endl;

  p1->dispay();
  p2->dispay();

  return 0;
}
