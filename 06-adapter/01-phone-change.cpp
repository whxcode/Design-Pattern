/*************************************************************************
> File Name: 01-phone-change.cpp
> Author:
> Mail:
> Created Time: 2022年07月09日 星期六 08时45分34秒
 ************************************************************************/

#include <iostream>
using namespace std;
/*
class V5 {
  public:
    void useV5() {
      cout <<"使用了 5v 电压" <<endl;

    }

};
*/

class V220 {
public:
  int useV220() {
    cout << "使用了 v220 电压" << endl;
    return 220;
  }
};

class V5 {

public:
  virtual int useV5() = 0;
};

class Adapter : public V5 {
public:
  Adapter(V220 *v220) : v220(v220) {}
  ~Adapter() { delete this->v220; }
  virtual int useV5() override {
    this->v220->useV220();

    return 5;
  }

private:
  V220 *v220;
};

class IPhone {
public:
  IPhone(V5 *v5) : v5(v5) {}
  ~IPhone() {
    if (this->v5 != NULL) {
      delete this->v5;
    }
  }

  int charge() {
    cout << "Iphone on charge" << endl;
    return this->v5->useV5();
  }

private:
  V5 *v5;
};

int main() {
  IPhone *phone = new IPhone(new Adapter(new V220));
  cout << phone->charge() << endl;
  ;
  return 0;
}
