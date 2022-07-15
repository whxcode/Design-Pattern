/*************************************************************************
> File Name: 01-CreatePattern/12-family.cpp
> Author: root
> Mail:
> Created Time: 2022年07月13日 星期三 22时44分41秒
 ************************************************************************/

#include <iostream>
using namespace std;
class CPU {
public:
  virtual void computer() const = 0;
};

class Memory {
public:
  virtual void strage() const = 0;
};

class Disk {
public:
  virtual void save() const = 0;
};

class Computer {
public:
  Computer(CPU *c, Memory *m, Disk *d) : cpu(c), memory(m), disk(d) {}

public:
  void worker() {
    cpu->computer();
    memory->strage();
    disk->save();
  }

private:
  CPU *cpu;
  Memory *memory;
  Disk *disk;
};
class AbstractFactory {
public:
  virtual CPU *getCpu() const = 0;
  virtual Memory *getMemory() const = 0;
  virtual Disk *getDisk() const = 0;
};

class IntelCpu : public CPU {
public:
  void computer() const override { cout << "intel cpu" << endl; }
};

class IntelMemory : public Memory {
public:
  void strage() const override { cout << "intel memory" << endl; }
};

class IntelDisk : public Disk {
public:
  void save() const override { cout << "intel disk" << endl; }
};

class IntelAbstract : public AbstractFactory {
public:
  CPU *getCpu() const override { return new IntelCpu; }
  Memory *getMemory() const override { return new IntelMemory; }
  Disk *getDisk() const override { return new IntelDisk; }
};

class KingstonCpu : public CPU {
public:
  void computer() const override { cout << "kingston cpu" << endl; }
};

class KingstonMemory : public Memory {
public:
  void strage() const override { cout << "kingston memory" << endl; }
};

class KingstonDisk : public Disk {
public:
  void save() const override { cout << "kingston disk" << endl; }
};

class KingstonAbstract : public AbstractFactory {
public:
  CPU *getCpu() const override { return new KingstonCpu; }
  Memory *getMemory() const override { return new KingstonMemory; }
  Disk *getDisk() const override { return new KingstonDisk; }
};

void testIntel() {
  AbstractFactory *intelFactory = new IntelAbstract;
  Computer *computer =
      new Computer(intelFactory->getCpu(), intelFactory->getMemory(),
                   intelFactory->getDisk());

  computer->worker();
}

void testKingston() {
  AbstractFactory *kingstonFactory = new KingstonAbstract;
  Computer *computer =
      new Computer(kingstonFactory->getCpu(), kingstonFactory->getMemory(),
                   kingstonFactory->getDisk());

  computer->worker();
}

void *(*f1())[12] { return NULL; }

void (*f2())() { return NULL; }

void *(*((*f3())()))[12] { return f1; }

void (*p[12])();

void (*(*f4())[12])() { return &p; }

void (*p1)() = NULL;

void (**f5())() { return &p1; }

void **(*(*p2)())() = NULL;

void **(*(*(*f6()))())() { return &p2; }

int main() {
  testIntel();
  cout << endl;
  cout << endl;
  testKingston();
  return 0;
}
