/*************************************************************************
> File Name: 02.桥接模式.cpp
> Author:
> Mail:
> Created Time: 2022年08月11日 星期四 21时59分20秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Brand {
public:
  virtual void call() = 0;
};

class HuaWei : public Brand {
public:
  void call() override { cout << "HuaWei"; }
};

class Vivo : public Brand {
public:
  void call() override { cout << "Vivo"; }
};

class Apple : public Brand {
public:
  void call() override { cout << "Apple"; }
};

class XiaoMI : public Brand {
public:
  void call() override { cout << "XiaoMI"; }
};

class Phone {
public:
  virtual void call() = 0;

protected:
  Brand *brand;
};

class Folede : public Phone {
public:
  Folede(Brand *brand) { this->brand = brand; }
  ~Folede() { delete brand; }

public:
  void call() override { brand->call(); cout << "Folede" <<endl;} 
};

class UpRight : public Phone {
public:
  UpRight(Brand *brand) { this->brand = brand; }
  ~UpRight() { delete brand; }

public:
  void call() override { brand->call(); cout << "UpRight" <<endl;}
};

class Silder : public Phone {
public:
  Silder(Brand *brand) { this->brand = brand; }
  ~Silder() { delete brand; }

public:
  void call() override { brand->call(); cout << "Silder" <<endl;}
};

void worker(Phone *phone) {
  phone->call();

  delete phone;
  cout << endl;
}

int main() {
  worker(new Folede(new HuaWei));
  worker(new UpRight(new HuaWei));
  worker(new Silder(new HuaWei));

  cout <<endl;
  cout <<endl;

  worker(new Folede(new Vivo));
  worker(new UpRight(new Vivo));
  worker(new Silder(new Vivo));

  cout <<endl;
  cout <<endl;

  worker(new Folede(new Apple));
  worker(new UpRight(new Apple));
  worker(new Silder(new Apple));

  cout <<endl;
  cout <<endl;

  worker(new Folede(new XiaoMI));
  worker(new UpRight(new XiaoMI));
  worker(new Silder(new XiaoMI));

  return 0;
}
