/*************************************************************************
> File Name: 06-adapter/02.computer.cpp
> Author: root
> Mail:
> Created Time: 2022年07月15日 星期五 22时59分32秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Electron {
public:
  virtual void useCharge() = 0;
};

class V220 : public Electron {
public:
  void useCharge() { cout << "使用 v220" << endl; }
};

class V18 {
public:
  virtual void useCharge(Electron *v2) = 0;
};

class Adapter : public V18 {
public:
  void useCharge(Electron *v) override {
    v->useCharge();
    cout << "转 v5" << endl;
  }
};

int main() {
  Electron *v2 = new V220;

  v2->useCharge();
  cout << endl;

  Adapter* apt = new Adapter;

  apt->useCharge(v2);

  return 0;
}
