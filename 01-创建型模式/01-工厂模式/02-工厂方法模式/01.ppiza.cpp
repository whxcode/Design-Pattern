/*************************************************************************
> File Name: 02-工厂方法模式/01.ppiza.cpp
> Author: root
> Mail:
> Created Time: 2022年08月04日 星期四 21时59分57秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Pizza {
public:
  virtual void package() = 0;
};

class BJCheessPizza : public Pizza {
public:
  void package() override { cout << "BJCheessPizza" << endl; }
};

class BJGreekPizza : public Pizza {
public:
  void package() override { cout << "BJGreekPizza" << endl; }
};

class LDCheessPizza : public Pizza {
public:
  void package() override { cout << "LDCheessPizza" << endl; }
};

class LDGreekPizza : public Pizza {
public:
  void package() override { cout << "LDGreekPizza" << endl; }
};

class Factory {
public:
  virtual Pizza *createPizza(string type) = 0;
};

class BJFactory : public Factory {
public:
  Pizza *createPizza(string type) override {
    if ("bg" == type) {
      return new BJGreekPizza;
    }

    if ("bc" == type) {
      return new BJCheessPizza;
    }
    return NULL;
  }
};

class LDFactory : public Factory {
public:
  Pizza *createPizza(string type) override {
    if ("bg" == type) {
      return new BJGreekPizza;
    }

    if ("bc" == type) {
      return new BJCheessPizza;
    }
    return NULL;
  }
};

void bj() {
  BJFactory *factory = new BJFactory;
  BJGreekPizza *bg = (BJGreekPizza *)factory->createPizza("bg");
  BJCheessPizza *bc = (BJCheessPizza *)factory->createPizza("bc");

  bg->package();
  bc->package();

  delete factory;
  delete bg;
  delete bc;

  cout << endl;
}

void ld() {
  LDFactory *factory = new LDFactory;
  LDGreekPizza *bg = (LDGreekPizza *)factory->createPizza("bg");
  LDCheessPizza *bc = (LDCheessPizza *)factory->createPizza("bc");

  bg->package();
  bc->package();

  delete factory;
  delete bg;
  delete bc;

  cout << endl;
}

void worker(Factory *factory) {
  Pizza *bg = factory->createPizza("bg");
  Pizza *bc = factory->createPizza("bc");

  bg->package();
  bc->package();

  delete bg;
  delete bc;
  delete factory;

  cout << endl;
}

int main() {
  worker(new BJFactory);
  worker(new LDFactory);

  return 0;
}
