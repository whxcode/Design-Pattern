/*************************************************************************
> File Name: 20-iterator/01.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 21时04分52秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define SIZE 5

typedef int Object;

struct Iterator {
public:
  virtual void reset() = 0;
  virtual void next() = 0;
  virtual bool isDone() = 0;
  virtual Object currentItem() = 0;
};

struct Aggragate {
public:
  virtual Iterator *createIterator() = 0;
  virtual Object getItem(int index) const = 0;
  virtual int getSize() const = 0;
};

struct Array : public Iterator {
public:
  Array(Aggragate *a) { obj = a; }

public:
  void reset() override { currentIndex = 0; }
  void next() override { ++currentIndex; }
  bool isDone() override { return currentIndex > obj->getSize(); }
  Object currentItem() override { return obj->getItem(currentIndex); }

private:
  int currentIndex;
  Aggragate *obj;
};

struct Set : public Aggragate {
  Set() {
    for (int i = 0; i < SIZE; ++i) {
      *(objs + i) = i * 100;
    }
  }

public:
  Iterator *createIterator() override { return new Array(this); }
  int getSize() const override { return SIZE; }
  Object getItem(int index) const override { return this->objs[index]; }

private:
  Object objs[SIZE];
};

void test01() {
  Aggragate *ag = new Set;
  auto *it = ag->createIterator();

  while (!it->isDone()) {
    auto a = it->currentItem();
    it->next();
    cout << a;
    cout << "\t";
  }

  cout << "\nend" << endl;
}

int main() {
  test01();
  return 0;
}
