/*************************************************************************
> File Name: 01-CreatePattern/16.皮萨.简单工厂模式.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 16时17分20秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

struct Pizza {
public:
  static Pizza *create(string type);

public:
  virtual void prepare() = 0;
  void bake() { cout << "烘烤皮萨" << endl; }
  virtual void cut() { cout << "切割皮萨" << endl; }
  virtual void box() { cout << "打包皮萨" << endl; }

protected:
  string name;
};

struct CheesePizza : public Pizza {
public:
  void prepare() override { cout << "准备奶酪皮萨" << endl; }
};

struct GreekPizza : public Pizza {
public:
  void prepare() override { cout << "希腊奶酪皮萨" << endl; }
};

struct PepperPizza : public Pizza {
public:
  void prepare() override { cout << "胡椒皮萨" << endl; }
};

Pizza *Pizza::create(string type) {
  if (type == "chessse") {
    return new CheesePizza;
  } else if (type == "greek") {
    return new GreekPizza;
  } else if (type == "pepper") {
    return new PepperPizza;
  }
  return NULL;
}

/*
struct PizzaFactory {
public:
  Pizza *create(string type) {
    if (type == "chessse") {
      return new CheesePizza;
    } else if (type == "greek") {
      return new GreekPizza;
    } else if (type == "pepper") {
      return new PepperPizza;
    }

    return NULL;
  }
};
*/

int main() {
  //  PizzaFactory *factory = new PizzaFactory;
  Pizza *chessse = Pizza::create("chessse");
  Pizza *greek = Pizza::create("greek");
  Pizza *pepper = Pizza::create("pepper");

  chessse->prepare();
  greek->prepare();
  pepper->prepare();

  delete (CheesePizza *)chessse;
  delete (GreekPizza *)greek;
  delete (PepperPizza *)pepper;

  return 0;
}
