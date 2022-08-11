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


class Voltage5V:public Voltage  {
  public:
    Voltage5V(Voltage220V *v) {
      this->v = v;
    }

    ~Voltage5V() {
      delete v;
    }

  public:
    int output() override {
      return this->v->output220() /(  (this->v->output220() / 5) );
    }
  private:
    Voltage220V *v;

};

class Phone {
  public:
    void charge(Voltage*v) {
      cout << "charge:" <<v->output() <<endl;
    }
  
};

int main(){
  Phone* phone = new Phone();
  Voltage5V* v5 = new Voltage5V(new Voltage220V);

  phone->charge(v5);

  delete v5;
  delete phone;

  return 0;
}
