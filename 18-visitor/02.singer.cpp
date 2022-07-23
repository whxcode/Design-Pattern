/*************************************************************************
> File Name: 18-visitor/02.singer.cpp
> Author: root
> Mail:
> Created Time: 2022年07月23日 星期六 10时08分46秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Person;
class Man;
class Woman;

class Action {
public:
  virtual void getManResult(Man *man) = 0;
  virtual void getWomanResult(Woman *woman) = 0;
};

class Person {
public:
  virtual void accept(Action *action) = 0;
};

class Man : public Person {
public:
  void accept(Action *action) override { action->getManResult(this); }
};

class Woman : public Person {
public:
  void accept(Action *action) override { action->getWomanResult(this); }
};

class Success : public Action {
public:
  void getManResult(Man *man) override { cout << "给的是成功" << endl; }
  void getWomanResult(Woman *woman) override { cout << "给的是成功" << endl; }
};

class Fail : public Action {
public:
  void getManResult(Man *man) override { cout << "给的是失败" << endl; }
  void getWomanResult(Woman *woman) override { cout << "给的是失败" << endl; }
};

class Wait : public Action {
public:
  void getManResult(Man *man) override { cout << "给的是待定" << endl; }
  void getWomanResult(Woman *woman) override { cout << "给的是待定" << endl; }
};

class ObjectStruct {
public:
  ObjectStruct() { persons.clear(); }

public:
  void attach(Person *p) { persons.push_back(p); }
  void detach(Person *p) { persons.remove(p); }
  void display(Action *action) {
    for (auto it : persons) {
      it->accept(action);
    }
  }

  ~ObjectStruct() {
    for (auto it : persons) {
      delete it;
    }
  }

private:
  list<Person *> persons;
};

void test01() {
  ObjectStruct obj;

  obj.attach(new Man);
  obj.attach(new Woman);

  Action *s = new Success;

  obj.display(s);

  obj.display(new Fail);
  obj.display(new Wait);
}

int main() {
  test01();
  return 0;
}
