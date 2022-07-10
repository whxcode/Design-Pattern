/*************************************************************************
> File Name: 01-signal-lampl.cpp
> Author:
> Mail:
> Created Time: 2022年07月10日 星期日 16时59分20秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Listenner {
public:
  virtual void onTeacherComming() const = 0;
  virtual void doBadthing() const = 0;
};

class Notifier {
public:
  virtual Notifier *addListenner(Listenner *listenner) = 0;

  virtual Notifier *deleteListenner(Listenner *listenner) = 0;

  virtual Notifier *notifyAllListenner() = 0;
};

class Student : public Listenner {
public:
  Student(string name) { this->name = name; }

public:
  void onTeacherComming() const override {
    cout << "学生:" << name << "停止干坏事,目前修改为写作业" << endl;
  }

  void doBadthing() const override {
    cout << "学生:" << name << "正在干坏事" << endl;
  }

private:
  string name;
};

class Monitor : public Notifier {
public:
  Monitor *addListenner(Listenner *listenner) override {
    this->m_list.push_back(listenner);
    return this;
  }
  Monitor *deleteListenner(Listenner *listenner) override { return this; }
  Monitor *notifyAllListenner() override {

    list<Listenner *>::iterator it = m_list.begin();
    list<Listenner *>::iterator end = m_list.end();

    while (it != end) {
      (*it++)->onTeacherComming();
    }

    return this;
  }

private:
  list<Listenner *> m_list;
};

int main() {
  Student *s1 = new Student("张三");
  Student *s2 = new Student("李四");
  Student *s3 = new Student("王五");

  Notifier *bossXu = new Monitor();

  bossXu->addListenner(s1)
      ->addListenner(s2)
      ->addListenner(s3)
      ->notifyAllListenner();

  return 0;
}
