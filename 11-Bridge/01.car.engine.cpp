/*************************************************************************
> File Name: 11-Bridge/01.car.engine.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 08时57分08秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Engine {
public:
  virtual void worker() = 0;
};

class E4400cc : public Engine {
public:
  void worker() override { cout << "i'm is E4400cc" << endl; }
};

class Me262 : public Engine {
public:
  void worker() override { cout << "i'm is Me262" << endl; }
};

class Car {
public:
  Car(Engine *engine) { this->engine = engine; }

public:
  virtual void worker() = 0;

public:
  void setEngin(Engine *engine) { this->engine = engine; }

protected:
  Engine *engine;
};

class WBM5 : public Car {
public:
  WBM5(Engine *e) : Car(e) {}

public:
  void worker() override { engine->worker(); }
};

class WBM6 : public Car {
public:
  WBM6(Engine *e) : Car(e) {}

public:
  void worker() override { engine->worker(); }
};

int main() {
  E4400cc *e4400cc = new E4400cc;
  Me262 *me262 = new Me262;

  WBM5 *wbw5 = new WBM5(e4400cc);
  WBM6 *wbw6 = new WBM6(me262);

  wbw5->worker();
  wbw6->worker();
  wbw5->setEngin(me262);
  cout << endl;
  wbw5->worker();

  delete e4400cc;
  delete  me262;
  delete wbw5;
  delete wbw6;

  return 0;
}
