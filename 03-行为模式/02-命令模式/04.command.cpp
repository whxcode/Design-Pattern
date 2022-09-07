/*************************************************************************
  > File Name: 04.command.cpp
  > Author: 
  > Mail: 
  > Created Time: 2022年09月07日 星期三 21时07分45秒
 ************************************************************************/

#include<iostream>
#include <stack>

using namespace std;
class Command {
  public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};


class Light {
  public:
    void on() {
      cout << "Light on" << endl;
    }

    void off() {
      cout << "Light off" <<endl;
    }
};

class LightCommand :public Command{
  public:
    LightCommand(Light* light) {
      this->light = light;
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


class Dvd {
  public:
    void on() {
      cout << "Dvd on" << endl;
    }

    void off() {
      cout << "Dvd off" <<endl;
    }
};

class DvdCommand :public Command{
  public:
    DvdCommand(Dvd* light) {
      this->light = light;
    }
  public:
    void execute() override {
      light->on();
    }
    void undo() override {
      light->off();
    }
  private:
    Dvd* light;
};

class Phone {
  public:
    void on() {
      cout << "Phone on" << endl;
    }

    void off() {
      cout << "Phone off" <<endl;
    }
};

class PhoneCommand :public Command{
  public:
    PhoneCommand(Phone* light) {
      this->light = light;
    }
  public:
    void execute() override {
      light->on();
    }
    void undo() override {
      light->off();
    }
  private:
    Phone* light;
};

class Controll {
  public:
    void execute(Command* command) {
      command->execute();
    undoCommands.push(command);
    }

    void undo() {
      Command *command = this->action(undoCommands, redoCommands);
      if (command == NULL) {
        return;
      }
      command->undo();
    }

    void redo() {
      Command *command = this->action(redoCommands, undoCommands);
      if (command == NULL) {
        return;
      }
      command->execute();
    }

  private:
    Command *action(stack<Command *> &l, stack<Command *> &r) {
      if (l.empty()) {
        return NULL;
      }

      Command *command = l.top();

      l.pop();
      r.push(command);

      return command;
    }
  private:
    stack<Command *> undoCommands;
    stack<Command *> redoCommands;

};


int main(){

  Controll *controll = new Controll();

  controll->execute(new LightCommand(new Light));
  controll->execute(new DvdCommand(new Dvd));
  controll->execute(new PhoneCommand(new Phone));


  cout << endl;

  controll->undo();
  controll->undo();
  controll->undo();

  cout << endl;

  controll->redo();
  controll->redo();
  controll->redo();


  return 0;
}
