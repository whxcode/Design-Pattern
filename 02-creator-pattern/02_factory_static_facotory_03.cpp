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
    static Pizza * createPizza(int type) {
      if(type == 0) {
        return new BjChessPizza();

      } else if(type == 1) {

        return new BjGreekPizza();

      }   else if(type == 2) {

        return new CdPepperPizza();
      }

      return NULL;
    }

};

// 如果新增一个 Pizza 这个函数里面也要修改

void worker(int type) {
  Pizza *pizza = Factory::createPizza(type);

  if(pizza == NULL) {
    return;
  }

  pizza->prepare();
  pizza->cut();
  pizza->bake();
  pizza->box();

  free(pizza);
}

int main(){ 
  Factory s;

  worker(0);
  cout << endl;
  worker(1);

  cout << endl;
  worker(2);

  return 0;
}
