/*************************************************************************
> File Name: 12-compose/02.school.cpp
> Author: root
> Mail:
> Created Time: 2022年07月20日 星期三 21时02分25秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Organization {
public:
  virtual void add(Organization *organization) {}
  virtual void remove(Organization *organization) {}
  virtual void printf() const = 0;

protected:
  string name;
  string describe;
};

class University : public Organization {
public:
  University(string name, string describe) {
    this->name = name;
    this->describe = name;
    l.clear();
  }

public:
  void add(Organization *organization) override { l.push_back(organization); }
  void remove(Organization *organization) override { l.remove(organization); }
  void printf() const override {
    cout << "----University-name:" << name << "describe:" << describe << "-----"
         << endl;
    auto start = l.begin();
    auto end = l.end();

    while (start != end) {
      (*start++)->printf();
    }
  }

private:
  list<Organization *> l;
};

class College : public Organization {
public:
  College(string name, string describe) {
    this->name = name;
    this->describe = name;
    l.clear();
  }

public:
  void add(Organization *organization) override { l.push_back(organization); }
  void remove(Organization *organization) override { l.remove(organization); }
  void printf() const override {
    cout << "----College-name:" << name << "describe:" << describe << "-----"
         << endl;
    auto start = l.begin();
    auto end = l.end();

    while (start != end) {
      (*start++)->printf();
    }
  }

private:
  // 这个 list 中，只能是 artparment
  list<Organization *> l;
};

class Department : public Organization {
public:
  Department(string name, string describe) {
    this->name = name;
    this->describe = name;
  }

public:
  void printf() const override {
    cout << "----Department-name:" << name << "describe:" << describe << "-----"
         << endl;
  }

private:
};

void test01() {
  Department *d1 = new Department("信息工程系", "d1");
  Department *d2 = new Department("软件工程系", "d2");
  Department *d3 = new Department("网络工程", "d3");
  Department *d4 = new Department("人工智能", "d4");

  College *c1 = new College("计算机学院", "c1");
  College *c2 = new College("信息工程系学院", "c2");

  University *university = new University("清华大学", "中国顶级大学");

  c1->add(d1);
  c1->add(d2);

  c2->add(d3);
  c2->add(d4);

  university->add(c1);
  university->add(c2);

  university->printf();
}

int main() {
  test01();
  return 0;
}
