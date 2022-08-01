/*************************************************************************
> File Name: 04-行为型模式/02-命令模式/01.家电.cpp
> Author: root
> Mail:
> Created Time: 2022年08月01日 星期一 20时59分46秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Command {
public:
  virtual void execute() = 0;
  virtual void undo() = 0;
};

class LightReceiver {
public:
  void on() { cout << "打开电灯" << endl; }

  void off() { cout << "关闭电灯" << endl; }
};

class LightOnCommand : public Command {
public:
  LightOnCommand(LightReceiver *light) : light(light) {}

public:
  void execute() override { light->on(); }
  void undo() override { light->off(); }

private:
  LightReceiver *light;
};

class LightOffCommand : public Command {
public:
  LightOffCommand(LightReceiver *light) : light(light) {}

public:
  void execute() override { light->on(); }
  void undo() override { light->off(); }

private:
  LightReceiver *light;
};

class TvtReceiver {
public:
  void on() { cout << "打开电视" << endl; }
  void off() { cout << "关闭电视" << endl; }
};

class TvtOnCommand : public Command {
public:
  TvtOnCommand(TvtReceiver *light) : light(light) {}

public:
  void execute() override { light->on(); }
  void undo() override { light->off(); }

private:
  TvtReceiver *light;
};

class TvtOffCommand : public Command {
public:
  TvtOffCommand(TvtReceiver *light) : light(light) {}

public:
  void execute() override { light->on(); }
  void undo() override { light->off(); }

private:
  TvtReceiver *light;
};

// 不执行任何命令。
// 省略对空的判断。
class NoCommand : public Command {
public:
  void execute() override {}
  void undo() override {}
};

class RemoteControll {
public:
  RemoteControll() {
    onCommands.clear();
    undoCommand = NULL;
    // offCommands.clear();
  }

public:
  void add(Command *command) { onCommands.push_back(command); }
  void remove(Command *command) {
    if (command == undoCommand) {
      undoCommand = NULL;
    }

    onCommands.remove(command);
  }

  void execute(int pos) {
    auto it = onCommands.begin();

    for (int i = 0; i < pos; ++i) {
      it++;
    }

    (*it)->execute();
    undoCommand = *it;
  }

  void undo() {
    if (undoCommand == NULL) {
      return;
    }

    undoCommand->undo();
  }

  void redo() { undoCommand->execute(); }

private:
  list<Command *> onCommands;
  // list<Command *> offCommands;
  Command *undoCommand;
};

int main() {
  RemoteControll *controll = new RemoteControll;
  LightReceiver *light = new LightReceiver;

  LightOnCommand *lightOn = new LightOnCommand(light);

  controll->add(lightOn);

  controll->execute(0);

  controll->undo();
  controll->redo();

  controll->undo();
  controll->redo();

  return 0;
}
