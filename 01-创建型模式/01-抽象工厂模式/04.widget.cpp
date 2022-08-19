/*************************************************************************
> File Name: 04.widget.cpp
> Author:
> Mail:
> Created Time: 2022年08月18日 星期四 22时41分20秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Window {
public:
  virtual void display() = 0;
};

class Scrollbar {
public:
  virtual void scrollTo() = 0;
};

class PMWindow : public Window {
public:
  void display() override { cout << "PMWindow" << endl; }
};

class MotifyWindow : public Window {
public:
  void display() override { cout << "MotifyWindow" << endl; }
};

class PMScrollbar : public Scrollbar {
public:
  void scrollTo() override { cout << "PMScrollbar" << endl; }
};

class MotifyScrollbar : public Scrollbar {
public:
  void scrollTo() override { cout << "MotifyScrollbar" << endl; }
};

class WidgetFactory {
public:
  virtual Window *createWindow() = 0;
  virtual Scrollbar *createScroll() = 0;
};

class PMFactory : public WidgetFactory {
public:
  Scrollbar *createScroll() override { return new PMScrollbar(); }
  Window *createWindow() override { return new PMWindow(); }
};

class MotifyFactory : public WidgetFactory {
public:
  Scrollbar *createScroll() override { return new MotifyScrollbar(); }
  Window *createWindow() override { return new MotifyWindow(); }
};

void worker(WidgetFactory *factory) {
  Scrollbar *s = factory->createScroll();
  Window *w = factory->createWindow();

  s->scrollTo();
  w->display();

  delete factory;
  delete s;
  delete w;
}

int main() {
  worker(new PMFactory);
  cout << endl;
  worker(new MotifyFactory);

  return 0;
}
