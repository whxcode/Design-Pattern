/*************************************************************************
> File Name: 01-signle.cpp
> Author:
> Mail:
> Created Time: 2022年07月04日 星期一 21时02分28秒
 ************************************************************************/

#include <iostream>
using namespace std;

class TakeManage {
public:
  static TakeManage *getInstance() { return TakeManage::instance; }

private:
  TakeManage(){};
  static TakeManage *instance;
};

TakeManage *TakeManage::instance = new TakeManage();

class Cat {
public:
  static Cat *getInstance() {
    if (Cat::instance == NULL) {
      Cat::instance = new Cat();
    };

    return Cat::instance;
  }

  void add() { cout << "add\n"; }

private:
  Cat(){

  };
  static Cat *instance;
};

Cat *Cat::instance = NULL;

int console() {
  TakeManage *take1 = TakeManage::getInstance();
  TakeManage *take2 = TakeManage::getInstance();

  bool a = take1 == take2;

  cout << a << endl;

  Cat::getInstance()->add();
  Cat::getInstance()->add();
  Cat::getInstance()->add();

  return 0;
}
