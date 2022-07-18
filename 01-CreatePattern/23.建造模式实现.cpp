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

struct House {
public:
  string basic;
  string walls;
  string roofed;

public:
  void printf() { cout << "house:" << basic << walls << roofed << endl; }
};

struct Builder : public House {
public:
  Builder() { this->house = new House; }

public:
  virtual void buildBasic() = 0;
  virtual void buildWalls() = 0;
  virtual void roofed() = 0;
  virtual House *build() { return house; }

protected:
  House *house;
};

struct CommonHouse : public Builder {
public:
public:
  void buildBasic() override {
    this->house->basic = "CommonHouse buildBasic";
    cout << "CommonHouse buildBasic" << endl;
  }
  void buildWalls() override {
    this->house->walls = "CommonHouse buildWalls";
    cout << "CommonHouse buildWalls" << endl;
  }
  void roofed() override {
    this->house->roofed = "CommonHouse roofed";
    cout << "CommonHouse roofed" << endl;
  }
};

struct HighBuilding : public Builder {
public:
  void buildBasic() override {
    this->house->basic = "HighBuilding buildBasic";
    cout << "HighBuilding buildBasic" << endl;
  }
  void buildWalls() override {

    this->house->walls = "HighBuilding buildWalls";
    cout << "HighBuilding buildWalls" << endl;
  }
  void roofed() override {
    this->house->roofed = "HighBuilding roofed";
    cout << "HighBuilding roofed" << endl;
  }
};

struct Villa : public Builder {
public:
  void buildBasic() override {
    this->house->basic = "Villa buildBasic";
    cout << "Villa buildBasic" << endl;
  }
  void buildWalls() override {

    this->house->walls = "Villa buildWalls";
    cout << "Villa buildWalls" << endl;
  }
  void roofed() override {
    this->house->roofed = "Villa roofed";
    cout << "Villa roofed" << endl;
  }
};

struct Director {
public:
  virtual House *construct() = 0;

protected:
  Builder *build;
};

struct PoorDirector : Director {
public:
  House *construct() override {
    this->build->buildBasic();
    this->build->roofed();
    this->build->buildWalls();

    return build->build();
  }

public:
  void setBuild(Builder *b) { this->build = b; }
};

int main() {
  CommonHouse *commonBuilder = new CommonHouse;
  HighBuilding *hightBuilder = new HighBuilding;
  Villa *villa = new Villa;

  PoorDirector *poor = new PoorDirector;

  poor->setBuild(commonBuilder);

  House *house = poor->construct();
  house->printf();

  poor->setBuild(hightBuilder);
  delete house;

  house = poor->construct();
  house->printf();
  delete house;
  poor->setBuild(villa);
  house = poor->construct();
  cout << endl;
  cout << endl;
  cout << endl;
  house->printf();
  cout << endl;
  ;

  delete villa;
  delete house;
  delete commonBuilder;
  delete hightBuilder;
  delete poor;

  return 0;
}
