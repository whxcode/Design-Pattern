/*************************************************************************
> File Name: 18-visitor/01.park.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 19时06分37秒
 ************************************************************************/

#include <iostream>
#include <list>

using namespace std;
class Park;

class Visitor {
public:
  virtual void vistor(Park *park) = 0;
};

class Park {
public:
  virtual void accpet(Visitor *vistor) = 0;
};

class StairsPark : public Park {
public:
  void accpet(Visitor *vistor) override { vistor->vistor(this); }
};

class PoolPark : public Park {
public:
  void accpet(Visitor *vistor) override { vistor->vistor(this); }
};

class Manage : public Visitor {
public:
  void vistor(Park *park) override { cout << "我是在视察工作的" << endl; }
};

class Cleaner : public Visitor {
public:
  void vistor(Park *park) override { cout << "我是来打扫卫生的" << endl; }
};
class Parks : public Park {
public:
  Parks() { parks.clear(); }

public:
  void accpet(Visitor *vistor) override {
    auto start = parks.begin();
    auto end = parks.end  ();

    while (start != end) {
      vistor->vistor((*start++));
    }
  }
  void addPark(Park *park) { parks.push_back(park); }

private:
  list<Park *> parks;
};

void test01() {
  Visitor *manage = new Manage;
  Visitor *cleaner = new Cleaner;

  Park *poolPark = new PoolPark;
  Park *stairsPark = new StairsPark;

  poolPark->accpet(manage);
  poolPark->accpet(cleaner);

  stairsPark->accpet(manage);
  stairsPark->accpet(cleaner);
}

void test02() {
  Visitor *manage = new Manage;

  Park *poolPark = new PoolPark;
  Park *stairsPark = new StairsPark;

  Parks *park = new Parks;
  park->addPark(poolPark);
  park->addPark(stairsPark);

  park->accpet(manage);
}

int main() {
  test02();
  // test01();
  return 0;
}
