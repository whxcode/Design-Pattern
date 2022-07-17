/*************************************************************************
> File Name: 0-base/03.singleResponsibity.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 08时25分39秒
 ************************************************************************/

#include <iostream>
using namespace std;

// 交通工具类。
// 该类违反了单一职责的问题；
// 根据交通工具的方式不同，抽象一个基类，在有其它具体类实现。
struct Vehicle {
public:
  void run(string vehcle) { cout << "在公路上运行" << vehcle << endl; }
};

void test01() {
  Vehicle *vehcle = new Vehicle;
  vehcle->run("摩托");
  delete vehcle;
}

// 抽出了两个类。
struct RoadVehicle {
public:
  void run(string vehicle) { cout << "在公路上运行" << vehicle << endl; }
};

struct FlyVehicle {
public:
  void run(string vehicle) { cout << "在飞机上运行" << vehicle << endl; }
};

void test02() {
  RoadVehicle *motor = new RoadVehicle();
  FlyVehicle *jet = new FlyVehicle();

  motor->run("模特车");
  jet->run("战斗机");

  delete motor;
  delete jet;
}

// 将每一个方法遵守交单一职责。
struct Transport {
public:
  void roadRun() { cout << "road run" << endl; }
  void flyRun() { cout << "fly run" << endl; }
  void waterRun() { cout << "water run" << endl; }
};

void test03() {
  Transport *tool = new Transport();
  tool->flyRun();
  tool->roadRun();
  tool->waterRun();

  free(tool);
}

// 对于 c 语言
//
void doWorke(const char *name, void (*method)(const char *name)) {
  method(name);
}

void test04() {}

int main() {
  test04();
  // test03();
  // test02();
  // test01();
  return 0;
}
