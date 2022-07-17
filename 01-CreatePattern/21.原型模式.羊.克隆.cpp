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
  Sheep(string n, int a) : name(n), age(a) {}

public:
  void print() { cout << "name:" << name << "age:" << age << endl; }
  Sheep *clone() { return new Sheep(name, age); }

public:
  string name;
  int age;
};

int main() {
  Sheep *s = new Sheep("xh", 10);

  for (int i = 0; i < 10; ++i) {
    Sheep *ss = ss->clone();

    ss->print();
  }

  return 0;
}
