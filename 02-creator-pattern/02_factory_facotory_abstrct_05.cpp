/*************************************************************************
> File Name: 02-creator-pattern/02-工厂模式-常规做法.cpp
> Author: 
> Mail: 
> Created Time: Mon May 29 21:06:28 2023
 ************************************************************************/

#include<iostream>
using namespace std;

class Window {
  public: 
    virtual void dialog() = 0;
};
class Scroll {
  public: 
    virtual void scroll() = 0;
};



class MicrosoftWindow: public Window {
  public:
    void dialog() override {
      cout << "dialog MicrosoftWindow" << endl;
    }
};
class MicrosoftScroll: public Scroll {

    void scroll() override {
      cout << "scroll MicrosoftWindow" << endl;
    }

};

class MacWindow: public Window {
  public:
    void dialog() override {
      cout << "dialog MacWindow" << endl;
    }
};

class MacScroll: public Scroll {

    void scroll() override {
      cout << "scroll MacScroll" << endl;
    }
};

class Factory {
  public:
    virtual Window * createWindow()  = 0;
    virtual  Scroll* createScroll()  = 0;
};

class MicrosoftFactory :public Factory {
  public:
    Scroll * createScroll() override {
      return new MicrosoftScroll();
    }

    Window * createWindow() override {
      return new MicrosoftWindow();
    }
};

class MacFactory :public Factory {
  public:
    Scroll * createScroll() override {
      return new MacScroll();
    }

    Window * createWindow() override {
      return new MacWindow();
    }
};




// 如果新增一个 Pizza 这个函数里面也要修改

void worker(Factory *f) {
  auto scroll = f->createScroll();
  auto window = f->createWindow();

  scroll->scroll();
  window->dialog();

  free(scroll);
  free(window);

  free(f);
}

int main(){ 

  cout << endl;
  worker(new MicrosoftFactory);

  cout << endl;

  worker(new MacFactory);

  return 0;
}
