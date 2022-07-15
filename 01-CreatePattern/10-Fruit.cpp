/*************************************************************************
> File Name: 01-CreatePattern/10-Fruit.cpp
> Author:
> Mail:
> Created Time: 2022年07月12日 星期二 22时42分52秒
简单工厂模式，
只生产抽象的产品；需要根据参数构造具体类。
角色:
  抽象类
  具体产品继承抽象类
  工厂: 根据参数负责生成具体类
 ************************************************************************/

#include <iostream>
#include <string.h>

using namespace std;
class Fruit {
public:
  virtual void getFruit() const = 0;
};

class Banana : public Fruit {
public:
  void getFruit() const override { cout << "我是香蕉" << endl; }
};

class Apple : public Fruit {
public:
  void getFruit() const override { cout << "我是苹果" << endl; }
};

class Factory {
public:
  Fruit *create(char const *const p) {
    if (strcmp(p, "banana") == 0) {
      return new Banana;
    }

    if (strcmp(p, "apple") == 0) {
      return new Apple;
    }

    return NULL;
  }
};

int main() {
  Factory *f = new Factory;

  Fruit *fruit = NULL;

  fruit = f->create("banana");
  fruit->getFruit();

  fruit = f->create("apple");
  fruit->getFruit();

  return 0;
}
