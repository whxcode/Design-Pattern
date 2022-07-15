/*************************************************************************
> File Name: /root/study/c/desgin-pattern/01-CreatePattern/14.property.cpp
> Author: root
> Mail:
> Created Time: 2022年07月14日 星期四 22时32分52秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Person {
public:
  virtual Person *clone() = 0;
  virtual void printf() = 0;

  void setName(const char *name) {
    const auto len = strlen(name) + 1;
    const auto l = strlen(this->name) + 1;

    if (len > l) {
      char *temp = this->name;
      this->name = (char *)calloc(1, len);

      delete temp;
    }

    strcpy(this->name, name);
  }

protected:
  char *name;
  int age;
};

class CProgrammer : public Person {
public:
  //运算符重载
  CProgrammer &operator=(CProgrammer &p) {
    this->age = p.age;
    const auto len = strlen(p.name) + 1;
    this->name = (char *)calloc(1, len);

    strcpy(this->name, p.name);
    return *this; // this是自身，解引用
  }

public:
  CProgrammer() {
    name = NULL;
    age = 0;
  }

  CProgrammer(const char *n, int a) {
    const auto len = strlen(n) + 1;
    this->name = (char *)calloc(1, len);

    strcpy(name, n);

    age = a;
  }

  Person *clone() override {
    CProgrammer *temp = new CProgrammer();
    *temp = *this;

    return temp;
  }

  void printf() override {
    cout << "name:";
    cout << name << endl;

    cout << "age:";
    cout << age << endl;
  }
};

void f1(int a) {}

void f2(void *a) {}

void *f3() { return NULL; }
void **f4() { return NULL; }
void (*f5())() { return NULL; }
void *(*f6())() { return NULL; }
void (*(*f7())())() { return NULL; }

int (*f9())[12] { return NULL; }

int (*(*f10())())[12] { return NULL; }

int (*(*(*f11())())())[12] { return NULL; }

int (*(*(*(*f8())())())())[12] { return NULL; }

void test01() {
  void (*p1)(int a) = f1;
  void (*p2)(void *a) = f2;
  void *(*p3)() = f3;
  void **(*p4)() = f4;

  void (*(*p5)())() = f5;
  void *(*(*p6)())() = f6;
  void (*(*(*p7)())())() = f7;

  int (*(*(*(*(*p8)())())())())[12] = f8;
  //
  //
  int(*(*p9)())[12] = f9;

  int(*(*(*p10)())())[12] = f10;

  int(*(*(*(*p11)())())())[12] = f11;
}

int main() {
  Person *c = new CProgrammer("王恒星", 10);

  c->printf();

  Person *java = c->clone();
  java->setName("恒星王");

  java->printf();
  cout << endl;
  java->setName("恒星王恒星王恒星王恒星王恒星王恒星王恒星王恒星王恒星王恒星王恒"
                "星王恒星王恒星王恒星王恒星王恒星王恒星王恒星王恒星王恒星王");

  c->printf();
  java->printf();

  return 0;
}
