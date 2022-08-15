/*************************************************************************
> File Name: 01.singer.cpp
> Author:
> Mail:
> Created Time: 2022年08月15日 星期一 20时30分04秒
 ************************************************************************/

#include <iostream>
#include <list>

using namespace std;

class Action;
class Person {
public:
  virtual void accept(Action *action) = 0;

public:
  string name;
};

class Action {
public:
  virtual void action(Person *p) = 0;
};

class Man : public Person {
public:
  void accept(Action *action) override { action->action(this); }
};

class Woman : public Person {
public:
  void accept(Action *action) override { action->action(this); }
};

class SuccessAction : public Action {
public:
  void action(Person *p) override { cout << "success" << endl; }
};

class FailAction : public Action {
public:
  void action(Person *p) override { cout << "fail" << endl; }
};

class Object {
public:
  Object() { l.clear(); }

public:
  void attach(Person *p) { l.push_back(p); }
  void action(Action *action) {
    for (auto it : l) {
      it->accept(action);
    }
  }

private:
  list<Person *> l;
};

int main() {
  Object *o = new Object;
  o->attach(new Man);
  o->attach(new Woman);

  o->action(new SuccessAction);

  o->action(new FailAction);

  return 0;
}
