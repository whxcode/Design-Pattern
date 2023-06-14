/*************************************************************************
> File Name: 01.abstrct.cpp
> Author: 
> Mail: 
> Created Time: Tue Jun  6 19:42:51 2023
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
  public:
    virtual void makeSound() = 0;
};

class Cat :public Animal {
  public:
    void makeSound() override {
      cout << (string)"!!" << endl;
    }
};

class Dog :public Animal {
  public:
    void makeSound() override {
      cout << (string)"xx" << endl;
    }
};

void test01() {
  Animal *ds[2] = {new Cat,new Dog};

  for(Animal* d : ds) {
    d->makeSound();
  }
}

double getTaxRate(double value,int type) {
  double total = value;
  if(type == 0) {
    total += total * 0.07;
  } else if(type == 1) {
    total += total * 0.5;
  }

  return total;
}

double getOrderTotal(double *orders,int size,int type) {
  double total = 0;

  for(int i = 0;i< size;++i) {
    total += *(orders + i);
  }



  return  getTaxRate(total,type);
}


void test02() {
  double orders[2] ={10,10};
  cout << getOrderTotal(orders,2,-1) << endl;; 
  cout << getOrderTotal(orders,2,1) << endl;; 
  cout << getOrderTotal(orders,2,0) << endl;; 

}

int main(){

  test02();

  return 0;
}
