/*************************************************************************
> File Name: 01.normal.cpp
> Author:
> Mail:
> Created Time: 2022年08月14日 星期日 15时49分23秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Subject {
public:
  virtual string request() = 0;
};

class RealSubject : public Subject {
public:
  string request() override { return "real subject"; }
};

class ProxySubject : public Subject {
public:
  ProxySubject(Subject *sub) { this->sub = sub; }
  ~ProxySubject() { delete sub; }

public:
  string request() override { return "proxy subject" + sub->request(); }

private:
  Subject *sub;
};

int main() {

  Subject *sub = new ProxySubject(new RealSubject);
  cout << sub->request() << endl;

  return 0;
}
