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
class Observer {
public:
  virtual void update(double temperature, double pressure, double humidity) = 0;
};

class Google : public Observer {
public:
  void update(double temperature, double pressure, double humidity) override {
    cout << "Google dispay" << endl;

    cout << "temperature:" << temperature << endl;
    cout << "pressure:" << pressure << endl;
    cout << "humidity:" << humidity << endl;

    cout << endl;
  }
};

class Vim : public Observer {
public:
  void update(double temperature, double pressure, double humidity) override {
    cout << "Vim dispay" << endl;

    cout << "temperature:" << temperature << endl;
    cout << "pressure:" << pressure << endl;
    cout << "humidity:" << humidity << endl;

    cout << endl;
  }
};

class Subject {
public:
  virtual void registerObserver(Observer *o) = 0;
  virtual void removeObserver(Observer *o) = 0;
  virtual void notify() = 0;
};

class WeatherData : public Subject {
public:
  WeatherData() { observers.clear(); }

public:
  void registerObserver(Observer *o) override { observers.push_back(o); }
  void removeObserver(Observer *o) override { observers.remove(o); }
  void notify() override {
    for (auto it : observers) {
      it->update(temperature, pressure, humidity);
    }
  }
  void update(double temperature, double pressure, double humidity)  { 
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;

    notify();
  }
  

private:
  list<Observer *> observers;
  double temperature;
  double pressure;
  double humidity;
};

void test01() {
  Google *google = new Google;
  Vim *vim = new Vim;

  WeatherData *weather = new WeatherData;
  weather->registerObserver(google);
  weather->registerObserver(vim);

  weather->update(10,20,30);

  weather->removeObserver(vim);
  weather->update(20,30,30);
  weather->removeObserver(google);

  weather->update(20,30,30);
}

int main() {

  test01();
  return 0;
}
