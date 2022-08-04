/*************************************************************************
> File Name: 01-工厂模式/01.简单工厂-普通实现.cpp
> Author: root
> Mail:
> Created Time: 2022年08月04日 星期四 21时33分43秒
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
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void package() = 0;
};

class CheessPizza : public Pizza {
public:
  void prepare() override { cout << "CheessPizza prepare" << endl; }
  void bake() override {}
  void cut() override {}
  void package() override { cout << "CheessPizza package" << endl; }
};

class GreekPizza : public Pizza {
public:
  void prepare() override { cout << "GreekPizza prepare" << endl; }
  void bake() override {}
  void cut() override {}
  void package() override { cout << "GreekPizza package" << endl; }
};

class SugarPiazza : public Pizza {
public:
  void prepare() override { cout << "SugarPiazza prepare" << endl; }
  void bake() override {}
  void cut() override {}
  void package() override { cout << "SugarPiazza package" << endl; }
};

class Factory {
public:
  virtual Pizza *createPizza(string type) = 0;
};

class FactoryPizza : public Factory {
public:
  static FactoryPizza *getInstance() { return FactoryPizza::instance; }

public:
  Pizza *createPizza(string type) override {
    if (type == "g") {
      return new GreekPizza;
    }
    if (type == "c") {
      return new CheessPizza;
    }

    if (type == "s") {
      return new SugarPiazza();
    }

    return NULL;
  }

private:
  static FactoryPizza *instance;
};

FactoryPizza *FactoryPizza::instance = new FactoryPizza;

class OrderPizza {
public:
  OrderPizza(Factory *factory) { this->factory = factory; }

public:
  Pizza *createPizza(string type) { return factory->createPizza(type); }

private:
  Factory *factory;
};

void test01() {
  OrderPizza *order1 = new OrderPizza(FactoryPizza::getInstance());

  GreekPizza *gp1 = (GreekPizza *)order1->createPizza("g");
  CheessPizza *cp1 = (CheessPizza *)order1->createPizza("c");

  gp1->package();
  cp1->package();
  cout << endl;

  delete gp1;
  delete cp1;
  delete order1;

  OrderPizza *order2 = new OrderPizza(FactoryPizza::getInstance());

  GreekPizza *gp2 = (GreekPizza *)order2->createPizza("g");
  CheessPizza *cp2 = (CheessPizza *)order2->createPizza("c");
  SugarPiazza *sp2 = (SugarPiazza *)order2->createPizza("s");

  gp2->package();
  cp2->package();
  sp2->package();

  delete gp2;
  delete cp2;
  delete sp2;
  delete order2;
}

int main() {
  test01();

  return 0;
}
