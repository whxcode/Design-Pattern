/*************************************************************************
> File Name: 04-行为型模式/03-访问者模式/01.song.test.cpp
> Author: root
> Mail:
> Created Time: 2022年08月02日 星期二 20时39分35秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Person;
class Action {
public:
  virtual void getManResult(Person *p) = 0;
  virtual void getWomanResult(Person *p) = 0;
};

class Person {
public:
  virtual void accept(Action *Action) = 0;
  ;
};

class Man : public Person {
public:
  void accept(Action *action) override { action->getManResult(this); }
};

class Woman : public Person {
public:
  void accept(Action *action) override { action->getManResult(this); }
};

class Success : public Action {
public:
  void getManResult(Person *p) override { cout << "成功" << endl; }
  void getWomanResult(Person *p) override { cout << "成功" << endl; }
};

class Fail : public Action {
public:
  void getManResult(Person *p) override { cout << "失败" << endl; }
  void getWomanResult(Person *p) override { cout << "失败" << endl; }
};

class ObjectStructure {
public:
  ObjectStructure() { persons.clear(); }

public:
  void attach(Person *p) { persons.push_back(p); }
  void remove(Person *p) { persons.remove(p); }
  void display(Action *a) {
    for (auto *it : persons) {
      it->accept(a);
    }
  }

private:
  list<Person *> persons;
};

int main() {
  ObjectStructure *obj = new ObjectStructure;

  obj->attach(new Man);
  obj->attach(new Woman);
  obj->attach(new Man);

  Success *success = new Success;

  obj->display(success);

  (new Man())->accept(new Success);
  (new Man())->accept(new Fail);

  return 0;
}
