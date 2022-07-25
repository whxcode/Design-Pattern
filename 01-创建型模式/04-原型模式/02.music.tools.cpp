/*************************************************************************
> File Name: 01-创建型模式/04-原型模式/02.music.tools.cpp
> Author: root
> Mail:
> Created Time: 2022年07月25日 星期一 21时21分38秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Graphic {

public:
  virtual Graphic *clone() = 0;
  virtual void draw() {}
};

class Staff : public Graphic {
public:
  Staff(string name) { this->name = name; }

public:
  Graphic *clone() override { return new Staff(name); }
  void draw() override { cout << "Staff:" << name << endl; }

private:
  string name;
};

class MuscleNote : public Graphic {
public:
  virtual Graphic *clone() = 0;
  virtual void draw() = 0;

protected:
  string name;
};

class WholeNote : public MuscleNote {
public:
  WholeNote(string name) { this->name = name; }

public:
  Graphic *clone() override { return new WholeNote(name); }
  void draw() override { cout << "WholeNote:" << name << endl; }
};

class HalfNote : public MuscleNote {
public:
  HalfNote(string name) { this->name = name; }

public:
  Graphic *clone() override { return new HalfNote(name); }
  void draw() override { cout << "HalfNote:" << name << endl; }
};

class Tool {
public:
  virtual void manipulate() = 0;
};

class GraphicTool : public Tool {
public:
  void manipulate() override {
    Staff *staff = new Staff("staff");
    WholeNote *whole = new WholeNote("whole");
    HalfNote *half = new HalfNote("half");
    list<Graphic *> l;
    l.clear();

    l.push_back(staff->clone());
    l.push_back(whole->clone());
    l.push_back(half->clone());

    delete staff;
    delete whole;
    delete half;

    for (auto it : l) {
      it->draw();

      delete it;
    }
  }
};

int main() {

  GraphicTool *graphicTool = new GraphicTool;
  graphicTool->manipulate();

  delete graphicTool;

  return 0;
}
