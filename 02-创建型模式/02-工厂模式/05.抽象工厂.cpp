#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Pizza {
public:
  virtual void prepare() = 0;
  void bake() { cout << "bake pizza" << endl; }
  void cut() { cout << "cut pizza" << endl; }
  void box() { cout << "box pizza" << endl; }

public:
  string getName() { return name; }

protected:
  string name;
};

class BJCheessePizza : public Pizza {
public:
  void prepare() override { cout << "北京的奶酪批萨" << endl; }
};

class BJGreekPizza : public Pizza {
public:
  void prepare() override { cout << "北京的希腊批萨" << endl; }
};

class LDCheessePizza : public Pizza {
public:
  void prepare() override { cout << "伦敦的奶酪批萨" << endl; }
};

class LDGreekPizza : public Pizza {
public:
  void prepare() override { cout << "伦敦的希腊批萨" << endl; }
};

class PizzaFactory {
public:
  virtual Pizza *createGreekPizza() = 0;
  virtual Pizza *createChessePizza() = 0;
};

class BJFactory : public PizzaFactory {

public:
  Pizza *createGreekPizza() override { return new BJGreekPizza; }

  Pizza *createChessePizza() override { return new BJCheessePizza; }

public:
  static BJFactory *getInstance() { return BJFactory::instance; }

private:
  BJFactory() {}

private:
  static BJFactory *instance;
};

BJFactory *BJFactory::instance = new BJFactory;

class LDFactory : public PizzaFactory {
public:
  Pizza *createGreekPizza() override { return new LDGreekPizza; }

  Pizza *createChessePizza() override { return new LDCheessePizza; }

public:
  static LDFactory *getInstance() { return LDFactory::instance; }

private:
  LDFactory() {}

private:
  static LDFactory *instance;
};

LDFactory *LDFactory::instance = new LDFactory;

int main() {
  BJFactory *bj = BJFactory::getInstance();

  bj->createGreekPizza()->prepare();
  bj->createChessePizza()->prepare();

  LDFactory *ld = LDFactory::getInstance();

  bj->createGreekPizza()->prepare();
  bj->createChessePizza()->prepare();

  return 0;
}
