/*************************************************************************
> File Name: 04-fruit-simple.cpp
> Author:
> Mail:
> Created Time: 2022年07月03日 星期日 19时49分12秒
简单工厂类:
 比较适合比较少的对象。
 ************************************************************************/

#include <iostream>
using namespace std;
class Fruit {
public:
  virtual void geteName() = 0;
  ~Fruit() {
    delete this->id;
    cout << "~Fruit()\n";
  }

protected:
  int *id;
};

class Apple : public Fruit {
public:
  Apple(int id) {
    this->id = new int;
    *this->id = id;
  }
  virtual void geteName() override { cout << "i am is Apple\n"; }
  ~Apple() { printf("~Apple()"); };
};

class Banana : public Fruit {
public:
  Banana(int id) {
    this->id = new int;
    *this->id = id;
  }
  virtual void geteName() override { cout << "i am is Banana\n"; }

  ~Banana() { printf("~Banana()"); };
};

class FruitFactory {

public:
  Fruit *createFruit(string kind);
};

class Pear : public Fruit {
public:
  virtual void geteName() override { cout << "im is Pear\n"; }
};

Fruit *FruitFactory::createFruit(string kind) {
  if (kind == "apple") {
    return new Apple(1);
  } else if (kind == "banana") {
    return new Banana(2);
  } else if (kind == "pear") {
    return new Pear;
  }

  return NULL;
}

int console() {
  FruitFactory *factory = new FruitFactory();
  Fruit *apple = factory->createFruit("apple");
  Fruit *banana = factory->createFruit("banana");
  Fruit *pear = factory->createFruit("pear");

  apple->geteName();
  banana->geteName();
  pear->geteName();

  delete factory;
  delete (Apple *)apple;
  delete (Banana *)banana;
  delete (Pear *)pear;

  return 0;
}
