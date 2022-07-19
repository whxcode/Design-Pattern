/*************************************************************************
> File Name: 11-Bridge/02.phone.cpp
> Author: root
> Mail:
> Created Time: 2022年07月19日 星期二 21时07分07秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

class Brand {
public:
  virtual void open() = 0;
  virtual void close() = 0;
  virtual void call() = 0;
};

class Mi : public Brand {
public:
  void open() override { cout << "MI open" << endl; }
  void close() override { cout << "MI close" << endl; }
  void call() override { cout << "MI call" << endl; }
};

class Vivo : public Brand {
public:
  void open() override { cout << "Vivo open" << endl; }
  void close() override { cout << "Vivo close" << endl; }
  void call() override { cout << "Vivo call" << endl; }
};

// 充当桥接模式。
class Phone {
public:
  Phone(Brand *brand) { this->brand = brand; }

protected:
  void open() { brand->open(); }
  void close() { brand->close(); }
  void call() { brand->call(); }

protected:
  Brand *brand;
};

class FoldePhone : public Phone {
public:
  FoldePhone(Brand *brand) : Phone(brand) {}

public:
  void open() {
    Phone::open();
    cout << "FoldePhone" << endl;
  }

  void close() {
    Phone::close();
    cout << "FoldePhone" << endl;
  }

  void call() {
    Phone::call();
    cout << "FoldePhone" << endl;
  }
};

class UpRight : public Phone {
public:
  UpRight(Brand *brand) : Phone(brand) {}

public:
  void open() {
    Phone::open();
    cout << "UpRight" << endl;
  }

  void close() {
    Phone::close();
    cout << "UpRight" << endl;
  }

  void call() {
    Phone::call();
    cout << "UpRight" << endl;
  }
};

void test01() {
  Mi *mi = new Mi;
  FoldePhone *fold = new FoldePhone(mi);

  fold->call();
  fold->open();
  fold->close();

  cout << endl;
   Vivo*vivo = new Vivo;
  UpRight* right = new UpRight(vivo);

  right->open();
  right->close();
  right->call();

  delete mi;
  delete vivo;
  delete fold;
  delete right;
}

int main() {

  test01();
  return 0;
}
