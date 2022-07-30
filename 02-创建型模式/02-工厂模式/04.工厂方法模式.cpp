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

class BJCheessePizza : public Pizza {
public:
  void prepare() override { cout << "北京的奶酪批萨" << endl; }
};

class BJGreekPizza : public Pizza {
public:
  void prepare() override { cout << "北京的希腊批萨" << endl; }
};

class LDCheessePizza : public Pizza {
public:
  void prepare() override { cout << "伦敦的奶酪批萨" << endl; }
};

class LDGreekPizza : public Pizza {
public:
  void prepare() override { cout << "伦敦的希腊批萨" << endl; }
};

class PizzaFactory {
public:
  virtual Pizza *createPizza(string type) = 0;
};

class BJFactory : public PizzaFactory {

public:
  Pizza *createPizza(string type) override {
    if (type == "g") {
      return new BJGreekPizza;
    }
    if (type == "c") {
      return new BJCheessePizza;
    }
    return NULL;
  }

public:
  static BJFactory *getInstance() { return BJFactory::instance; }

private:
  BJFactory() {}

private:
  static BJFactory *instance;
};

BJFactory *BJFactory::instance = new BJFactory;

class LDFactory : public PizzaFactory {
public:
  Pizza *createPizza(string type) override {
    if (type == "g") {
      return new LDGreekPizza;
    }
    if (type == "c") {
      return new LDCheessePizza;
    }
    return NULL;
  }
public:
  static LDFactory *getInstance() { return LDFactory::instance; }

private:
  LDFactory() {}

private:
  static LDFactory *instance;
};

LDFactory *LDFactory::instance = new LDFactory;

int main() {
  BJFactory *bj = BJFactory::getInstance();

  bj->createPizza("g")->prepare();
  bj->createPizza("c")->prepare();

  LDFactory *ld = LDFactory::getInstance();

  ld->createPizza("g")->prepare();
  ld->createPizza("c")->prepare();

  return 0;
}
