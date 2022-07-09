/*************************************************************************
> File Name: 01-nurse.cpp
> Author:
> Mail:
> Created Time: 2022年07月09日 星期六 09时51分45秒
 ************************************************************************/

#include <iostream>
#include <list>
using namespace std;
class Docotr {
public:
  void treatEyes() { cout << "医生治疗眼睛" << endl; }

  void treatNose() { cout << "医生治疗鼻子" << endl; }
};

class Command {
public:
  virtual void treat() = 0;
  Command(Docotr *d) : doctor(d) {}
  ~Command() { delete doctor; }

protected:
  Docotr *doctor;
};

class CommandEyes : public Command {
public:
  CommandEyes(Docotr *doctor) : Command(doctor) {}
  void treat() override { doctor->treatEyes(); }
};

class CommandNose : public Command {
public:
  CommandNose(Docotr *doctor) : Command(doctor) {}
  void treat() { doctor->treatNose(); }
};

class Nurse {
public:
  Nurse(Command *command) { this->command = command; }

  ~Nurse() { delete this->command; }

  void notify() {}

private:
  Command *command;
};

class NurseBoss {
public:
  NurseBoss() { mlist.clear(); }

  ~NurseBoss() { mlist.clear(); }

  void addCmd(Command *cmd) { this->mlist.push_back(cmd); }
  void notify() {
    list<Command *>::iterator it = mlist.begin();
    list<Command *>::iterator end = mlist.end();

    while (it != end) {
      (*it++)->treat();
    }
  }

private:
  list<Command *> mlist;
};

int main() {

  /*
  CommandEyes *cmdEyes = new CommandEyes(new Docotr);
  CommandNose *cmdNose = new CommandNose(new Docotr);

  cmdEyes->treat();
  cmdNose->treat();
  */
  NurseBoss *nurseBoss = new NurseBoss();
  nurseBoss->addCmd(new CommandEyes(new Docotr));
  nurseBoss->addCmd(new CommandNose(new Docotr));

  nurseBoss->notify();

  return 0;
}
