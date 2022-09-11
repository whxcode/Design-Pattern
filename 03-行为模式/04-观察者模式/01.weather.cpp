/*************************************************************************
> File Name: 01.weather.cpp
> Author: 
> Mail: 
> Created Time: 2022年09月11日 星期日 18时13分10秒
 ************************************************************************/

#include<iostream>
#include <list>

using namespace std;


class Observer {
  public:
    virtual void update(double temperature,double  pressure,double humidity) = 0;
};

class Subject {
  public:
    virtual void notify() = 0;
    virtual void add(Observer *o) = 0;
    virtual void remove(Observer *o) = 0;
    virtual void update(double temperature,double  pressure,double humidity) = 0;
};

class Weather :public Subject {
  public:
    Weather() {
      obs.clear();
    }
  public:
    void notify() override {
      for(auto it : obs) {
        it->update( temperature,  pressure,  humidity);
      }
    }

    void add(Observer *o) override {
      obs.push_back(o);
    }

    void remove(Observer *o) override {
      obs.remove(o);
    }

    void update(double temperature, double pressure, double humidity) override {
      this->temperature = temperature;
      this->pressure = pressure;
      this->humidity = humidity;
    }
  private:
    list<Observer *> obs;
    double temperature;
    double pressure;
    double humidity;
};


class Google :public Observer {
  public:
    void update(double temperature,double  pressure,double humidity) {
      cout << "Google:";
      cout << "temperature:" << temperature <<endl;
      cout << "pressure:" << pressure <<endl;
      cout << "humidity:" << humidity <<endl;
      cout << "Google end" << endl;
      cout << endl;
    }
};

class HuaWei :public Observer {
  public:
    void update(double temperature,double  pressure,double humidity) {
      cout << "HuaWei:";
      cout << "temperature:" << temperature <<endl;
      cout << "pressure:" << pressure <<endl;
      cout << "humidity:" << humidity <<endl;
      cout << "HuaWei end" << endl;
    }
};



int main(){
  Weather* w = new Weather;

  w->add(new Google);

  w->add(new HuaWei);


  w->update(20, 10, 10);

  w->notify();


  return 0;
}
