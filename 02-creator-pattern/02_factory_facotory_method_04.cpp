/*************************************************************************
> File Name: 02-creator-pattern/02-工厂模式-常规做法.cpp
> Author: 
> Mail: 
> Created Time: Mon May 29 21:06:28 2023
 ************************************************************************/

#include<iostream>
using namespace std;

class Pizza {
  public:
    virtual void prepare() = 0;

    void cut() {
      cout << "切割" << endl;
    }

    void bake() {
      cout << "烘烤" << endl;
    }

    void box() {
      cout << "打包" << endl;
    }
};


class BjChessPizza :public Pizza {
  void prepare() override {
    cout << "prepare ChessPizza" << endl;
  }
};

class BjGreekPizza :public Pizza {
  void prepare() override {
    cout << "prepare GreekPizza" << endl;
  }
};

class CdPepperPizza :public Pizza {
  void prepare() override {
    cout << "prepare PepperPizza" << endl;
  }
};

class Factory {
  public:
    virtual Pizza * createPizza(int type)  = 0;

};

class BjFactory: public Factory {
  public:
     Pizza * createPizza(int type) override {
      if(type == 0) {
        return new BjChessPizza();

      } else if(type == 1) {

        return new BjGreekPizza();
      }   
      return NULL;

    }

};

class CdFactory: public Factory {
  public:
     Pizza * createPizza(int type) override {
       return new CdPepperPizza;
    }

};

// 如果新增一个 Pizza 这个函数里面也要修改

void worker(Factory *f,int type) {
  Pizza *pizza = f->createPizza(type);

  if(pizza == NULL) {
    return;
  }

  pizza->prepare();
  pizza->cut();
  pizza->bake();
  pizza->box();

  free(pizza);
  free(f);
}

int main(){ 

  worker(new BjFactory ,0);
  cout << endl;
  worker(new BjFactory,1);

  cout << endl;
  worker(new CdFactory,2);

  return 0;
}
