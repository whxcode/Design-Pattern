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
#include <stack>
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
  RemoteControll() { onCommands.clear(); }

public:
  void add(Command *command) { onCommands.push_back(command); }
  void remove(Command *command) { onCommands.remove(command); }

  void execute(int pos) {
    auto it = onCommands.begin();

    for (int i = 0; i < pos; ++i) {
      it++;
    }

    (*it)->execute();
    undoCommands.push(*it);
  }

  void undo() {
    Command *command = undoCommands.top();
    undoCommands.pop();

    command->undo();

    redos.push(command);
  }

  void redo() {
    Command *command = redos.top();
    redos.pop();
    command->execute();
    undoCommands.push(command);
  }

private:
  list<Command *> onCommands;
  stack<Command *> undoCommands;
  stack<Command *> redos;
};

int main() {
  RemoteControll *controll = new RemoteControll;

  LightReceiver *light = new LightReceiver;
  LightOnCommand *lightOn = new LightOnCommand(light);

  TvtReceiver *tvt = new TvtReceiver;
  TvtOnCommand *tvtOn = new TvtOnCommand(tvt);

  controll->add(lightOn);
  controll->add(tvtOn);

  controll->execute(0);
  controll->execute(1);

  controll->undo();
  controll->undo();

  controll->redo();
  controll->redo();

  return 0;
}
