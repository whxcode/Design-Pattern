/*************************************************************************
> File Name: 17-memorandum/02.备忘录.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 08时13分29秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Memento {
public:
  Memento(string state) { this->state = state; }

public:
  string getState() { return state; }

private:
  string state;
};

class Originator {

public:
  string getState() { return state; }
  void setSTate(string state) { this->state = state; }

public:
  // 只保存一些相关数据
  Memento *saveStateMemento() { return new Memento(state); }
  // 通过 Memento 恢复状态
  void getStateFromMemento(Memento *memento) { state = memento->getState(); }

private:
  string state;
};

class Caretaker {
public:
  Caretaker() { mementos.clear(); }

public:
  void add(Memento *memento) { mementos.push_back(memento); }
  Memento *get(int index) {
    auto it = mementos.begin();
    for (int i = 0; i < index; ++i) {
      it++;
    }

    return *it;
  }

private:
  list<Memento *> mementos;
};

void test01() {
  Originator *originator = new Originator;
  Caretaker *caretaker = new Caretaker;

  originator->setSTate("状态 100");
  caretaker->add(originator->saveStateMemento());

  originator->setSTate("状态 40");
  caretaker->add(originator->saveStateMemento());

  originator->setSTate("状态 10");

  cout << originator->getState() << endl;

  originator->getStateFromMemento(caretaker->get(1));
  cout << originator->getState() << endl;

  originator->getStateFromMemento(caretaker->get(0));
  cout << originator->getState() << endl;


};

int main() {
  test01();
  return 0;
}
