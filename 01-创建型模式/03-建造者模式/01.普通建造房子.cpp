/*************************************************************************
> File Name: 01-创建型模式/03-建造者模式/01.普通建造房子.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月10日 星期三 21时00分03秒
 ************************************************************************/

#include<iostream>
using namespace std;

class AbstractHouse {
  public:
    virtual void buildBasic() = 0;
    virtual void buildWalls() = 0;
    virtual void buildRoofed() = 0;

    void build() {
      buildBasic();
      buildWalls();
      buildRoofed();
    }
};


class CommonHouse: public AbstractHouse {
  void buildBasic() override {
    cout << "basic CommonHouse" <<endl;
  }

  void buildWalls() override {
    cout << "walls CommonHouse" <<endl;
  }

  void buildRoofed() override {
    cout << "roofed CommonHouse" <<endl;
  }

};


class HightHouse: public AbstractHouse {
  void buildBasic() override {
    cout << "basic HightHouse" <<endl;
  }

  void buildWalls() override {
    cout << "walls HightHouse" <<endl;
  }

  void buildRoofed() override {
    cout << "roofed HightHouse" <<endl;
  }

};

int main(){
  return 0;
}
