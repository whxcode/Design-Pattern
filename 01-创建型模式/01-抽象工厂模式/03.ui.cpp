/*************************************************************************
> File Name: 01-抽象工厂模式/03.ui.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月10日 星期三 21时48分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Window {

};

class PMWindow: public Window {

};

class MotifyWindow: public Window {

};

class Scrollbar {

};

class PMScrollbar :public Scrollbar {

};

class MotifyScrollbar:public  Scrollbar {
  
};

class UIFactory {
  virtual Window* createWindow() = 0;
  virtual Scrollbar* createScrollbar() = 0;

};

class MotifyFactory :public UIFactory {
  Window * createWindow() override {

    return new MotifyWindow;
  }

  Scrollbar* createScrollbar() override {
    return new MotifyScrollbar();
  }

};


class PMUIFactory :public UIFactory {
  Window * createWindow() override {

    return new PMWindow;
  }

  Scrollbar* createScrollbar() override {
    return new PMScrollbar();
  }

};

int main(){
  return 0;
}
