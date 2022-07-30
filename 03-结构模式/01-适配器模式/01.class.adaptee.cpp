/*************************************************************************
> File Name: 03-结构模式/01-适配器模式/01.class.adaptee.cpp
> Author: root
> Mail:
> Created Time: 2022年07月30日 星期六 15时55分28秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Voltage5V {
public:
  virtual int outputV5() = 0;
};

class VoltageV220 {
public:
  int outputV220() {
    // 坐落一系列的负责运算。
    return 220;
  }
};

class AdapterV5 : public Voltage5V, VoltageV220 {
public:
  int outputV5() override {
    int v = outputV220();

    return v / (v / 5);
  }
};

int main() {
  VoltageV220 *v220 = new VoltageV220;
  AdapterV5 *v5 = new AdapterV5();

  cout << endl;
  cout << "voltage:" << v5->outputV5() << endl;
  cout << endl;

  return 0;
}
