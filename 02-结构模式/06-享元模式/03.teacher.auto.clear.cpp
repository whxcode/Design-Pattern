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
    cout << "name:" << name << "  ";
    cout << "teach " << p->name << endl;
    ;

    delete p;
  }
};

class ReferenceDecorator : public Person {
public:
  ReferenceDecorator(Person *person) {
    this->name = person->name;
    this->person = person;
    reference = 1;
  }

  ~ReferenceDecorator() {
    delete person;
  }
public:
  void behaver(Person *p) override { person->behaver(p); }

public:
  int reference;

private:
  Person *person;
};

class TeacherFactory {
public:
  TeacherFactory() { teachers.clear(); }

public:
  Person *getTeacher(string name) {
    auto it = teachers.find(name);

    if (it != teachers.end()) {
      ++it->second->reference;

      return it->second;
    }

    ReferenceDecorator *t = new ReferenceDecorator(new Teacher(name));

    teachers.insert(make_pair(name, t));

    return t;
  }

  Person *createStuden(string name) { return new Study(name); }

  void display() {
    cout << "current teacher amount:" << teachers.size() << endl;
    cout << "----" << endl;

    for (auto it : teachers) {
      cout << it.first << "  :  " << it.second->reference << endl;
    }

    cout << "----" << endl;
  }

  void free(Person **p) {
    ReferenceDecorator* rp = (ReferenceDecorator *)*p;

    *p = NULL;

    if(rp->reference == 1) {
      teachers.erase((*rp).name);

      delete rp;
      return;;
    }

    -- rp->reference;
  }

private:
  map<string, ReferenceDecorator *> teachers;
};

int main() {

  TeacherFactory *factory = new TeacherFactory();

  Person *t1 = factory->getTeacher("xw");
  t1->behaver(factory->createStuden("whx"));

  Person *t11 = factory->getTeacher("xw");
  t11->behaver(factory->createStuden("xhw"));

  // printf("%d\n",t1 == t11);

  factory->display();

  factory->free(&t11);
  factory->display();

  factory->free(&t1);
   factory->display();

  delete factory;

  return 0;
}
