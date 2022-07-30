/*************************************************************************
> File Name: ./02-创建型模式/04-建造者模式/01.普通模式盖房子.cpp
> Author: root
> Mail:
> Created Time: 2022年07月30日 星期六 12时02分24秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class AbstractHouse {
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

class CommonHouse : public AbstractHouse {
public:
  void buildBasic() override { cout << "CommonHouse basic" << endl; }

  void buildWalls() override { cout << "CommonHouse walls" << endl; }

  void roofed() override { cout << "Common roofed" << endl; }
};

int main() {
  CommonHouse* house = new CommonHouse;
  house->build();

  return 0;
}
