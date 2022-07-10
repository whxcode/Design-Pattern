/*************************************************************************
> File Name: 02-commodyty.cpp
> Author:
> Mail:
> Created Time: 2022年07月10日 星期日 16时30分24秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#define DiscountPrence 0.8
#define FullMinusPrice 100

class AbstractStrategy {
public:
  virtual double getPrice(double price) const = 0;
};

class Commondity {
public:
  virtual double sellPrice() const { return price; };

  void setSaleStrategy(AbstractStrategy *strategy) volatile {
    this->strategy = strategy;
  }

  Commondity(string kind, double price) : kind(kind), price(price) {}

  friend ostream &operator<<(ostream &cout, Commondity *commodyty) {

    cout << commodyty->kind << endl;
    cout << commodyty->sellPrice() << endl;
    return cout;
  }

protected:
  double price;
  AbstractStrategy *strategy;

private:
  string kind;
};

class Discount : public AbstractStrategy {
public:
  double getPrice(double price) const override {
    return price * DiscountPrence;
  }
};

class FullMinus : public AbstractStrategy {
public:
  double getPrice(double price) const override {
    return price > 200 ? price - FullMinusPrice : price;
  }
};

class Pen : public Commondity {
public:
  Pen(string kind, double price) : Commondity(kind, price) {}
  double sellPrice() const override {
    return this->strategy->getPrice(this->price);
  }
};

int main() {
  AbstractStrategy *strategy1 = new Discount();
  AbstractStrategy *strategy2 = new FullMinus();

  Commondity *pen = new Pen("派克", 1000);

  pen->setSaleStrategy(strategy1);
  cout << pen;

  pen->setSaleStrategy(strategy2);
  cout << pen;

  return 0;
}
