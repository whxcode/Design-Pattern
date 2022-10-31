/*************************************************************************
> File Name: 01.传统方式.cpp
> Author: 
> Mail: 
> Created Time: 2022年10月31日 星期一 22时21分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
/***
 * 基本无法使用,因为不同的品种会重新重写很多方法
 *
 * */

class Duck {
  public:

    virtual void quack() {
      cout << "嘎嘎叫" <<endl;
    }

    virtual void swim() {
      cout << "游泳"<< endl;
    }
    virtual void fly() {
      cout << "我会飞" << endl;
    }
    virtual void display() =0;
};

class ＷildDuck :public Duck {

  public:
    void display() override {
      cout << "ＷildDuck" <<endl;
    }

};

class PekingDuck :public Duck {

  public:
    void fly() override{
      cout << "我是 PekingDuck ,不会飞"<< endl;
    }
    void display() override {
      cout << "PekingDuck" <<endl;
    }
};

class ToyDuck :public Duck {

  public:
    void fly() override{
      cout << "我是 ToyDuck ,不会飞"<< endl;
    }
    void swim() override {
      cout << "我是 ToyDuck ,不会游泳"<< endl;
    }

    void quack() override {
      cout << "我是 ToyDuck ,不会叫"<< endl;
    }
    void display() override {
      cout << "ToyDuck" <<endl;
    }
};

int main(){
return 0;
}
