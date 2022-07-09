/*************************************************************************
> File Name: 02-mind-furniture.cpp
> Author:
> Mail:
> Created Time: 2022年07月07日 星期四 20时48分04秒
 ************************************************************************/

#include <iostream>
#include <time.h>
using namespace std;

class TV {
public:
  void On() { cout << "TV 打开了" << endl; }

  void Off() { cout << "TV 关闭了" << endl; }
};

class MicroPhone {
public:
  void On() { cout << "MicroPhone 打开了" << endl; }

  void Off() { cout << "MicroPhone 关闭了" << endl; }
};

class AirConditioner {
public:
  void On() { cout << "AirConditioner 打开了" << endl; }

  void Off() { cout << "AirConditioner 关闭了" << endl; }
};

class HomePlayer {
public:
  HomePlayer(TV *tv, MicroPhone *microPhone, AirConditioner *airCondition)
      : tv(tv), microPhone(microPhone), airCondition(airCondition){};
  void doKTV() {
    this->tv->On();
    this->microPhone->On();
    this->airCondition->Off();
  }

  void doSleep() {
    this->tv->Off();
    this->microPhone->Off();
    this->airCondition->On();
  }

private:
  TV *tv;
  MicroPhone *microPhone;
  AirConditioner *airCondition;
};

int main() {

  HomePlayer *player =
      new HomePlayer(new TV, new MicroPhone, new AirConditioner);
  player->doKTV();
  cout << "之后\n";
  player->doSleep();
  return 0;
}
