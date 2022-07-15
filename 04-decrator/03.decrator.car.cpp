/*************************************************************************
> File Name: 04-decrator/03.decrator.car.cpp
> Author: root
> Mail:
> Created Time: 2022年07月15日 星期五 22时27分33秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Car {
public:
  virtual void show() const = 0;
};

class KoreaCar : public Car {
public:
  void show() const override { cout << "可以在陆地上开车" << endl; }
};

class FlyCar : public Car {
public:
  FlyCar(Car *car) { this->car = car; }

public:
  void show() const override {
    cout << "可以在水下游泳" << endl;
    car->show();
  }

private:
  Car *car;
};

class SwimCar : public Car {
public:
  SwimCar(Car *car) { this->car = car; }

public:
  void show() const override {
    cout << "可以在天下🕊" << endl;
    car->show();
  }

private:
  Car *car;
};

int main() {
  Car *car = new KoreaCar();
  car->show();

  cout << endl;
  FlyCar *flyCar = new FlyCar(car);
  flyCar->show();

  cout << endl;
  SwimCar *swimCar = new SwimCar(flyCar);
  swimCar->show();
  return 0;
}
