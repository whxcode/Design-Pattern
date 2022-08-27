/*************************************************************************
> File Name: 03.window.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月27日 星期六 21时36分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

class WindowImp {
  public:
    virtual void drawLine() = 0;
    virtual void drawText() = 0;
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
    WindowImp* imp;
};


class XWindow:public Window {
  public:
    XWindow(WindowImp* imp) {
      this->imp = imp;
    }
  public:
    void drawRect() override {
      cout << "XWindow:" ;
      imp->drawLine();
    }
    void drawText()  override {
      cout << "XWindow:" ;
      imp->drawText();
    }
};

class TranslentWindow:public Window {
  public:
    TranslentWindow(WindowImp* imp) {
      this->imp = imp;
    }
  public:
    void drawRect() override {
      cout << "TranslentWindow:" ;
      imp->drawLine();
    }
    void drawText()  override {
      cout << "TranslentWindow:" ;
      imp->drawText();
    }
};


class XWindowImp:public WindowImp {
  public:
    void drawLine() override {
      cout << "XWindowImp Line" <<endl;
    }
    void drawText() override {
      cout << "XWindowImp Text" <<endl;
    }
};

class PMWindowImp:public WindowImp {
  public:
    void drawLine() override {
      cout << "PMWindowImp Line" <<endl;
    }
    void drawText() override {
      cout << "PMWindowImp Text" <<endl;
    }
};


void worker(Window* w) {

  w->drawRect();
  w->drawText();

  delete w;
}



int main(){
  worker(new XWindow(new XWindowImp()));
  worker(new XWindow(new PMWindowImp()));

  cout << endl;
  cout << endl;

  worker(new TranslentWindow(new XWindowImp()));
  worker(new TranslentWindow(new PMWindowImp()));

  return 0;
}
