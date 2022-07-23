/*************************************************************************
> File Name: 01-创建型模式/01-抽象工厂模式/01.window.cpp
> Author: root
> Mail:
> Created Time: 2022年07月23日 星期六 17时56分48秒

优点:
  将不同的产品系列，抽象为小的组件，在通过组合他们实现。
缺点:
  要增加新的产品。不得不将 AbstractFactory 类以及它的派生类都给修改。
总结:
  适合产品族已经确定且不会随时变化的系统适用。如果产品系列经常变化，将非常难以维护。
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Window {
public:
  virtual void dispay() = 0;
};

class Scrollbar {
public:
  virtual void scrollbar() = 0;
};

class MacWindow : public Window {
public:
  void dispay() override { cout << "mac window" << endl; }
};

class LinuxWindow : public Window {
public:
  void dispay() override { cout << "linux   window" << endl; }
};

class MacScrollbar : public Scrollbar {
public:
  void scrollbar() override { cout << "mac scrollbar" << endl; }
};

class LinuxScrollbar : public Scrollbar {
public:
  void scrollbar() override { cout << "linux scrollbar" << endl; }
};

class AbstractFactory {
public:
  virtual Window *createWindow() = 0;
  virtual Scrollbar *createScroll() = 0;
};

class MacFactory : public AbstractFactory {
public:
  Scrollbar *createScroll() override { return new MacScrollbar; }
  Window *createWindow() override { return new MacWindow; }
};

class LinuxFactory : public AbstractFactory {
public:
  Scrollbar *createScroll() override { return new LinuxScrollbar; }
  Window *createWindow() override { return new LinuxWindow; }
};

void doThing(AbstractFactory &factory) {
  Window *window = factory.createWindow();
  Scrollbar *scrollbar = factory.createScroll();

  window->dispay();
  scrollbar->scrollbar();

  delete window;
  delete scrollbar;
}

void testMac() {
  MacFactory mac;
  LinuxFactory command;

  doThing(mac);
  cout << endl;
  doThing(command);
}

int main() {
  testMac();
  return 0;
}
