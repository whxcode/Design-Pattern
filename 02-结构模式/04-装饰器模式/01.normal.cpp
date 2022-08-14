/*************************************************************************
> File Name: 01.normal.cpp
> Author:
> Mail:
> Created Time: 2022年08月14日 星期日 09时34分16秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Component {
public:
  virtual void worker() = 0;
};

class ConcreteComponentA : public Component {
public:
  void worker() override { cout << "ConcreteComponentA" << endl; }
};

class ConcreteComponentB : public Component {
public:
  void worker() override { cout << "ConcreteComponentB" << endl; }
};

class Decorator : public Component {
public:
  ~Decorator() { delete component; }

public:
  void worker() override { component->worker(); }

protected:
  Component *component;
};

class ConcreteDecoratorA : public Decorator {

public:
  ConcreteDecoratorA(Component *component) { this->component = component; }

public:
  void worker() override {
    Decorator::worker();
    cout << "ConcreteDecoratorA" << endl;
  }
};

void worker(Component *component) {
  component->worker();

  delete component;

  cout << endl;
}

int main() {
  worker(new ConcreteComponentA());
  worker(new ConcreteDecoratorA(new ConcreteComponentA()));

  worker(new ConcreteDecoratorA(new ConcreteDecoratorA(new ConcreteComponentA())));

  return 0;
}
