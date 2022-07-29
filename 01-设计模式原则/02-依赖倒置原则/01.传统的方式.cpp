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
/**
 * 1、简单
 * 2、如果新增新的消息类，同时 Person 也要增加新的接受方法。
 *
 * */

class Email {
public:
  string getMessage() { return "Hello Email"; }
};

class Person {
public:
  void receive(Email *email) { cout << email->getMessage() << endl; }
};

int main() {
  Person *person = new Person;
  Email *email = new Email;

  person->receive(email);

  return 0;
}
