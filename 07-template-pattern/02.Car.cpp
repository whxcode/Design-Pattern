/*************************************************************************
> File Name: 07-template-pattern/02.Car.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 13时46分02秒
 ************************************************************************/

#include <iostream>
using namespace std;
class MakeCar {
private:
  virtual void makeHead() = 0;
  virtual void makeBody() = 0;
  virtual void makeTail() = 0;

public:
  void make() {
    makeHead();
    this->makeBody();
    makeTail();
  }
};

class Jeep : public MakeCar {
private:
  void makeHead() override { cout << "Jeep Head" << endl; }
  void makeBody() override { cout << "Jeep Body" << endl; }
  void makeTail() override { cout << "Jeep Tail" << endl; }
};

class WBM : public MakeCar {
private:
  void makeHead() override { cout << "WBM Head" << endl; }
  void makeBody() override { cout << "WBM Body" << endl; }
  void makeTail() override { cout << "WBM Tail" << endl; }
};

int main() {
  MakeCar *car = new Jeep;
  car->make();
  delete (Jeep *)car;

  car = new WBM;
  car->make();

  delete (WBM *)car;


  return 0;
}
