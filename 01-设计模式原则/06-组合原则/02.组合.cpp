/*************************************************************************
> File Name: 01-设计模式原则/06-组合原则/01.继承.cpp
> Author: root
> Mail:
> Created Time: 2022年07月29日 星期五 19时27分58秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Dog {
public:
  void kit() { cout << "咬人拉" << endl; }
};

class Cat : public Dog {
public:
  Cat(Dog *dog) { this->dog = dog; }
  ~Cat() {
    delete dog;
  }

public:
  void scratch() { cout << "抓伤人了" << endl; }

private:
  Dog *dog;
};

int main() {
  Cat *cat = new Cat(new Dog);

  cat->scratch();
  cat->kit();

  delete cat;

  return 0;
}
