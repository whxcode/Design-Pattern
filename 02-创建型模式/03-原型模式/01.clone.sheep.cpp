/*************************************************************************
> File Name: 02-创建型模式/03-原型模式/01.clone.sheep.cpp
> Author: root
> Mail:
> Created Time: 2022年07月30日 星期六 11时46分58秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Sheep {
public:
  Sheep(string name, int age) {
    this->name = name;
    this->age = age;
  }

public:
  Sheep *clone() {
    Sheep *sheep = new Sheep(this->name, this->age);
    *sheep = *this;

    return sheep;
  }
  void display() {
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
  }

public:
  int age;
  string name;
};

int main() {
  Sheep *s1 = new Sheep("王恒星", 19);
  Sheep *s2 = s1->clone();

  s1->display();
  s2->display();

  delete s1;
  delete s2;

  return 0;
}
