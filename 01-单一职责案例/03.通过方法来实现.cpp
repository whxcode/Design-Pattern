/*************************************************************************
> File Name: 01-单一职责案例/01.交通工具按列.cpp
> Author: root
> Mail:
> Created Time: 2022年07月26日 星期二 20时49分36秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

/**
 * 在方法上准守了单一职责。
 *
 * */
class Vehicle {
public:
  void runRoad(string name) { cout << name << "在公路上运行..." << endl; }
  void runAir(string name) { cout << name << "在公路上运行..." << endl; }
  void runSea(string name) { cout << name << "在公路上运行..." << endl; }
};

int main() {
  Vehicle *vehicle = new Vehicle();

  vehicle->runRoad("摩托车");
  vehicle->runAir("战斗机");
  vehicle->runSea("轮船");

  return 0;
}
