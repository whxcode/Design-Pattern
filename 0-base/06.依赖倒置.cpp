/*************************************************************************
> File Name: 0-base/06.依赖倒置.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 09时09分39秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct Message {
public:
  virtual void getMessage() const = 0;
};

struct Email : public Message {
public:
  void getMessage() const override { cout << "Hello Email" << endl; }
};

struct WeChat : public Message {
public:
  void getMessage() const override { cout << "Hello WeChat" << endl; }
};

struct Person {
public:
  void receive(Message *email) { email->getMessage(); }
};

int main() {
  Email *e = new Email;
  WeChat *w = new WeChat;
  Person *p = new Person;

  p->receive(e);
  p->receive(w);

  return 0;
}
