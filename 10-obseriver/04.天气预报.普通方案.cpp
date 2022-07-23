/*************************************************************************
> File Name: 10-obseriver/04.天气预报.普通方案.cpp
> Author: root
> Mail:
> Created Time: 2022年07月23日 星期六 15时57分30秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

class CurrentCondition {
public:
  void update(double temperature, double pressure, double humidity) {
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;
    display();
  }
  void display() {
    cout << "temperature:" << temperature << endl;
    cout << "pressure:" << pressure << endl;
    cout << "humidity:" << humidity << endl;
  }

private:
  double temperature;
  double pressure;
  double humidity;
};

class WeatherData {
public:
  WeatherData(CurrentCondition *d) { this->d = d; }

public:
  void update(double temperature, double pressure, double humidity) {
    d->update(temperature, pressure, humidity);
  }

private:
  CurrentCondition *d;
};

void test01() {
  CurrentCondition *c  = new CurrentCondition;
  WeatherData *w = new WeatherData(c);

  w->update(10,20l,30);
  cout << endl;
  w->update(102l,20l,30);
}
int main() {

  test01();
  return 0;
}
