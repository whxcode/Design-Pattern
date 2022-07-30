#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class House {
public:
  string basic;
  string wall;
  string roofed;

public:
  void display() {
    cout << basic << endl;
    cout << wall << endl;
    cout << roofed << endl;
  }
};

class HouseBulder {
public:
  virtual void buildBasic() = 0;
  virtual void buildWalls() = 0;
  virtual void roofed() = 0;
  House *buildHouse() { return house; }

protected:
  House *house;
};

class CommonHouseBuild : public HouseBulder {
public:
  void buildBasic() override { house->basic = "Common Basic"; }

  void buildWalls() override { house->basic = "Common Walls"; }

  void roofed() override { house->basic = "Common roofed"; }
};

class HightHouseBuild : public HouseBulder {
public:
  void buildBasic() override { house->basic = "Hight Basic"; }

  void buildWalls() override { house->basic = "Hight Walls"; }

  void roofed() override { house->basic = "Hight roofed"; }
};

class HouseDirector {
public:
  virtual House *construct(HouseBulder *build) = 0;
};

class CommonDirector : public HouseDirector {
public:
  House *construct(HouseBulder *build) override {
    build->buildBasic();
    build->buildWalls();
    build->roofed();

    return build->buildHouse();
  }
};

int main() {
  CommonDirector *director = new CommonDirector;
  CommonHouseBuild *commonHouseBuild = new CommonHouseBuild;
  HightHouseBuild *hightHouseBuild = new HightHouseBuild;

  House *commonHouse = director->construct(commonHouseBuild);
  House *hightHouse = director->construct(hightHouseBuild);

  commonHouse->display();
  hightHouse->display();

  return 0;
}
