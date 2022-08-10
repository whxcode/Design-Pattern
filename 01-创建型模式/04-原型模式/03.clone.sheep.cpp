/*************************************************************************
> File Name: 04-原型模式/03.clone.sheep.cpp
> Author:
> Mail:
> Created Time: 2022年08月10日 星期三 22时09分31秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Prototype {
public:
  virtual Prototype *clone() = 0;
};

class Sheep : public Prototype {
public:
  Prototype *clone() override {
    Sheep *s = new Sheep;
    *s = *this;
    return s;
  }

public:
  string name;
  int age;
};

class Cat : public Prototype {
public:
  Prototype *clone() override {
    Cat *s = new Cat;
    *s = *this;
    return s;
  }

public:
  string eat;
  string play;
};



void test01() {
  Sheep*s1 = new Sheep;
  Cat*c1 = new Cat;

  s1->age = 10;
  s1->name ="s1";

  c1->eat = "shark";
  c1->play ="ball";


  Sheep* s2 = (Sheep*)s1->clone();
  Cat* c2 = (Cat *)c1->clone();

  cout << c2->play <<endl;
  cout << s1->age <<endl;
}

int main() {
  test01();
  return 0;
}
