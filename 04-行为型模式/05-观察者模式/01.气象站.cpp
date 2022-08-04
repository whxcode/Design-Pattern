/*************************************************************************
> File Name: 04-行为型模式/05-观察者模式/01.气象站.cpp
> Author: root
> Mail:
> Created Time: 2022年08月03日 星期三 20时37分51秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Observe {
public:
  virtual void update(double temperature, double pressure, double humidity) = 0;
};

class Google : public Observe {

public:
  void update(double temperature, double pressure, double humidity) override {
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;

    display();
  }

  void display() {
    cout << "Google temperature:" << temperature << endl;
    cout << "Google pressure:" << pressure << endl;
    cout << "Google humidity:" << humidity << endl;
  }

private:
  double temperature;
  double pressure;
  double humidity;
};

class BinYin : public Observe {
public:
  void update(double temperature, double pressure, double humidity) override {
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;

    display();
  }

  void display() {
    cout << "BinYin temperature:" << temperature << endl;
    cout << "BinYin pressure:" << pressure << endl;
    cout << "BinYin humidity:" << humidity << endl;
  }

private:
  double temperature;
  double pressure;
  double humidity;
};

class Souguo : public Observe {
public:
  void update(double temperature, double pressure, double humidity) override {
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;

    display();
  }

  void display() {
    cout << "Souguo temperature:" << temperature << endl;
    cout << "Souguo pressure:" << pressure << endl;
    cout << "Souguo humidity:" << humidity << endl;
  }

private:
  double temperature;
  double pressure;
  double humidity;
};

class Subject {
public:
  virtual void attach(Observe *obs) = 0;
  virtual void remove(Observe *obs) = 0;
  virtual void notify(double temperature, double pressure, double humidity) = 0;
};

class WeatherData : public Subject {
public:
  WeatherData() { obs.clear(); }
  ~WeatherData() {
    for (auto it : obs) {
      delete it;
    }
  }

public:
  void attach(Observe *obs) override { this->obs.push_back(obs); }
  void remove(Observe *obs) override { this->obs.remove(obs); }
  void notify(double temperature, double pressure, double humidity) override {
    for (auto it : obs) {
      it->update(temperature, pressure, humidity);
    }
  }

private:
  list<Observe *> obs;
};

int main() {
  WeatherData *weather = new WeatherData;
  Souguo *s = new Souguo;
  weather->attach(new Google);
  weather->attach(new BinYin);
  weather->attach(s);

  weather->notify(10.1, 12.2, 1.2);

  weather->remove(s);
  cout << endl;
  weather->notify(12.1, 12.2, 1.2);

  return 0;
}
