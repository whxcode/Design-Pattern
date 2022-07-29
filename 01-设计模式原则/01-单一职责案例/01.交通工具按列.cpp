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

class Vehicle {
public:
  void run(string name) { cout << name << "在公路上运行..." << endl; }
};

int main() { 
  Vehicle *vehicle = new Vehicle();
  vehicle->run("摩托车");
  vehicle->run("汽车");
  vehicle->run("飞机");

  return 0; }
