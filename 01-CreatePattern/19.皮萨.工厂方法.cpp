/*************************************************************************
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
  virtual void prepare() = 0;
  void bake() { cout << "烘烤皮萨" << endl; }
  virtual void cut() { cout << "切割皮萨" << endl; }
  virtual void box() { cout << "打包皮萨" << endl; }

protected:
  string name;
};

struct BeijingCheesePizza : public Pizza {
public:
  void prepare() override { cout << "Beijing 准备奶酪皮萨" << endl; }
};

struct BeijingGreekPizza : public Pizza {
public:
  void prepare() override { cout << "希腊奶酪皮萨" << endl; }
};

struct BeijingPepperPizza : public Pizza {
public:
  void prepare() override { cout << "胡椒皮萨" << endl; }
};

struct LongdongCheesePizza : public Pizza {
public:
  void prepare() override { cout << "Longdong 准备奶酪皮萨" << endl; }
};

struct LongdongGreekPizza : public Pizza {
public:
  void prepare() override { cout << "Longdong 希腊奶酪皮萨" << endl; }
};

struct LongdongPepperPizza : public Pizza {
public:
  void prepare() override { cout << "胡椒皮萨" << endl; }
};

struct PizzaFactory {
public:
  virtual Pizza *createChesse() const = 0;
  virtual Pizza *createGreek() const = 0;
};

struct BeijingFactory : public PizzaFactory {
public:
  Pizza *createChesse() const override { return new BeijingCheesePizza; }
  Pizza *createGreek() const override { return new BeijingGreekPizza; }
};

struct LongdongFactory : public PizzaFactory {
public:
  Pizza *createChesse() const override { return new LongdongCheesePizza; }
  Pizza *createGreek() const override { return new LongdongGreekPizza; }
};

int main() {
  PizzaFactory *beijingFactory = new BeijingFactory;
  Pizza *bjChesse = beijingFactory->createChesse();
  Pizza *bjGreek = beijingFactory->createGreek();

  PizzaFactory *longdongFactory = new LongdongFactory;
  Pizza *lgChesse = longdongFactory->createChesse();
  Pizza *lgGreek = longdongFactory->createGreek();

  bjChesse->prepare();
  bjGreek->prepare();

  lgChesse->prepare();
  lgGreek->prepare();

  delete (BeijingFactory *)beijingFactory;
  delete (LongdongFactory *)longdongFactory;

  delete (BeijingCheesePizza *)bjChesse;
  delete (BeijingGreekPizza *)bjGreek;

  delete (LongdongGreekPizza *)lgChesse;
  delete (LongdongGreekPizza *)lgChesse;

  return 0;
}
