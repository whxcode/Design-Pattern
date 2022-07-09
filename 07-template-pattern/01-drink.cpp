/*************************************************************************
> File Name: 01-drink.cpp
> Author:
> Mail:
> Created Time: 2022年07月09日 星期六 09时23分19秒
 ************************************************************************/

#include <iostream>
using namespace std;
class MakeDrink {
public:
  void boil() { cout << "烧开水" << endl; }
  void putInCup() { cout << "导入杯中" << endl; }
  virtual bool customWantAddtings() { return true; }
  virtual void brew() = 0;
  virtual void addTings() = 0;
  void make() {
    boil();
    brew();
    putInCup();
    if (customWantAddtings()) {
      addTings();
    }
  }
};

class MakeCoffe : public MakeDrink {
public:
  virtual void brew() override { cout << "冲咖啡豆" << endl; }
  virtual void addTings() override { cout << "加入牛奶与白糖" << endl; }
};

class MakeTea : public MakeDrink {
public:
  virtual bool customWantAddtings() override {
    return false;
  }
  virtual void brew() override { cout << "冲茶叶" << endl; }
  virtual void addTings() override { cout << "加入柠檬与花" << endl; }
};

int main() {
  MakeDrink *makeCoffe = new MakeCoffe();
  makeCoffe->make();
  printf("\n\n");
  MakeDrink *makeTea = new MakeTea();
  makeTea->make();

  return 0;
}
