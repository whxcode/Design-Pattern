/*************************************************************************
> File Name: 01-CreatePattern/22.建造者模式.普通实现.cpp
> Author: root
> Mail:
> Created Time: 2022年07月18日 星期一 20时39分08秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

struct AbstractHouse {
public:
  virtual void buildBasic() = 0;
  virtual void buildWalls() = 0;
  virtual void roofed() = 0;
  virtual void build() {
    buildBasic();
    buildWalls();
    roofed();
  }
};

struct CommonHouse : public AbstractHouse {
public:
  void buildBasic() override { cout << "CommonHouse buildBasic" << endl; }
  void buildWalls() override { cout << "CommonHouse buildWalls" << endl; }
  void roofed() override { cout << "CommonHouse roofed" << endl; }
};

int main() {
  CommonHouse *common = new CommonHouse;

  common->build();

  delete common;

  return 0;
}
