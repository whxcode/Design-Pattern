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

class TeacherFactory {
public:
  TeacherFactory() {
    teachers.clear();
    reference.clear();
  }

public:
  Person *getTeacher(string name) {
    auto it = teachers.find(name);

    if (it != teachers.end()) {
      reference[name]++;

      return it->second;
    }

    Teacher *t = new Teacher(name);

    teachers.insert(make_pair(name, t));
    reference[name] = 1;

    return t;
  }

  Person *createStuden(string name) { return new Study(name); }

  void display() {
    cout << "current teacher amount:" << teachers.size() << endl;
    cout << "----" <<endl;

    for(auto it : reference) {
      cout << it.first << "  :  " << it.second  <<endl;
    }

    cout << "----" <<endl;
  }

  void free(Person* p) {

    auto it = reference.find(p->name);

    if (it == reference.end()) {
      return;
    }

    if(it->second == 1) {
      reference.erase(p->name);
      teachers.erase(p->name);
      delete p;
    } else {
      -- reference[p->name] ;
    }
  }

private:
  map<string, Person *> teachers;
  map<string, int> reference;
};

int main() {

  TeacherFactory *factory = new TeacherFactory();

  Person *t1 = factory->getTeacher("xw");
  t1->behaver(factory->createStuden("whx"));

  Person *t11 = factory->getTeacher("xw");
  t11->behaver(factory->createStuden("xhw"));

  // printf("%d\n",t1 == t11);

  factory->display();

  factory->free(t1);
  factory->display();

  factory->free(t1);
  factory->display();

  delete factory;

  return 0;
}
