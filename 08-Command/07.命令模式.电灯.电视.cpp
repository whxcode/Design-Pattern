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
  void on() { cout << "电灯打开了..." << endl; }

  void off() { cout << "电灯关闭了..." << endl; }
};

class LightOnCommand : public Command {
public:
  LightOnCommand(LightReceiver *r) { receiver = r; }

public:
  void execute() override { receiver->on(); }
  void undo() override { receiver->off(); }

private:
  LightReceiver *receiver;
};

class LightOffCommand : public Command {
public:
  LightOffCommand(LightReceiver *r) { receiver = r; }

public:
  void execute() override { receiver->off(); }
  void undo() override { receiver->on(); }

private:
  LightReceiver *receiver;
};

class TvtReceiver {
public:
  void on() { cout << "电视打开了..." << endl; }

  void off() { cout << "电视关闭了..." << endl; }
};

class TvtOnCommand : public Command {
public:
  TvtOnCommand(TvtReceiver *r) { receiver = r; }

public:
  void execute() override { receiver->on(); }
  void undo() override { receiver->off(); }

private:
  TvtReceiver *receiver;
};

class TvtOffCommand : public Command {
public:
  TvtOffCommand(TvtReceiver *r) { receiver = r; }

public:
  void execute() override { receiver->off(); }
  void undo() override { receiver->on(); }

private:
  TvtReceiver *receiver;
};

// 仅仅在位。
class NoCommand : public Command {
public:
  void execute() override {}
  void undo() override {}
};

class RemoteController {
public:
public:
  void setOnCommand(int no, Command *onCommand, Command *offCommand) {
    onCmds[no] = onCommand;
    offCmds[no] = offCommand;
  }

  void on(int no) {
    (*(*(onCmds + no))).execute();
    undoCmds = *(onCmds + no);
  }

  void off(int no) {
    (*(*(offCmds + no))).execute();
    undoCmds = *(offCmds + no);
  }

  void undo() { undoCmds->undo(); }

private:
  Command *onCmds[5];
  Command *offCmds[5];
  Command *undoCmds;
};

void test01() {
  LightReceiver *lightReceiver = new LightReceiver;
  LightOnCommand *onLight = new LightOnCommand(lightReceiver);
  LightOffCommand *offLight = new LightOffCommand(lightReceiver);

  RemoteController *remote = new RemoteController();
  remote->setOnCommand(0, onLight, offLight);

  remote->on(0);
  remote->undo();

  remote->off(0);
  remote->undo();

  delete lightReceiver;
  delete onLight;
  delete offLight;
  delete remote;
}

void test02() {
  LightReceiver *lightReceiver = new LightReceiver;
  LightOnCommand *onLight = new LightOnCommand(lightReceiver);
  LightOffCommand *offLight = new LightOffCommand(lightReceiver);

  TvtReceiver *tvtReceiver = new TvtReceiver;
  TvtOnCommand *onTvt = new TvtOnCommand(tvtReceiver);
  TvtOffCommand *offTvt = new TvtOffCommand(tvtReceiver);

  RemoteController *remote = new RemoteController();
  remote->setOnCommand(0, onLight, offLight);
  remote->setOnCommand(1, onTvt, offTvt);

  remote->on(0);
  remote->undo();

  remote->off(0);
  remote->undo();

  cout << endl;
  remote->on(1);
  remote->off(1);
  remote->undo();;

  delete lightReceiver;
  delete onLight;
  delete offLight;

  delete tvtReceiver;
  delete onTvt;
  delete offTvt;

  delete remote;
}

int main() {
  // test01();
  test02();
  return 0;
}
