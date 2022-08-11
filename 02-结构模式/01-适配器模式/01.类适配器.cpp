/*************************************************************************
> File Name: 01.类适配器.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月11日 星期四 20时52分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Voltage {
  public:
    virtual int output() =0;

};
class Voltage220V {
  public:
    int output220() {
      return 220;
    }    
};


class Voltage5V:public Voltage,private Voltage220V  {
  public:
    int output() override {
      return this->output220() /(  (this->output220() / 5) );
    }

};

class Phone {
  public:
    void charge(Voltage*v) {
      cout << "charge:" <<v->output() <<endl;
    }
  
};

int main(){
  Phone* phone = new Phone();
  Voltage* v5 = new Voltage5V;

  phone->charge(v5);

  return 0;
}
