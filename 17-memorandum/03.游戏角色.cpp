/*************************************************************************
> File Name: 17-memorandum/03.游戏角色.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 08时32分31秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Memento {

public:
  Memento(int v, int d) {
    vit = v;
    def = d;
  }

public:
  int vit;
  int def;
};

class Caretaker {
public:
  void setMemento(Memento *memento) { this->memento = memento; }
  Memento *getMemento() { return this->memento; }

private:
  Memento *memento;
};

class Here {
public:
  void setVit(int v) { vit = v; }
  void setDef(int v) { def = v; }
  Memento *saveState() { return new Memento(vit, def); }
  void restoreState(Memento *m) {
    setVit(m->vit);
    setDef(m->def);
  }
  void printf() {
    cout << "Vit:" << vit << endl;
    cout << "Def:" << def << endl;
  }

private:
  int vit;
  int def;
};

int main() {
  Here *h = new Here();
  Caretaker *care = new Caretaker;

  h->printf();

  care->setMemento(h->saveState());

  h->setDef(50);
  h->setVit(50);

  h->printf();
  h->restoreState(care->getMemento());
  h->printf();


  return 0;
}
