/*************************************************************************
> File Name: 02-virtual.cpp
> Author:
> Mail:
> Created Time: 2022年07月03日 星期日 17时03分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public:
  virtual void speak();
};

void Animal::speak() { printf("动物说话了.\n"); };

class Dog : public Animal {
public:
  void speak() override {
    printf("汪汪.\n");
    
    this->Animal::speak();
  }
};

class Cat : public Animal {
public:
};

class Grafiic : public Animal {
public:
  void speak();
};

void Grafiic::speak() {

  printf("长颈鹿说话了.\n");
}

int console() {
  Animal *a1 = new Dog();

  a1->speak();

  delete a1;
  // 本类没有实现，就调用父类的 virtual 同名函数，前提是父类能构造出。
  a1 = new Cat();
  a1->speak();

  delete a1;
  a1 = new Grafiic();
  a1->speak();

  delete a1;

  return 0;
}
