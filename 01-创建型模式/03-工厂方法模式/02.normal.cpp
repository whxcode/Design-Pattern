/*************************************************************************
> File Name: 03-工厂方法模式/02.normal.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月10日 星期三 22时01分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Product {

};

class Creator  {
  public:
    virtual Product* make() =0;
};

class ProductA:public Product {
};

class ProductB:public Product {
};

class CreatorA:public Creator {
  Product * make() override {
    return new ProductB;
  }
  
};

class CreatorB:public Creator {
  Product * make() override {
    return new ProductA;
  }
  
};



void worke(Creator* creator) {
    delete  creator->make();
    delete  creator;
}

int main(){
  
  worke(new CreatorA);
  worke(new CreatorB);
  return 0;
}
