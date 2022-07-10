/*************************************************************************
> File Name: 03-roast.cpp
> Author:
> Mail:
> Created Time: 2022年07月10日 星期日 11时38分09秒
 ************************************************************************/

#include <iostream>
#include <list>

using namespace std;
class Cooker {
public:
  void makeChuaner() { cout << "makeChuaner" << endl; }
  void makeChicken() { cout << "makeChicken" << endl; }
};

class Command {
public:
  Command(Cooker *cooker) : cooker(cooker) {}
  ~Command() { delete this->cooker; }
  virtual void execute() const = 0;

protected:
  Cooker *cooker;
};

class CommandChuaner : public Command {
public:
  CommandChuaner(Cooker *cooker) : Command(cooker) {}
  void execute() const override { this->cooker->makeChuaner(); }
};

class CommandChicken : public Command {
public:
  CommandChicken(Cooker *cooker) : Command(cooker) {}
  void execute() const override { this->cooker->makeChicken(); }
};

class Waitress {

public:
  Waitress *addCommand(Command *cmd) {
    commands.push_back(cmd);
    return this;
  }

  Waitress *notify() {
    list<Command *>::iterator it = commands.begin();
    list<Command *>::iterator end = commands.end();

    while (it != end) {
      (*it++)->execute();
    }

    return this;
  }

private:
  list<Command *> commands;
};

int main() {
  Waitress *waitress = new Waitress();
  Command *chuanger = new CommandChuaner(new Cooker);
  Command *chicken = new CommandChicken(new Cooker);

  waitress->addCommand(chuanger)->addCommand(chicken)->notify();
  return 0;
}
