/*************************************************************************
> File Name: 03-结构模式/07-代理模式/01.静态代理.cpp
> Author: root
> Mail:
> Created Time: 2022年07月31日 星期日 21时09分20秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Teach {
public:
  virtual void goToClass() = 0;
};

class Teacher : public Teach {
public:
  void goToClass() override { cout << "Teacher when go to class?" << endl; }
};

class Proxy : public Teach {
public:
  Proxy(Teach *teach) { this->teach = teach; }

public:
  void goToClass() override {
    cout << "代理对象正在:" << endl;
    teach->goToClass();
  }

private:
  Teach *teach;
};

int main() {
  Teach *teach = new Teacher();
  Proxy *proxy = new Proxy(teach);

  proxy->goToClass();

  delete proxy;
  delete (Teacher *)teach;

  return 0;
}
