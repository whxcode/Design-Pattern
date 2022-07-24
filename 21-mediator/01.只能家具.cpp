/*************************************************************************
> File Name: 21-mediator/01.只能家具.cpp
> Author: root
> Mail:
> Created Time: 2022年07月23日 星期六 21时15分28秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Colleague;

class Mediator {
public:
  virtual void add(string name, Colleague *colleague) = 0;
  virtual void getMessage(int stateChange, string name) = 0;
  virtual void sendMessage() = 0;
};

class Colleague {
public:
  Colleague(Mediator *mediator, string name) {
    this->mediator = mediator;
    this->name = name;
  }

public:
  Mediator *getMediator() { return mediator; }
  virtual void sendMessage(int stateChange) = 0;
  virtual void start() = 0;

public:
  string name;

private:
  Mediator *mediator;
};

class Alarm : public Colleague {
public:
  Alarm(Mediator *mediator, string name) : Colleague(mediator, name) {
    mediator->add(name, this);
  }

public:
  void sendAlarm(int stateChange) { sendMessage(stateChange); }
  void sendMessage(int stateChange) override {
    getMediator()->getMessage(stateChange, this->name);
  }
  void start() override { cout << "丁丁定~~~~" << endl; }
};

class ConcreteMediator : public Mediator {
public:
  ConcreteMediator() { mediators.clear(); }

public:
  void add(string name, Colleague *colleague) override {
    mediators.insert(make_pair(name, colleague));
  }
  // 根据得到的消息，完成对应的任务
  void getMessage(int stateChange, string name) override {
    auto it = mediators.find(name);
    it->second->start();
  }

  void sendMessage() override {}

private:
  map<string, Colleague *> mediators;
};

void test01() {
  Mediator *mediator = new ConcreteMediator();
  Alarm *alarm = new Alarm(mediator, "alarm");

  alarm->sendAlarm(10);



}

int main() {

  test01();
  return 0;
}
