/*************************************************************************
> File Name: 04-行为型模式/03-访问者模式/02.park.cpp
> Author: root
> Mail:
> Created Time: 2022年08月02日 星期二 21时16分22秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Park;

class Visitor {
public:
  virtual void visitor(Park *park) = 0;
};

class Park {
public:
  virtual void accept(Visitor *visitor) = 0;
};

// 椅子
class StarsPark : public Park {
public:
  void accept(Visitor *visitor) override { visitor->visitor(this); }
};

// 池塘
class PoolPark : public Park {
public:
  void accept(Visitor *visitor) override { visitor->visitor(this); }
};

class Manage : public Visitor {
public:
  void visitor(Park *park) override { cout << "我在视察工作" << endl; }
};

class Cleaner : public Visitor {
public:
  void visitor(Park *park) override { cout << "我来打扫卫生" << endl; }
};

// 管理公元的各个部分
class Parks : public Park {
public:
  Parks() { parks.clear(); }

public:
  void accept(Visitor *visitor) override {

    auto start = parks.begin();
    auto end = parks.end();

    while (start != end) {
      visitor->visitor((*start++));
    }
  }

  void addPark(Park *park) { parks.push_back(park); }

private:
  list<Park *> parks;
};

int main() {
  Visitor *manage = new Manage;

  Park *poolPark = new PoolPark;
  Park *stairsPark = new StarsPark;

  Parks *park = new Parks;
  park->addPark(poolPark);
  park->addPark(stairsPark);

  park->accept(manage);

  park->accept(new Cleaner);

  return 0;
}
