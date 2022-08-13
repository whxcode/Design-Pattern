/************************************************************************
> File Name: 02.window.案例.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月12日 星期五 23时00分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

class WindowImplementor {
  public:
    virtual void devDrawText() = 0;
    virtual void devDrawLine() = 0;
};

class Window {
  public:
    ~Window() {
      delete imp;
    }
  public:
    virtual void drawText() = 0;
    virtual void drawRect() = 0;
  protected:
    WindowImplementor* imp;
};

class IconWindow:public Window {
  public:
    IconWindow(WindowImplementor* imp) {
      this->imp = imp;
    }
  public:
    void drawRect() override {

    }
    void drawText() override {
      imp->devDrawLine();
      imp->devDrawText();
    }
};

class TransitionWIndowBox:public Window {
  public:
    TransitionWIndowBox(WindowImplementor* imp) {
      this->imp = imp;
    }
  public:
    void drawRect() override {
      imp->devDrawLine();
      imp->devDrawLine();
      imp->devDrawLine();
      imp->devDrawLine();
    }
    void drawText() override {

    }
};

class XWindow: public WindowImplementor {
  public:
    void devDrawLine() override {
      cout << "XWindow line" <<endl;
    }

    void devDrawText() override {
      cout << "XWindow text" <<endl;
    }
};


class PMWindow: public WindowImplementor {
  public:
    void devDrawLine() override {
      cout << "PMWindow line" <<endl;
    }

    void devDrawText() override {
      cout << "PMWindow text" <<endl;
    }
};

void worker(Window *window) {
  window->drawRect();
  window->drawText();

  delete window;
  cout << endl;
}

int main(){
  worker(new IconWindow(new XWindow));
  worker(new IconWindow(new PMWindow));

  cout << endl;
  cout << endl;
  cout << endl;

  worker(new TransitionWIndowBox(new XWindow));
  worker(new TransitionWIndowBox(new PMWindow));

  return 0;
}
