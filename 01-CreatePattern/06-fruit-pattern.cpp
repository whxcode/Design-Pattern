/*************************************************************************
> File Name: 06-fruit-pattern.cpp
> Author:
> Mail:
> Created Time: 2022年07月03日 星期日 20时23分53秒
工厂方法
 每一个工厂对应一个产品。

 ************************************************************************/

#include <iostream>
using namespace std;

class Fruit {
public:
  virtual void getName() = 0;
};

class Apple : public Fruit {
public:
  virtual void getName() override { cout << "我是🍎\n "  ;}
};

class Banana : public Fruit {
public:
  virtual void getName() override { cout << "我是🍌\n"  ;}
};

class Pear : public Fruit {
public:
  virtual void getName() override { cout << "我是🍐\n " ;}
};

class AbstractFactory {
public:
  virtual Fruit *createFruit() = 0;
};

class AppleFactory : public AbstractFactory {
public:
  virtual Fruit *createFruit() { return new Apple; }
};

class BananaFactory : public AbstractFactory {
public:
  virtual Fruit *createFruit() { return new Banana; }
};

class PearFactory : public AbstractFactory {
public:
  virtual Fruit *createFruit() { return new Pear; }
};

int console() {
  AbstractFactory *bananaFactory = new BananaFactory;
  Fruit *banana = bananaFactory->createFruit();
  banana->getName();

  AbstractFactory *appleFactory = new AppleFactory;
  Fruit *apple = appleFactory->createFruit();
  apple->getName();

  PearFactory *pearFactory = new PearFactory;
  Fruit *pear = pearFactory->createFruit();
  pear->getName();

  delete (BananaFactory *)bananaFactory;
  delete (Banana *)banana;

  delete (AppleFactory *)appleFactory;
  delete (Apple *)apple;

  delete (PearFactory *)pearFactory;
  delete (Pear *)pear;

  return 0;
}
