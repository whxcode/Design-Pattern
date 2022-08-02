/*************************************************************************
> File Name: 04-行为型模式/04-迭代器模式/02.改进迭代器.cpp
> Author: root
> Mail:
> Created Time: 2022年08月02日 星期二 22时47分14秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Iteratee;
class Iterator {
public:
  virtual void reset() = 0;
  virtual bool isDone() = 0;
  virtual void *next() = 0;

protected:
  Iteratee *iteratee;
};

class Iteratee {

public:
  virtual Iterator *createInterator() = 0;
  virtual int getSize() = 0;
  virtual void *getItem(int index) = 0;
};

class ArrayIterator : public Iterator {
public:
  ArrayIterator(Iteratee *iteratee) {
    index = 0;
    this->iteratee = iteratee;
  }

  void reset() override { index = 0; }
  bool isDone() override { return index > iteratee->getSize(); }
  void *next() override { return iteratee->getItem(index++); }

private:
  int index;
};

class Dog : public Iteratee {
public:
  Dog() {
    for (int i = 0; i < 10; i++) {
      this->dog[i] = i * 100;
    }
  }

public:
  int getSize() override { return 10; }
  void *getItem(int index) override { return (void *)(dog + index); }
  Iterator *createInterator() override { return new ArrayIterator(this); }

private:
  int dog[10];
};

class Cat : public Iteratee {
public:
  Cat() {
    for (int i = 0; i < 4; i++) {
      cat.push_back(i*100);
    }
  }

public:
  int getSize() override { return cat.size(); }
  void *getItem(int index) override { 
    auto it = cat.begin();
    for( int i =0;i < index;++i ) {
      it++;
    }
    return (void *)*it;

  }
  Iterator *createInterator() override { return new ArrayIterator(this); }

private:
  list<int> cat;
};

int main() {

  Dog *dog = new Dog;

  Iterator *t1 = dog->createInterator();

  while (!t1->isDone()) {
    int *d = (int *)t1->next();

    cout << "d=" << *d << endl;
  }
  cout << endl;

  Iterator *t2 = (new Cat)->createInterator();

  while (!t2->isDone()) {
    int *d = (int *)t2->next();

    printf("%d\n",d);
  }

  return 0;
}
