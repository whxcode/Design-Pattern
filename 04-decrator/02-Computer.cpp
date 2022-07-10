/*************************************************************************
> File Name: 02-Computer.cpp
> Author:
> Mail:
> Created Time: 2022年07月10日 星期日 11时15分33秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Computer {
public:
  virtual void worke() const = 0;
};

class HP : public Computer {
public:
  virtual void worke() const { cout << "HP worke" << endl; };
};

/**
 * 装饰一个类.
 *
 * */
class HPANDMAC : public Computer {
public:
  HPANDMAC(Computer *c) : computer(c) {}
  ~HPANDMAC() { delete this->computer; }
  virtual void worke() const {
    cout << "Mac worke" << endl;
    cout << "HP worke" << endl;
  };

private:
  Computer *computer;
};

int main() {
  Computer *computer = new HP();
  computer->worke();

  computer  = new HPANDMAC(computer);

  computer->worke();

  return 0;
}
