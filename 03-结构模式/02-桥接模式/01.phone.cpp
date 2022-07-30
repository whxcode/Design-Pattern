/*************************************************************************
> File Name: 03-结构模式/02-桥接模式/01.phone.cpp
> Author: root
> Mail:
> Created Time: 2022年07月30日 星期六 17时21分28秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Brand {
public:
  virtual void call() = 0;
};

class Vivo : public Brand {
  void call() override { cout << "Vivo call" << endl; }
};

class XiaoMi : public Brand {
  void call() override { cout << "XiaMi call" << endl; }
};

class Phone {
public:
  Phone(Brand *brand) { this->brand = brand; }
  ~Phone() { delete brand; }

public:
  void call() { brand->call(); }

private:
  Brand *brand;
};

class RightUpPhone : public Phone {
public:
  RightUpPhone(Brand *brand) : Phone(brand) {}

public:
  void call() {
    cout << "RightUpPhone call" << endl;
    this->Phone::call();
  }
};

class FoldedPhone : public Phone {
public:
  FoldedPhone(Brand *brand) : Phone(brand) {}

public:
  void call() {
    cout << "FoldedPhone call" << endl;
    this->Phone::call();
  }
};

int main() {
  FoldedPhone*foldedXm =new FoldedPhone(new XiaoMi);
  FoldedPhone*foldedVo =new FoldedPhone(new Vivo);

  foldedVo->call();
  foldedXm->call();

  return 0;
}
