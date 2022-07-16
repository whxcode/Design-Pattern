/*************************************************************************
> File Name: 17-memorandum/01.test.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 18时34分49秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Memorandum {
public:
  Memorandum(string name, int age) {
    this->name = name;
    this->age = age;
  }

public:
public:
  string getName() { return name; }
  void setName(string name) { this->name = name; }

  int getAge() { return age; }
  void setAge(int age) { this->age = age; }

private:
  string name;
  int age;
};

class Person {
public:
  Memorandum *createMemorandum() { return new Memorandum(name, age); }
  void setMemorandum(Memorandum *mem) {
    this->age = mem->getAge();
    this->name = mem->getName();
  }

  void pritf() { cout << "name:" << name << ",age:" << age << endl; }

public:
  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }

public:
  string getName() { return name; }
  void setName(string name) { this->name = name; }

  int getAge() { return age; }
  void setAge(int age) { this->age = age; }

private:
  string name;
  int age;
};

class Caretker {
public:
  Caretker(Memorandum *mem) { this->mem = mem; }
  void setMem(Memorandum *mem) { this->mem = mem; }
  Memorandum *getMem() { return this->mem; }

private:
  Memorandum *mem;
};

void test01() {
  Person *p = new Person("whx", 10);
  Memorandum *mem = p->createMemorandum();
  p->pritf();
  p->setAge(100);
  p->setName("w100");
  p->pritf();
  p->setMemorandum(mem);
  p->pritf();

  delete p;
  delete mem;
}

void test02() {
  Person *p = new Person("whx", 10);
  Caretker *care = new Caretker(p->createMemorandum());

  p->pritf();
  p->setAge(100);
  p->setName("w100");
  p->pritf();

  p->setMemorandum(care->getMem());
  p->pritf();

  delete p;
  delete care->getMem();
}

int main() {
  test01();
  return 0;
}
