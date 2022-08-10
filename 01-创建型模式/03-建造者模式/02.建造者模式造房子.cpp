/*************************************************************************
> File Name: 01-创建型模式/03-建造者模式/01.普通建造房子.cpp
> Author:
> Mail:
> Created Time: 2022年08月10日 星期三 21时00分03秒
 ************************************************************************/

#include <iostream>
using namespace std;

class House {
public:
  string basic;
  string walls;
  string roofed;
public:
  void display() {
    cout << "basic:" <<basic << ":walls:" << walls << ":roofed:" << roofed <<endl;
  }
};

class AbstractBuild {
  public:
    AbstractBuild() {
      house = new House;
    }
public:
  virtual void buildBasic() = 0;
  virtual void buildWalls() = 0;
  virtual void buildRoofed() = 0;

public:
  House *buildHouse() {
    buildBasic();
    buildWalls();
    buildRoofed();

    return house;
  }

protected:
  House *house;
};

class CommonBuild :public AbstractBuild {
  public:
    void buildBasic() override {
      this->house->basic = "common basic";
    }

    void buildWalls() override {
      this->house->basic = "common walls";
    }

    void buildRoofed() override {
      this->house->basic = "common roofed";
    }
};

class HightBuild :public AbstractBuild {
  public:
    void buildBasic() override {
      this->house->basic = "hight basic";
    }

    void buildWalls() override {
      this->house->basic = "hight walls";
    }

    void buildRoofed() override {
      this->house->basic = "hight roofed";
    }
};


class HouseDirector {
  public:
    House* constrcut(AbstractBuild* build) {
      build->buildBasic();
      build->buildWalls();
      build->buildRoofed();

      return build->buildHouse();
    }
  private:


};

int main() { 
  HouseDirector* director = new HouseDirector;
  CommonBuild* commonBuild = new CommonBuild;
  HightBuild* hightBuild = new HightBuild;

  House* house = director->constrcut(commonBuild);
  House* house1 = director->constrcut(hightBuild);

  house->display();
  house1->display();

  delete director;
  delete commonBuild;
  delete hightBuild;

  delete house;
  delete house1;

  return 0; }
