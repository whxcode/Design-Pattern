/*************************************************************************
> File Name: 02-创建型模式/02-工厂模式/01.简单工厂.cpp
> Author: root
> Mail:
> Created Time: 2022年07月30日 星期六 08时54分34秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Pizza {
public:
  virtual void prepare() = 0;
  void bake() { cout << "bake pizza" << endl; }
  void cut() { cout << "cut pizza" << endl; }
  void box() { cout << "box pizza" << endl; }

public:
  string getName() { return name; }

protected:
  string name;
};

class ChessPizza : public Pizza {
public:
  void prepare() override {
    this->name = "奶酪批萨";
    cout << "奶酪批萨" << endl;
  }
};

class GreekPizza : public Pizza {
public:
  void prepare() override {
    this->name = "希腊批萨";
    cout << "希腊批萨" << endl;
  }
};

class PepperPizza : public Pizza {
public:
  void prepare() override {
    this->name = "胡椒批萨";
    cout << "胡椒批萨" << endl;
  }
};

class PizzaFactory {
public:
  Pizza *createPizza(string type) {
    Pizza *pizza = NULL;

    if (type == "g") {
      pizza = new GreekPizza;
      ;
    } else if (type == "c") {
      pizza = new ChessPizza;
      ;
    } else if (type == "p") {
      pizza = new PepperPizza;
    }

    return pizza;
  }
};

class OrderPizza {
public:
  void createPizza(PizzaFactory *factory) {
    Pizza *pizza = NULL;
    string type = "";

    do {
      cin >> type;
      pizza = factory->createPizza(type);
      pizza->prepare();
      pizza->bake();
      pizza->cut();
      pizza->box();

      if (pizza == NULL) {
        break;
      }
    } while (1);
  }
};

int main() {
  OrderPizza *order = new OrderPizza;
  PizzaFactory *factory = new PizzaFactory;

  order->createPizza(factory);

  delete order;
  delete factory;

  return 0;
}
