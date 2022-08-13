/*************************************************************************
> File Name: 01.smart.family.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月13日 星期六 16时54分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Dvd {
  public:
    void open() {
      cout << "open dvd" << endl;
    }
    void close() {
      cout << "close dvd" << endl;
    }
};

class Screen {
  public:
    void open() {
      cout << "open screen" << endl;
    }
    void close() {
      cout << "close screen" << endl;
    }
};

class Light {
  public:
    void open() {
      cout << "open light" << endl;
    }
    void close() {
      cout << "close light" << endl;
    }
};

class Controll {
  public:
    Controll() {
      dvd  = new Dvd;;
      screen = new Screen;;
      light  = new Light;;
    }
  public:
    static Controll* getInstance() {
      return Controll::instance;
    }
  public:
    void seeFilm() {
      light->close();
      dvd->open();
      screen->open();
    }

    void night() {
      dvd->close();
      screen->close();
      light->close();
    }

    void free() {
      delete dvd;
      delete screen;
      delete light;

      delete this;
    }
  private:
    Dvd* dvd;
    Screen* screen;
    Light* light;
    static Controll* instance;
};

Controll* Controll::instance = new Controll;

int main(){
   Controll*controll = Controll::getInstance();

   controll->seeFilm();
   cout << endl;
   controll->night();

  return 0;
}
