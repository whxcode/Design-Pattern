#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Adaptee {
public:
  int request() { return 100; }
};

class Target {
public:
  virtual int useData() = 0;
};

class Adapter : public Target {
public:
  Adapter(Adaptee *adaptee) { this->adaptee = adaptee; }
  ~Adapter() { delete adaptee; }

public:
  int useData() override { return this->adaptee->request() / 10; }

private:
  Adaptee *adaptee;
};

class V5 : public Adaptee, Target {
public:
  int useData() override { return this->request() / (this->request() / 5); }
};

int main() {
  Adapter *target = new Adapter(new Adaptee);
  V5 *v5 = new V5;

  cout << target->useData() << endl;
  cout << v5->useData() << endl;

  return 0;
}
