#include <iostream>
#include <list>
#include <stack>

using namespace std;
class Command {
public:
  virtual void execute() = 0;
  virtual void undo() = 0;
};

class Light {
public:
  void on() { cout << "light on" << endl; }

  void off() { cout << "light off" << endl; }
};

class LightOnCommand : public Command {
public:
  LightOnCommand(Light *light) { this->light = light; }

public:
  void execute() override { light->on(); }
  void undo() override { light->off(); }

private:
  Light *light;
};

class LightOffCommand : public Command {
public:
  LightOffCommand(Light *light) { this->light = light; }

public:
  void execute() override { light->off(); }
  void undo() override { light->on(); }

private:
  Light *light;
};

class Dvd {
public:
  void on() { cout << "Dvd on" << endl; }

  void off() { cout << "Dvd off" << endl; }
};

class DvdOnCommand : public Command {
public:
  DvdOnCommand(Dvd *dvd) { this->dvd = dvd; }

public:
  void execute() override { dvd->on(); }
  void undo() override { dvd->off(); }

private:
  Dvd *dvd;
};

class DvdOffCommand : public Command {
public:
  DvdOffCommand(Dvd *dvd) { this->dvd = dvd; }

public:
  void execute() override { dvd->off(); }
  void undo() override { dvd->on(); }

private:
  Dvd *dvd;
};

class Controll {
public:
  void execute(Command *command) {
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

int main() {
  Light light;

  Command *command = new LightOnCommand(&light);
  Controll *controll = new Controll();

  controll->execute(command);
  controll->undo();
  controll->redo();

  return 0;
}
