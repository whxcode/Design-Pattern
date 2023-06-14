/*************************************************************************
> File Name: 01.transport.cpp
> Author: 
> Mail: 
> Created Time: Wed Jun  7 19:36:53 2023
 ************************************************************************/

#include<iostream>
using namespace std;

class Transport {
  public: 
    virtual void delivery() = 0;
};

class Logisitics {
  public:
    virtual Transport* createTransport() = 0;
};


class Truck :public Transport {
  public: 
    void delivery() override {
      cout << "Truck" << endl;
    }
};

class SeaShip :public Transport {
  public: 
    void delivery() override {
      cout << "SeaShip" << endl;
    }
};

class RoadLogisitics: public Logisitics {
  public:
    Transport * createTransport() override {

      return new Truck;
    }
};

class SeaLogisitics: public Logisitics {
  public:
    Transport * createTransport() override {

      return new SeaShip;
    }
};

void work(Logisitics *l) {
  Transport* t = l->createTransport();

  t->delivery();
  delete  t;

}

int main(){
  RoadLogisitics *r = new RoadLogisitics();
  SeaLogisitics *s = new SeaLogisitics();

  work(r);
  work(s);

  delete r;
  delete s;

  return 0;
}
