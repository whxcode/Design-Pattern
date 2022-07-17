/*************************************************************************
> File Name: 01-CreatePattern/20.原型模式.羊.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 18时41分45秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Clone {
public:
};

struct Sheep {
public:
  Sheep(string n, int id, int a) : name(n), age(a) { this->id = new int(id); }

public:
  void print() {
    cout << "id:" << *id << "\tname:" << name << "age:" << age << endl;
  }
  Sheep *clone() {
    Sheep *s = new Sheep("", 0, 0);

    *s = *this;
    return s;
  }

public:
  string name;
  int age;
  int *id;
};

int main() {
  Sheep *s = new Sheep("xh", 10, 10);
  Sheep *ss = s->clone();


  *ss->id = 100;

  s->print();
  ss->print();

  return 0;
}
