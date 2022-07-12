/*************************************************************************
> File Name: 01-depend.cpp
> Author:
> Mail:
> Created Time: 2022年07月12日 星期二 20时38分24秒
 ************************************************************************/

#include <iostream>
using namespace std;
class HardDisk {
public:
  virtual void work() = 0;
};

class Memory {
public:
  virtual void work() = 0;
};

class Cpu {
public:
  virtual void work() = 0;
};

class Computer {
public:
  Computer(HardDisk *disk, Memory *mem, Cpu *cpu) {
    hardisk = disk;
    memory = mem;
    this->cpu = cpu;
  }
  ~Computer() {
    delete hardisk;
    delete memory;
    delete cpu;
  }

public:
  void work() {
    hardisk->work();
    memory->work();
    cpu->work();
  }

private:
  HardDisk *hardisk;
  Memory *memory;
  Cpu *cpu;
};

class IntelCpu : public Cpu {
public:
  void work() override { cout << "intel cpu" << endl; }
};

class KingstonMemory : public Memory {
public:
  void work() override { cout << "kingston memory" << endl; }
};

class SamsungMemory : public Memory {
public:
  void work() override { cout << "Samsung memory" << endl; }
};

class FoxconnDisk : public HardDisk {
public:
  void work() override { cout << "FoxconnDisk hardisk" << endl; }
};

int main() {
  Computer *computer =
      new Computer(new FoxconnDisk, new KingstonMemory, new IntelCpu);
  computer->work();

  cout << endl;
  Computer *computer1 =
      new Computer(new FoxconnDisk, new SamsungMemory, new IntelCpu);
  computer1->work();

  return 0;
}
