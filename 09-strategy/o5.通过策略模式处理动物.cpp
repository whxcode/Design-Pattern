/*************************************************************************
> File Name: 09-strategy/04.通过继承处理动物.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 10时54分10秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Fly {
public:
  virtual void fly() = 0;
};

class GoodFly : public Fly {
public:
  void fly() override { cout << "飞翔技术很好" << endl; }
};

class BadFly : public Fly {
public:
  void fly() override { cout << "飞翔技术不是很好" << endl; }
};

class NoFly : public Fly {
public:
  void fly() override { cout << "不会飞翔" << endl; }
};

class Duck {
public:
  virtual void display() = 0;

protected:
  Fly *flyBehavior;

public:
  virtual void quack() { cout << "鸭子 嘎嘎~~" << endl; }
  virtual void swim() { cout << "游泳~" << endl; }
  virtual void fly() {
    if (flyBehavior != NULL) {
      flyBehavior->fly();
    }
  }
};

class WildDuck : public Duck {
public:
  WildDuck() { flyBehavior = new GoodFly; }

public:
  void display() override { cout << "这是野生鸭子" << endl; }
};

class PekingDuck : public Duck {
public:
  PekingDuck() { flyBehavior = new BadFly(); }

public:
  void display() override { cout << "这是北京鸭子" << endl; }
};

class ToyDuck : public Duck {
public:
  ToyDuck() { flyBehavior = new NoFly(); }

public:
  void display() override { cout << "这是玩具鸭子" << endl; }
  void quack() override { cout << "玩具鸭子不能叫" << endl; }
  void swim() override { cout << "玩具鸭子不能游泳" << endl; }
};

int main() {
  WildDuck *wildDuck = new WildDuck;
  PekingDuck *pekingDuck = new PekingDuck;
  ToyDuck *toyDuck = new ToyDuck;

  wildDuck->fly();
  pekingDuck->fly();
  toyDuck->fly();

  return 0;
}
