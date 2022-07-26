/*************************************************************************
> File Name: 02-结构模式/01.类装饰器.cpp
> Author: root
> Mail:
> Created Time: 2022年07月26日 星期二 22时14分47秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Adaptee {
public:
  int request() { return 100; }
};

class Target {
public:
  virtual int useData() = 0;
};

class Adapter : public Adaptee, Target {
public:
  int useData() override { return this->request() / 10; }
};

class V5 : public Adaptee, Target {
public:
  int useData() override { return this->request() / (this->request() / 5); }
};

int main() {
  Adapter *target = new Adapter;
  V5 *v5 = new V5;

  cout << target->useData() << endl;
  cout << v5->useData() << endl;

  return 0;
}
