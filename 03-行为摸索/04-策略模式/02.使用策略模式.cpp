/*************************************************************************
> File Name: 02.使用策略模式.cpp
> Author: 
> Mail: 
> Created Time: 2022年10月31日 星期一 22时34分15秒
 ************************************************************************/

#include<iostream>
using namespace std;
class FlyBehavior {
  public:
    virtual void fly() =0;
};

class BadFlyBehavior: public FlyBehavior {
  public:
    void fly() override{
      cout << "不太会飞"<< endl;
    }
};

class GoodFlyBehavior: public FlyBehavior {
  public:
    void fly() override{
      cout << "太会飞"<< endl;
    }
};


class Duck {
  public:
    Duck(FlyBehavior* f) {
      this->f = f;
    }
  public:
    virtual void quack() {
      cout << "嘎嘎叫" <<endl;
    }
    virtual void swim() {
      cout << "游泳"<< endl;
    }
    void fly() {
      this->f->fly();
    }
    virtual void display() =0;
  private:
    FlyBehavior* f;
};



class ＷildDuck :public Duck {

  public:
    ＷildDuck(FlyBehavior* f):Duck(f) {

    }
  public:
    void display() override {
      cout << "ＷildDuck" <<endl;
    }

};

class PekingDuck :public Duck {

  public:
    PekingDuck(FlyBehavior* f):Duck(f) {

    }
  public:
    void display() override {
      cout << "PekingDuck" <<endl;
    }
};

void worker(Duck *duck)  {
  duck->fly();
  delete duck;

}
int main(){
  worker(new ＷildDuck(new GoodFlyBehavior));
  worker(new PekingDuck(new BadFlyBehavior));
  return 0;
}
