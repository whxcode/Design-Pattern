/*************************************************************************
> File Name: 01-proxy.cpp
> Author:
> Mail:
> Created Time: 2022年07月05日 星期二 20时51分11秒
代理模式:

 ************************************************************************/

#include <iostream>
using namespace std;
class Item {
public:
  Item(string kind, bool fact) {
    this->kind = kind;
    this->fact = fact;
  }
  void show() {
    cout << this->kind << endl;
    cout << this->fact << endl;
  }
  bool getFact() { return this->fact; }

private:
  string kind;
  bool fact;
};

class Shopping {

public:
  virtual void buy(Item *it) = 0;
};

class KoreaShopping : public Shopping {
public:
  void buy(Item *it) override {
    cout << "去韩国购买" << endl;
    it->show();
  }
};

class USShopping : public Shopping {
public:
  void buy(Item *it) override {
    cout << "去美国购买" << endl;
    it->show();
  }
};

class OverrseasProxy : Shopping {
public:
  OverrseasProxy(Shopping *shopping) { this->shopping = shopping; }
  void buy(Item *it) override {

    if (it->getFact()) {
      cout << "发现正品，要购物" << endl;
      this->shopping->buy(it);
      cout << "通过海关检查" << endl;
    } else {
      cout << "这是假货，不会购买" << endl;
    }
  }

private:
  Shopping *shopping;
};

int console() {
  Item *t1 = new Item("snake", true);
  Shopping *koreaShopping = new KoreaShopping();

#if 0
  if (t1->getFact()) {
    cout << "发现正品，要购物" << endl;

    koreaShopping->buy(t1);

    cout << "通过海关检查" << endl;

  } else {
    cout << "这是假货，不会购买" << endl;
  }
#endif
  Shopping *usShopping = new USShopping();
  OverrseasProxy *overseaShopping = new OverrseasProxy(usShopping);

  overseaShopping->buy(t1);

  return 0;
}
