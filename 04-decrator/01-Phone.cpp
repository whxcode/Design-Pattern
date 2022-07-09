/*************************************************************************
> File Name: 01-Phone.cpp
> Author:
> Mail:
> Created Time: 2022年07月06日 星期三 20时57分52秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Phone {
public:
  virtual void show()  = 0;
};

class IPhone : public Phone {
  virtual void show()  override { cout << "🍎" << endl; }
};

class MI : public Phone {
  virtual void show()  override { cout << "🦐" << endl; }
};

class Decorator : public Phone {
public:
  Decorator(Phone *phone) { this->phone = phone; }
  virtual void show()  = 0;

protected:
  Phone *phone;
};

class Shell : public Decorator {
public:
  Shell(Phone *phone) : Decorator(phone) {}
  virtual void show()  override {
    this->phone->show();
    this->shell();
  }

private:
  void shell()  { cout << "shell" << endl; }
};

class Sheath : public Decorator {
public:
  Sheath(Phone *phone) : Decorator(phone) {}
  virtual void show()  override {
    this->phone->show();
    this->sheath();
  }

private:
  void sheath()  { cout << "sheath" << endl; }
};


int main() {
  Phone *apple = new IPhone();
  apple->show();

  Phone *shell = new Shell(apple);
  shell->show();

  Phone *sheath = new Sheath(apple);
  sheath->show();

  return 0;
}
