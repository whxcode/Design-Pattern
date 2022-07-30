/*************************************************************************
fw> File Name: 03-结构模式/03-装饰者模式/01.coffe.cpp
> Author: root
> Mail:
> Created Time: 2022年07月30日 星期六 17时55分27秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Drink {
public:
  string desc;

public:
  void setPrice(double price) { this->price = price; }
  double getPrice() { return price; }

public:
  virtual double cost() = 0;

private:
  double price;
};

// 被装饰着
class Coffee : public Drink {
  virtual double cost() { return this->Drink::getPrice(); }
};

class EspressoCoffee : public Coffee {
public:
  EspressoCoffee() {
    this->Drink::desc = "意大利咖啡";
    this->Drink::setPrice(6);
  }
};

class LongBlackCoffee : public Coffee {
public:
  LongBlackCoffee() {
    this->Drink::desc = "LongBlack";
    this->Drink::setPrice(10);
  }
};

class SHortBlackCoffee : public Coffee {
public:
  SHortBlackCoffee() {
    this->Drink::desc = "LongBlack";
    this->Drink::setPrice(10);
  }
};

// 装饰者。
class Decorator : public Drink {
public:
  Decorator(Drink *drink) { this->drink = drink; }
  ~Decorator() { delete drink; }

public:
  double cost() override { return this->Drink::getPrice() + drink->cost(); }

private:
  Drink *drink;
};

class Tea : public Decorator {
public:
  Tea(Drink *drink) : Decorator(drink) { this->Decorator::Drink::setPrice(5); }

public:
private:
  Drink *drink;
};

int main() {
  Drink *longBlack = new LongBlackCoffee;
  cout << longBlack->cost() << endl;

  Drink *tea = new Tea(new LongBlackCoffee);
  Drink *tea1 = new Tea(tea);

  cout << tea->cost() << endl;
  cout << tea1->cost() << endl;

  return 0;
}
