/*************************************************************************
> File Name: 01.teacher.cpp
> Author:
> Mail:
> Created Time: 2022年08月14日 星期日 10时40分54秒
 ************************************************************************/

#include <iostream>
#include <map>

using namespace std;

class Person {
public:
  virtual void behaver(Person *p) = 0;

public:
  string name;
};

class Study : public Person {
public:
  Study(string name) { this->name = name; }

public:
  void behaver(Person *) override {}
};

class Teacher : public Person {
public:
  Teacher(string name) { this->name = name; }

public:
  void behaver(Person *p) override {
    cout << "name:" << name << "  " ;
    cout << "teach " << p->name << endl;;

    delete p;
  }
};

class TeacherFactory {
public:
  TeacherFactory() { teachers.clear(); }

public:
  Person *getTeacher(string name) {
    auto it = teachers.find(name);

    if (it != teachers.end()) {
      return it->second;
    }

    Teacher *t = new Teacher(name);

    teachers.insert(make_pair(name, t));
    return t;
  }

  Person* createStuden(string name) {

    return new Study(name);
  }
private:
  map<string, Person *> teachers;
};


int main() { 

  TeacherFactory* factory = new TeacherFactory();

  Person *t1 = factory->getTeacher("xw");
  t1->behaver(factory->createStuden("whx"));

  Person *t11 = factory->getTeacher("xw");
  t11->behaver(factory->createStuden("xhw"));

  printf("%d\n",t1 == t11);

  delete t1;
  delete t11;
  delete factory;

  return 0; }
