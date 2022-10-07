/*************************************************************************
  > File Name: 01.smart.cpp
  > Author: 
  > Mail: 
  > Created Time: 2022年09月11日 星期日 19时14分44秒
 ************************************************************************/

#include<iostream>
#include<map>


#define ALARM_ON 0
#define ALARM_OFF 1
#define TV_ON 2
#define TV_OFF 3

using namespace std;

class Colleague;
class Mediator {
  public:
    virtual void on(string name,Colleague*c) =0;
    virtual void getMessage(int state,string name) = 0;
};

class Colleague {
  public:
      Colleague(Mediator* m,string name) {
      mediator = m;
      this->name = name;
    }
  public:
    virtual void sendMessage(int state) = 0;
    virtual void execute() {}
  public:
    Mediator* getMediator() {
      return mediator;
    }
  public:
    string name;
  private:
    Mediator* mediator;
};


class Alarm :public Colleague {
  public:
    Alarm(Mediator *m,string name):Colleague(m,name) {
      m->on(name,this);
    }
  public:
    void sendAlarm(int state) {
      sendMessage(state);
    }
    void sendMessage(int state) {
      this->getMediator()->getMessage(state,this->name);
    }
};

class Controll :public Mediator {
  public:
    Controll() {
      obs.clear();
    }
  public:
    void on(string name, Colleague *c) override {
      obs.insert(make_pair(name, c));
    }

    void getMessage(int state, string name) override {
      if(state == ALARM_ON) {


      }
    

    }

  private:
    map<string,Colleague*> obs;
};

int main(){
  return 0;
}
