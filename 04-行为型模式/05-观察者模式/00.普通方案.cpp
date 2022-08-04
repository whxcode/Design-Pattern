/*************************************************************************
> File Name: ./04-行为型模式/05-观察者模式/00.不同方案.cpp
> Author: root
> Mail:
> Created Time: 2022年08月03日 星期三 21时27分35秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class CurrentConditions {
public:
  void update(double temperature, double pressure, double humidity) {
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;
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
  WeatherData(CurrentConditions *c) { this->c = c; }

public:
  void dataChange(double temperature, double pressure, double humidity) {
    c->update(temperature, pressure, humidity);
  }

private:
  CurrentConditions *c;
};

int main() {
  CurrentConditions *c = new CurrentConditions;
  WeatherData *weatherData = new WeatherData(c);

  weatherData->dataChange(10.1, 12.2, 1.2);
  c->display();

  cout << endl;
  weatherData->dataChange(12.1, 12.2, 1.2);
  c->display();

  return 0;
}
