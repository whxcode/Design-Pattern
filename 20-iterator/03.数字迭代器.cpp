/*************************************************************************
> File Name: 20-iterator/03.数字迭代器.cpp
> Author: root
> Mail:
> Created Time: 2022年07月23日 星期六 15时22分27秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Iterator {
public:
  virtual void reset() = 0;
  virtual void *next() = 0;
  virtual bool isDone() = 0;
};

class Iteratee {
public:
  virtual Iterator *createIterator() = 0;
  virtual void *getItem(int index) const = 0;
  virtual int getSize() const = 0;
};

struct Array : public Iterator {
public:
  Array(Iteratee *a) { obj = a; }

public:
  void reset() override { currentIndex = 0; }
  void *next() override {
    ++currentIndex;
    return obj->getItem(currentIndex);
  }
  bool isDone() override { return currentIndex > obj->getSize(); }

private:
  int currentIndex;
  Iteratee *obj;
};

class Set : public Iteratee {
public:
  Set() {
    for (int i = 0; i < 10; ++i) {
      *(dog + i) = 10;
    }
  }

public:
  Iterator *createIterator() override { return new Array(this); }

public:
  int getSize() const override { return 10; }
  void *getItem(int index) const override { return (void *)(dog + index); }

private:
  int dog[10];
};

class SetList : public Iteratee {
public:
  SetList() {
    dog.clear();
    for (int i = 0; i < 10; ++i) {
      dog.push_back(i);
    }
  }

public:
  Iterator *createIterator() override { return new Array(this); }

public:
  int getSize() const override { return 10; }

  void *getItem(int index) const override {
    auto start = dog.begin();

    for (int i = 0; i < index; ++i) {
      ++start;
    }
    int d = *start;

    return (void *)(new int(d));
  }

private:
  list<int> dog;
};

void test01() {
  Iteratee *ag = new Set;
  auto *it = ag->createIterator();

  while (!it->isDone()) {
    auto a = it->next();
    cout << *(int *)a;
    cout << "\t";
  }

  cout << "\nend" << endl;
}


void test02() {
  Iteratee *ag = new SetList;
  auto *it = ag->createIterator();

  while (!it->isDone()) {
    auto a = it->next();
    cout << *(int *)a;
    delete (int *)a;
    cout << "\t";
  }

  cout << "\nend" << endl;
}
int main() {
  test02();
  return 0;
}
