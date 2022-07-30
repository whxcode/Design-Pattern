#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Voltage {
public:
  virtual int output() = 0;
};

class VoltageV220 {
public:
  int output() {
    // 坐落一系列的负责运算。
    return 220;
  }
};

class AdapterV5 : public Voltage {
public:
  AdapterV5(VoltageV220 *v220) { this->v220 = v220; }

public:
  int output() override {
    int v = this->v220->output();

    return v / (v / 5);
  }

private:
  VoltageV220 *v220;
};

int main() {
  VoltageV220 *v220 = new VoltageV220;
  AdapterV5 *v5 = new AdapterV5(v220);

  cout << endl;
  cout << "voltage:" << v5->output() << endl;
  cout << endl;

  return 0;
}
