/*************************************************************************
> File Name: 04-decrator/04.coffee.cpp
> Author: root
> Mail:
> Created Time: 2022年07月19日 星期二 22时00分05秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

class Drink {
public:
  virtual double cost() = 0;

public:
  string describe;
  double price;
};

class Coffee : public Drink {
public:
  double cost() override { return Drink::price; }
};

class Espresso : public Coffee {
public:
  Espresso() {
    Drink::price = .6;
    Drink::describe = "意大利咖啡";
  }
};

class LongBlack : public Coffee {
public:
  LongBlack() {

    Drink::price = 5;
    Drink::describe = "美式咖啡";
  }
};

class Sugar : public Coffee {
public:
  Sugar() {
    Drink::price = 10;
    Drink::describe = "有糖咖啡";
  }
};

class DecoratorCoffee : public Drink {
public:
  DecoratorCoffee(Drink *drink) { this->obj = drink; }

public:
  double cost() override { return Drink::price + obj->cost(); };

private:
  Drink *obj;
};

// 与各种咖啡组合
class Chesse : public DecoratorCoffee {
public:
  Chesse(Drink *drink) : DecoratorCoffee(drink) {
    this->price = 3;
    this->describe = "奶酪";
  }
};

class Milk : public DecoratorCoffee {
public:
  Milk(Drink *drink) : DecoratorCoffee(drink) {
    this->price = 4;
    this->describe = "牛奶";
  }
};

class Chocolate : public DecoratorCoffee {
public:
  Chocolate(Drink *drink) : DecoratorCoffee(drink) {
    this->price = 5;
    this->describe = "巧克力";
  }
};

void test01() {
  Sugar *sugar = new Sugar;

  Chesse *chesse = new Chesse(sugar);
  Milk *milk = new Milk(chesse);
  Milk *milkSugar = new Milk(sugar);

  cout << "chess:" << chesse->cost() << endl;
  cout << "milk:" << milk->cost() << endl;
  cout << "milkSugar:" << milkSugar->cost() << endl;
}

int main() {
  test01();
  return 0;
}
