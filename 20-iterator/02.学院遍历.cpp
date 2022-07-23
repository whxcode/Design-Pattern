/*************************************************************************
> File Name: 20-iterator/02.学院遍历.cpp
> Author: root
> Mail:
> Created Time: 2022年07月23日 星期六 11时20分24秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

template <typename T> class Iterator {
public:
  virtual bool hasNext() const = 0;
  virtual T next() = 0;
  virtual void remove() = 0;
};

class Department {
public:
  Department() {}
  Department(string n, string d) : name(n), desc(d) {}

public:
  string name;
  string desc;
};

class ComputerCollegeIterator : public Iterator<Department *> {
public:
  ComputerCollegeIterator(Department (*d)[10]) { departments = d; }

private:
  Department (*departments)[10];
  int position = 0;

public:
  bool hasNext() const override { return this->position < 10; }

  Department *next() override { return &(*departments)[this->position++]; }
  void remove() override {}
};

class InfomationCollegeIterator : public Iterator<Department *> {
public:
  InfomationCollegeIterator(list<Department> *d) { departments = d; }

private:
  list<Department> *departments;
  int position = 0;

public:
  bool hasNext() const override { return this->position < 10; }

  Department *next() override {
    auto start = departments->begin();

    for (int i = 0; i < position; ++i) {
      ++start;
    }

    this->position++;
    Department *d = &*start;

    return d;
  }

  void remove() override {}
};

template <typename T> class College {
public:
  virtual Iterator<T> *createIterator() = 0;
};

class ComputerCollege : public College<Department *> {
public:
  ComputerCollege() {
    for (int i = 0; i < 10; ++i) {
      departments[i] =
          Department("ComputerCollegeIterator name:" + to_string(i),
                     "ComputerCollegeIterator desc" + to_string(i));
    }
  }

  Iterator<Department *> *createIterator() override {

    return new ComputerCollegeIterator(&departments);
  }

private:
  Department departments[10];
};

class InfomationCollege : public College<Department *> {
public:
  InfomationCollege() {
    for (int i = 0; i < 10; ++i) {
      Department d = Department("InfomationCollege name:" + to_string(i),
                                "InfomationCollege desc" + to_string(i));
      departments.push_back(d);
    }
  }

  Iterator<Department *> *createIterator() override {

    return new InfomationCollegeIterator(&departments);
  }

private:
  list<Department> departments;
};

void test01() {
  InfomationCollege *info = new InfomationCollege();
  Iterator<Department *> *i1 = info->createIterator();

  while (i1->hasNext()) {
    auto i = i1->next();
    cout << i->name << ":" << i->desc << endl;
  }

  cout << endl;

  ComputerCollege *computer = new ComputerCollege();
  Iterator<Department *> *i2 = computer->createIterator();

  while (i2->hasNext()) {
    auto i = i2->next();
    cout << i->name << ":" << i->desc << endl;
  }
}

int main() {
  test01();
  return 0;
}
