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

class RoadVehicle {
public:
  void run(string name) { cout << name << "在公路上运行..." << endl; }
};

class AirVehicle {
public:
  void run(string name) { cout << name << "在水中运行..." << endl; }
};

class OverseaVehicle {
public:
  void run(string name) { cout << name << "在水中运行..." << endl; }
};

int main() {
  RoadVehicle *vehicle = new RoadVehicle();
  vehicle->run("摩托车");
  vehicle->run("汽车");

  AirVehicle *fly = new AirVehicle();
  fly->run("客机");
  fly->run("战斗机");

  return 0;
}
