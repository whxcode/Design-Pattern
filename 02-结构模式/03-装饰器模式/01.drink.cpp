/*************************************************************************
> File Name: 01.drink.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月13日 星期六 11时10分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Drink {
  public:
    virtual double cost() { return prince; }
  protected:
    double prince;
    string describe;
};

class Coffee :public Drink {

};

class SugarCoffee:public Coffee {
  public:
    SugarCoffee() {
      this->describe = "SugarCoffee";
      this->prince = 10;
    }
};

class EspressoCoffee:public Coffee {
  public:
    EspressoCoffee() {
      this->describe = "EspressoCoffee";
      this->prince = 20;
    }
};

class Decorator:public Drink {
  public:
    Decorator() {
      drink = NULL;
    }
  public:
    double cost() override {
      double extra = drink == NULL ? 0 : drink->cost();
      return this->prince + extra;
    }

    void setDrink(Drink* drink) {
      this->drink  = drink;
    }

  protected:
    Drink* drink;
};


class Milk :public Decorator {
  public:
    Milk() {
      this->describe ="Milk";
      this->prince = 5;
    }
};


class Chocolate :public Decorator {
  public:
    Chocolate() {
      this->describe ="Chocolate";
      this->prince = 10;
    }
};

void test01() {
  Milk*m1 = new Milk;
  Milk*m2 = new Milk;

  m1->setDrink(m2);
  cout << "test01 m1:" << m1->cost() << endl;
};

void test02() {
  Milk*m1 = new Milk;
  Milk*m2 = new Milk;
  SugarCoffee*s2 = new SugarCoffee;

  m2->setDrink(s2);
  m1->setDrink(m2);
  cout << "test02 m1:" << m1->cost() << endl;
};

void test03() {
  Milk*m1 = new Milk;
  Chocolate*m2 = new Chocolate;
  SugarCoffee*s2 = new SugarCoffee;

  m2->setDrink(s2);
  m1->setDrink(m2);
  cout << "test03 m1:" << m1->cost() << endl;
};

int main(){
  test01();
  test02();
  test03();

  return 0;
}
