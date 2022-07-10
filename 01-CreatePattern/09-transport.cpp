/*************************************************************************
> File Name: 09-transport.cpp
> Author:
> Mail:
> Created Time: 2022年07月09日 星期六 11时10分43秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Produt {
public:
  virtual ~Produt(){};
  virtual string Operation() const = 0;
};

class ConceretProduct1 : public Produt {
public:
  virtual string Operation() const override { return "ConceretProduct1"; }
};

class ConceretProduct2 : public Produt {
public:
  virtual string Operation() const override { return "ConceretProduct2"; }
};

class Creator {
public:
  virtual ~Creator() {}
  virtual Produt *factoryMethod() const = 0;

  string SomeOperation() {

    Produt *product = this->factoryMethod();
    string result = product->Operation();

    delete product;
    return result;
  }
};

class ConcreteCreator1 : public Creator {
public:
  Produt *factoryMethod() const override { return new ConceretProduct1; }
};

class ConcreteCreator2 : public Creator {
public:
  Produt *factoryMethod() const override { return new ConceretProduct2; }
};

int main() {

  Creator *create = new ConcreteCreator1();
  cout<< create->SomeOperation()<<endl;;

  Creator *create1 = new ConcreteCreator2();

  cout<< create1->SomeOperation()<<endl;;

  ;
  return 0;
}
