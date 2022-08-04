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

// 如果都是通过 OrderPizza 创建 Pizza 对象， 那么 OrderPizza
// 就是一个简单的工厂对象。
class OrderPizza {
public:
  Pizza *createPizza(string type) {
    if (type == "g") {
      return new GreekPizza;
    }
    if (type == "c") {
      return new CheessPizza;
    }
    return NULL;
  }
};

void test01() {

  OrderPizza *order1 = new OrderPizza;

  GreekPizza *gp1 = (GreekPizza *)order1->createPizza("g");
  CheessPizza *cp1 = (CheessPizza *)order1->createPizza("c");

  gp1->package();
  cp1->package();

  delete gp1;
  delete cp1;
  delete order1;

  OrderPizza *order2 = new OrderPizza;

  GreekPizza *gp2 = (GreekPizza *)order2->createPizza("g");
  CheessPizza *cp2 = (CheessPizza *)order2->createPizza("c");

  gp2->package();
  cp2->package();

  delete gp2;
  delete cp2;
  delete order2;
}

int main() { return 0; }
