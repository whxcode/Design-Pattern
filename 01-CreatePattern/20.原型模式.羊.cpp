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

struct Sheep {
public:
  Sheep(string n, int id, int a ) : name(n), age(a) { this->id = new int(id); }

public:
  void print() {
    cout << "id:" << *id << "name:" << name << "age:" << age << endl;
  }

public:
  string name;
  int age;
  int *id;
};

int main() {
  Sheep *s = new Sheep("xh", 100,10);

  for (int i = 0; i < 10; ++i) {
    Sheep *ss = new Sheep(s->name,*s->id, s->age);
    *ss->id = i;

    ss->print();

    delete ss;
  }

  cout << endl;

  s->print();

  delete s;

  return 0;
}
