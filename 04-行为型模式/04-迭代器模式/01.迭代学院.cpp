/*************************************************************************
> File Name: 04-行为型模式/04-迭代器模式/01.迭代学院.cpp
> Author: root
> Mail:
> Created Time: 2022年08月02日 星期二 21时41分49秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Iterator {
public:
  virtual bool hasNext() = 0;
  virtual void *next() = 0;
  virtual void remove() = 0;
};

class Department {
public:
  Department(string name, string desc) {
    this->name = name;
    this->desc = desc;
  }

public:
  void display() {
    cout << "name:"
         << "desc:" << desc << endl;
  }

private:
  string name;
  string desc;
};

class ComputerIterator : public Iterator {
public:
  ComputerIterator(Department *(*de)[10]) {
    pos = -1;
    this->departments = de;
  }

public:
  bool hasNext() override {
    pos++;
    if (pos >= 10) {
      return false;
    }

    return true;
  }

  void *next() override {
    Department *d = (*departments)[pos];

    return d;
  }

  void remove() override {}

private:
  int pos;
  Department *(*departments)[10];
};

class InfomationIterator : public Iterator {
public:
  InfomationIterator(list<Department *> *list) {
    pos = -1;
    this->departments = list;
  }

public:
  bool hasNext() override {
    int size = departments->size() - 1;
    int res = (pos) >= size;

    if (res) {
      return false;
    }

    pos++;

    return true;
  }

  void *next() override {
    auto it = departments->begin();
    for (int i = 0; i < pos; ++i) {
      it++;
    }

    return *it;
  }

  void remove() override {}

private:
  int pos;
  list<Department *> *departments;
};

class College {
public:
  virtual Iterator *createIterator() = 0;
};

class ComputerCollege : public College {
public:
  ComputerCollege() {
    for (int i = 0; i < 10; ++i) {
      departs[i] = new Department("计算机学院", "位");
    }
  }

public:
  Iterator *createIterator() override { return new ComputerIterator(&departs); }

private:
  Department *departs[10];
};

class InfomationCollege : public College {
public:
  InfomationCollege() {
    departs.clear();
    for (int i = 0; i < 10; ++i) {
      departs.push_back(new Department("信息学院", "位111"));
    }
  }

public:
  Iterator *createIterator() override {
    return new InfomationIterator(&departs);
  }

private:
  list<Department *> departs;
};

int main() {
  ComputerCollege *computer = new ComputerCollege;
  Iterator *computerIterator = computer->createIterator();

  InfomationCollege *infomation = new InfomationCollege;
  Iterator *infomationIterator = infomation->createIterator();

  while (computerIterator->hasNext()) {
    Department *d = (Department *)computerIterator->next();

    d->display();
  }

  cout << endl;

  while (infomationIterator->hasNext()) {
    Department *d = (Department *)infomationIterator->next();

    d->display();
  }

  return 0;
}
