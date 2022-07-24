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
class Duck {
public:
  virtual void display() = 0;

public:
  virtual void quack() { cout << "鸭子 嘎嘎~~" << endl; }
  virtual void swim() { cout << "游泳~" << endl; }
  virtual void fly() { cout << "🕊" << endl;  }
};

class WildDuck : public Duck {
public:
  void display() override { cout << "这是野生鸭子" << endl; }
};

class PekingDuck : public Duck {
public:
  void display() override { cout << "这是北京鸭子" << endl; }
  void fly() override { cout << "北京鸭子飞翔分享" << endl; }
};

class ToyDuck : public Duck {
public:
  void display() override { cout << "这是玩具鸭子" << endl; }
  void quack() override { cout << "玩具鸭子不能叫" << endl; }

  void swim() override { cout << "玩具鸭子不能游泳" << endl; }
  void fly() override { cout << "北京鸭子被能分享" << endl; }
};

int main() { return 0; }
