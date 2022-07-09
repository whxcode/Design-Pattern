/*************************************************************************
> File Name: 07-AbstractFactory.cpp
> Author:
> Mail:
> Created Time: 2022年07月03日 星期日 20时54分18秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Fruit {
public:
  virtual void getName() const = 0;
};

class USAApple : public Fruit {

public:
  virtual void getName() const override { cout << "我是美国的苹果\n"; }
};

class USABanana : public Fruit {

public:
  virtual void getName() const override { cout << "我是美国的香蕉\n"; }
};

class ChinaApple : public Fruit {
public:
  virtual void getName() const override { cout << "我是中国的苹果\n"; }
};

class ChinaBanana : public Fruit {

public:
  virtual void getName() const override { cout << "我是中国的香蕉\n"; }
};

class AbstractFactory {
public:
  virtual Fruit *createApple() = 0;
  virtual Fruit *createBanana() = 0;
};

class USSAFactory : public AbstractFactory {
public:
  Fruit *createBanana() override { return new USABanana; }
  Fruit *createApple() override { return new USAApple; }
};

class ChinaFactory : public AbstractFactory {
public:
  Fruit *createBanana() override { return new ChinaBanana; }
  Fruit *createApple() override { return new ChinaApple; }
};

int main() {
  AbstractFactory *usaAFactory = new USSAFactory;
  AbstractFactory *chinaFactory = new ChinaFactory;

  const Fruit *usaApple = usaAFactory->createApple();
  const Fruit *usaBanana = usaAFactory->createBanana();

  usaApple->getName();
  usaBanana->getName();

  return 0;
}
