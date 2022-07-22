/*************************************************************************
> File Name: 03-proxy/05.静态代理.cpp
> Author: root
> Mail:
> Created Time: 2022年07月22日 星期五 21时04分48秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;
class Teach {
public:
  virtual void teach() = 0;
};

class Teacher : public Teach {
public:
  void teach() override { cout << "老师在教课" << endl; }
};

class ProxyTeacher : public Teach {
public:
  ProxyTeacher(Teach *t) : t(t) {}

public:
  void teach() override {
    cout << "代理:";
    t->teach();
  }

private:
  Teach *t;
};

int main() {
  Teacher *t = new Teacher;
  ProxyTeacher *p = new ProxyTeacher(t);

  p->teach();

  delete t;
  delete p;

  return 0;
}
