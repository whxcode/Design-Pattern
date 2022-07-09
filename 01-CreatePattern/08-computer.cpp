/*************************************************************************
> File Name: 08-computer.cpp
> Author:
> Mail:
> Created Time: 2022年07月04日 星期一 20时24分15秒
 ************************************************************************/

#include <iostream>
using namespace std;

// 抽象层面。
class CPU {
public:
  virtual void caculate() = 0;
};

class DisplayCard {
public:
  virtual void display() = 0;
};

class Memory {
public:
  virtual void storage() = 0;
};

class AbstractFactory {
public:
  virtual CPU *createCPU() = 0;
  virtual DisplayCard *createDisplay() = 0;
  virtual Memory *createMemory() = 0;
};

class Computer {
public:
  Computer(CPU *cpu, DisplayCard *displayCard, Memory *memory) {
    this->cpu = cpu;
    this->displayCard = displayCard;
    this->memory = memory;
  }

public:
  void worker() {
    this->cpu->caculate();
    this->displayCard->display();
    this->memory->storage();
  }
  void setCUP(CPU *cpu) { this->cpu = cpu; }

private:
  CPU *cpu;
  DisplayCard *displayCard;
  Memory *memory;
};

// 实现层面

class InterlCPU : public CPU {
public:
  void caculate() override { cout << "Interl CUP\n"; }
};

class InterlCard : public DisplayCard {
public:
  void display() override { cout << "Interl display card\n"; }
};

class InterMemory : public Memory {
public:
  void storage() override { cout << "Interl memory\n"; }
};

class InterlFactory : public AbstractFactory {
public:
  CPU *createCPU() override { return new InterlCPU(); }
  DisplayCard *createDisplay() override { return new InterlCard(); }
  Memory *createMemory() override { return new InterMemory(); }
};

// 实现层面

class NvidiaCPU : public CPU {
public:
  void caculate() override { cout << "Nvidia CUP\n"; }
};

class NvidiaCard : public DisplayCard {
public:
  void display() override { cout << "Nvidia display card\n"; }
};

class NvidiaMemory : public Memory {
public:
  void storage() override { cout << "Nvidia memory\n"; }
};

class NvidiaFactory : public AbstractFactory {
public:
  CPU *createCPU() override { return new NvidiaCPU(); }
  DisplayCard *createDisplay() override { return new NvidiaCard(); }
  Memory *createMemory() override { return new InterMemory(); }
};

int console() {
  AbstractFactory *interlFactory = new InterlFactory();
  CPU *intelCPU = new InterlCPU;
  DisplayCard *intelCard = new InterlCard;
  Memory *intelMemory = new InterMemory;

  Computer *intelComputer = new Computer(intelCPU, intelCard, intelMemory);
  intelComputer->worker();

  CPU *nvidiaCPU = new NvidiaCPU();
  intelComputer->setCUP(nvidiaCPU);

  intelComputer->worker();

  return 0;
}
