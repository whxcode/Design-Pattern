/*************************************************************************
> File Name: 04.phone.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月27日 星期六 21时45分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Phone{
  public:
    virtual void call() =0;
};

class Brand {
  public:
    ~Brand(){
      delete phone;
    }
  public:
    virtual void call() = 0;
  protected:
    Phone* phone;

};


class XiaoMI:public Brand {
  public:
    XiaoMI(Phone*p) {
      phone = p;
    }
  public:
    void call() override {
      cout <<"XiaoMI";
      phone->call();
    }

};

class Vivo:public Brand {
  public:
    Vivo(Phone*p) {
      phone = p;
    }
  public:
    void call() override {
      cout <<"Vivo";
      phone->call();
    }
};

class FoolPhone:public Phone {
  public:
    void call() override {
      cout << "FoolPhone" <<endl;
    }
};

class SmartPhone:public Phone {
  public:
    void call() override {
      cout << "SmartPhone" <<endl;
    }
};

class NormalPhone:public Phone {
  public:
    void call() override {
      cout << "NormalPhone" <<endl;
    }
};

void worker(Brand* w) {

  w->call();

  delete w;
}

int main(){
  worker(new XiaoMI(new FoolPhone));
  worker(new XiaoMI(new NormalPhone));
  worker(new XiaoMI(new SmartPhone));
  cout <<endl;

  worker(new Vivo(new FoolPhone));
  worker(new Vivo(new NormalPhone));
  worker(new Vivo(new SmartPhone));
return 0;
}
