#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class College;

class Organization {
public:
  Organization(string name) { this->name = name; }

public:
  virtual void add(Organization *org) {}
  virtual void remove(Organization *org) {}
  virtual void printf() = 0;

protected:
  string name;
};

class Department : public Organization {
public:
  Department(string name) : Organization(name) {}

public:
  void printf() override { cout << "-------Deparment:" << this->name << endl; }
};

class College : public Organization {
public:
  College(string name) : Organization(name) { departments.clear(); }

  ~College() {
    for (auto it : departments) {
      delete (Department *)it;
    }
  }

public:
  void add(Organization *org) override { departments.push_back(org); }
  void remove(Organization *org) override { departments.remove(org); }
  void printf() override {
    cout << "-----College:" << this->name << endl;

    for (auto it : departments) {
      it->printf();
    }
  }

private:
  list<Organization *> departments;
};

class University : public Organization {
public:
  University(string name) : Organization(name) { colleges.clear(); }
  ~University() {
    for (auto it : colleges) {
      delete (College *)it;
    }
  }

public:
  void add(Organization *org) override { colleges.push_back(org); }
  void remove(Organization *org) override { colleges.remove(org); }
  void printf() override {
    cout << "---University:" << this->name << endl;

    for (auto it : colleges) {
      it->printf();
    }
  }

private:
  list<Organization *> colleges;
};

void test01() {
  University *university = new University("xxx大学");
  College *c1 = new College("c1 学院");
  College *c2 = new College("c2 学院");
  College *c3 = new College("c3 学院");

  Department *d1 = new Department("d1 系");
  Department *d2 = new Department("d1 系");
  Department *d3 = new Department("d1 系");
  Department *d4 = new Department("d1 系");

  c1->add(d1);
  c1->add(d2);

  c2->add(d3);
  c3->add(d4);

  university->add(c1);
  university->add(c2);
  university->add(c3);

  university->printf();

  delete (University *)university;
}

int main() {
  test01();
  return 0;
}
