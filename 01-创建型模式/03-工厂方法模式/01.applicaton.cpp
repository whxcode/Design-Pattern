/*************************************************************************
> File Name: 01-创建型模式/03-工厂方法模式/01.applicaton.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 20时50分31秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Application {
public:
  virtual void display() const = 0;
};

class LinuxApplication : public Application {
public:
  void display() const override { cout << "linux" << endl; }
};

class WindowApplication : public Application {
public:
  void display() const override { cout << "window" << endl; }
};

class ApplicationFactory {
public:
  virtual Application *createApplication() const = 0;
};

class LinuxApplicationFactory : public ApplicationFactory {
public:
  Application *createApplication() const override {
    return new LinuxApplication;
  }
};

class WindowApplicationFactory : public ApplicationFactory {
public:
  Application *createApplication() const override {
    return new WindowApplication;
  }
};



void worker(ApplicationFactory *factory) {
  factory->createApplication()->display();
}

int main() {
  LinuxApplicationFactory *l = new LinuxApplicationFactory();
  WindowApplicationFactory *w = new WindowApplicationFactory();

  worker(l);
  worker(w);

  return 0;
}
