/*************************************************************************
> File Name: 01-CreatePattern/11-Simple-Factory.cpp
> Author:
> Mail:
> Created Time: 2022年07月13日 星期三 21时40分06秒
角色:
  抽象工厂: 返回一个抽象产品。
  抽象产品
  具体工厂: 继承抽象工厂；返回具体的产品。
  具体产品: 继承抽象产品。
 ************************************************************************/

#include <iostream>
using namespace std;

class Fruit {
public:
  virtual void sayname() const = 0;
};

class Pear : public Fruit {
public:
  virtual void sayname() const override { cout << "我是一个理智" << endl; }
};

class Apple : public Fruit {
public:
  virtual void sayname() const override { cout << "我是一个苹果" << endl; }
};

class Peach : public Fruit {
public:
  virtual void sayname() const override { cout << "我是一个桃子" << endl; }
};

class Watermelon : public Fruit {
public:
  virtual void sayname() const override { cout << "我是一个西瓜" << endl; }
};

class AbstractFactory {
public:
  virtual Fruit *createProcut() const = 0;
};

class PearFacotry : public AbstractFactory {
public:
  virtual Fruit *createProcut() const override { return new Pear; };
};

class AppleFactory : public AbstractFactory {
public:
  virtual Fruit *createProcut() const override { return new Apple; };
};

class PeachFactory : public AbstractFactory {
public:
  virtual Fruit *createProcut() const override { return new Peach; };
};

class WatermelonFactory : public AbstractFactory {
public:
  virtual Fruit *createProcut() const override { return new Watermelon; };
};

int main() {
  AbstractFactory *pearFactory = new PearFacotry();
  Fruit *pear = pearFactory->createProcut();

  pear->sayname();

  AbstractFactory *appleFactory = new AppleFactory();
  Fruit *apple = appleFactory->createProcut();

  apple->sayname();

  AbstractFactory *peachFactory = new PeachFactory();
  Fruit *peach = peachFactory->createProcut();

  peach->sayname();

  AbstractFactory *watermelonFactory = new WatermelonFactory();
  Fruit *watermelon = watermelonFactory->createProcut();

  watermelon->sayname();

  delete pearFactory;
  delete pear;

  delete appleFactory;
  delete apple;

  return 0;
}
