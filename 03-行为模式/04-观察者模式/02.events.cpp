/*************************************************************************
  > File Name: 02.events.cpp
  > Author: 
  > Mail: 
  > Created Time: 2022年09月11日 星期日 18时36分24秒
 ************************************************************************/

#include<iostream>
#include <list>
#include <map>

using namespace std;

class Observer {
  public:
    virtual void update(double temperature,double  pressure,double humidity) = 0;
};

class Subject {
  public:
    virtual void notify(string name) = 0;
    virtual void on(string name,Observer *o) = 0;
    virtual void off(string name,Observer *o) = 0;
    virtual void update(double temperature,double  pressure,double humidity) = 0;
};

class Weather :public Subject {
  public:
    Weather() {
      obs.clear();
    }
    ~Weather() {
      for(auto it : obs) {
        delete it.second;
      }

    }
  public:
    void notify(string name) override {
      auto it = obs.find(name);

      if (it == obs.end()) {
        return;

      }

       for(auto itt : *it->second) {
          itt->update( temperature,  pressure,  humidity);
       }

    }

    void on(string name,Observer *o) override {
      auto it = obs.find(name);

      if (it != obs.end()) {
        it->second->push_back(o);
        return;;
      }

      list<Observer *> *l = new list<Observer*>;

        l->push_back(o);
      obs.insert(make_pair(name, l));
    }


    void off(string name,Observer *o) override {
      auto it = obs.find(name);

      if (it == obs.end()) {
        return;
      }

      it->second->remove(o);
    }

    void update(double temperature, double pressure, double humidity) override {
      this->temperature = temperature;
      this->pressure = pressure;
      this->humidity = humidity;
    }

  private:
    map<string,list<Observer *>* > obs;
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
  Google* g = new Google();
  HuaWei *h  = new HuaWei;

  w->on("google",g);
  w->on("google",h);

  w->update(20, 10, 10);


  w->notify("google");
  cout << "----" << endl;

  w->on("huawei",h);

  w->notify("huawei");

  delete w;
  delete g;
  delete h;


  return 0;
}
