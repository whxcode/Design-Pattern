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
  virtual Pizza *createCheessPizza() = 0;
  virtual Pizza *createGreekPizza() = 0;
};

class BJFactory : public Factory {
public:
  Pizza *createGreekPizza() override { return new BJGreekPizza; }

  Pizza *createCheessPizza() override { return new BJCheessPizza; }
};

class LDFactory : public Factory {
public:
  Pizza *createGreekPizza() override { return new LDGreekPizza; }

  Pizza *createCheessPizza() override { return new LDCheessPizza; }
};

void worker(Factory *factory) {
  Pizza *bg = factory->createGreekPizza();
  Pizza *bc = factory->createCheessPizza();

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
