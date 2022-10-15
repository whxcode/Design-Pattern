/*************************************************************************
> File Name: 01.commad.cpp
> Author: 
> Mail: 
> Created Time: 2022年10月15日 星期六 20时22分40秒
 ************************************************************************/

#include<iostream>
#include <stack>

using namespace std;

class Command {
  public:
    virtual void execute() =0;;
    virtual void undo() = 0;
};
class Action {
  public:
    void execute(Command* c) {
       c->execute();
       undos.push(c);
    }

    void undo() {
      if(undos.empty()) {
        return;;
      }

      Command* c = undos.top();
      c->undo();
      undos.pop();
      redos.push(c);
    }

    void redo() {
      if(redos.empty()) {
        return;;
      }

      Command* c = redos.top();
      c->execute();
      redos.pop();
      undos.push(c);
    }
  private:
    stack<Command*> undos;
    stack<Command*>redos;

};

class Light {
  public:
    void off() {
      cout << "关闭电灯" << endl;
    }
    void on() {
      cout << "打开电灯" << endl;
    }
};


class LightCommandOn: public Command {
  public:
    LightCommandOn(Light*l) {
       light = l;
    }
  public:
    void execute() override {
       light->on();

    }
    void undo() override {
       light->off();

    }
  private:
    Light* light;
};

class LightCommandOff: public Command {
  public:
    LightCommandOff(Light* l) {
      light = l;
    }
  public:
    void execute() override {
      light->off();

    }
    void undo() override {
      light->on();

    }
  private:
    Light* light;
};


class Tvt {
  public:
    void off() {
      cout << "关闭电视" << endl;
    }

    void on() {
      cout << "打开电视" << endl;
    }
};

class TvtCommand: public Command {
  public:
    TvtCommand(Tvt* l) {
      light = l;
    }
  public:
    void execute() override {
      light->on();

    }
    void undo() override {
      light->off();

    }
  private:
    Tvt* light;
};



int main(){
  Action* action = new Action;
   LightCommandOn* on = new LightCommandOn(new Light);
  LightCommandOff* off = new LightCommandOff(new Light);
   TvtCommand* tvt = new TvtCommand(new Tvt);


   action->execute(on);
   action->execute(tvt);
   action->undo();
   action->redo();

   action->undo();
   action->undo();
  

   delete on; 
   delete off; 
   delete action;
   delete action;

  return 0;
}
