/*************************************************************************
> File Name: 14-Share/01.share.teacher.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 11时22分41秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <unistd.h>

using namespace std;

class Person {
public:
  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }

public:
  virtual void printf() const = 0;

protected:
  string name;
  int age;
};

class Teacher : public Person {
public:
  Teacher(string name, int age, string id) : Person(name, age) {
    this->id = id;
  }

public:
  void printf() const override {
    cout << "id:" << id << endl;
    cout << "name:" << name << endl;
    cout << "age:" << age << endl;
  }

private:
  string id;
};

class FlyWeight {
public:
  virtual const Person *getPerson(string id) = 0;

protected: map<std::string, Person *> obj;
};

class FlyWeightTeach : public FlyWeight {
public:
  ~FlyWeightTeach() {
    while (!obj.empty()) {
      Person *temp = NULL;
      auto it = obj.begin();

      temp = it->second;
      obj.erase(it);

      delete (Teacher *)temp;
    }
  }

public:
  const Person *getPerson(string id) override {
    auto it = obj.find(id);

    if (it != obj.end()) {

      return it->second;
    }

    cout << endl << "请输入名字" << endl;
    std::string name;
    int age;

    cin >> name;
    cout << endl << "请输入年龄" << endl;
    cin >> age;

    Teacher *techer = new Teacher(name, age, id);
    obj.insert(make_pair(id, techer));

    return techer;
  }
};

const int *const f1() { return NULL; }

void test01() {}

int main() {
  FlyWeight *fly = new FlyWeightTeach();
  const Person *t1 = fly->getPerson("001");
  const Person *t2 = fly->getPerson("001");

  t1->printf();
  t2->printf();

  delete (FlyWeightTeach *)fly;

  sleep(1);
  

  return 0;
}
