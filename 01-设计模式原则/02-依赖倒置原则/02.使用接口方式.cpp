/*************************************************************************
> File Name: 02-依赖倒置原则/01.传统的方式.cpp
> Author: root
> Mail:
> Created Time: 2022年07月26日 星期二 21时25分51秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Message {
public:
  virtual string getMessage() = 0;
};

class Email : public Message {
public:
  string getMessage() { return "Hello Email"; }
};

class Google : public Message {
public:
  string getMessage() { return "Hello Google"; }
};

class Person {
public:
  void receive(Message *msg) { cout << msg->getMessage() << endl; }
};

int main() {
  Person *person = new Person;
  Email *email = new Email;
  Google *google = new Google;

  person->receive(email);
  person->receive(google);

  delete person;
  delete email;
  delete google;

  return 0;
}
