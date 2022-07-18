/*************************************************************************
> File Name: 06-adapter/03.类适配器.cpp
> Author: root
> Mail:
> Created Time: 2022年07月18日 星期一 21时55分55秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;
struct VoltageV5 {
public:
  virtual int output() = 0;
};

struct VoltageV220 {
public:
  int output() {
    cout << "v 220" << endl;
    return 220;
  }
};

struct VoltageAdapter : public VoltageV220, VoltageV5 {
public:
  int output() override {
    int v = VoltageV220::output();

    return v / 44;
  }
};

struct Phone {
public:
  void charging(VoltageV5 *v) {
    int voltage = v->output();

    cout << "phone charge " << voltage << endl;
    ;
  }
};

int main() {
  Phone *phone = new Phone;
  VoltageAdapter *v5 = new VoltageAdapter;

  phone->charging(v5);

  delete v5;
  delete phone;

  return 0;
}
