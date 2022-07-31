/*************************************************************************
> File Name: 03-结构模式/05-外观模式/01.家庭影院.cpp
> Author: root
> Mail:
> Created Time: 2022年07月31日 星期日 10时58分07秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class DVDPlayer {
public:
  static DVDPlayer *getInstace() { return DVDPlayer::instance; }

public:
  void on() { cout << "dvd on" << endl; }

  void off() { cout << "dvd off" << endl; }

  void play() { cout << "dvd play" << endl; }

private:
  static DVDPlayer *instance;
};

class Popcorn {
public:
  static Popcorn *getInstace() { return Popcorn::instance; }

public:
  void on() { cout << "popcorn on" << endl; }
  void off() { cout << "popcorn off" << endl; }
  void pop() { cout << "popcorn pop" << endl; }

private:
  static Popcorn *instance;
};

class Screen {
public:
  static Screen *getInstace() { return Screen::instance; }

public:
  void on() { cout << "popcorn on" << endl; }
  void off() { cout << "popcorn off" << endl; }
  void pop() { cout << "popcorn pop" << endl; }

private:
  static Screen *instance;
};

DVDPlayer *DVDPlayer::instance = new DVDPlayer;
Popcorn *Popcorn::instance = new Popcorn;
Screen *Screen::instance = new Screen;

class Home {
public:
  Home() {
    this->dvd = DVDPlayer::getInstace();
    this->popcorn = Popcorn::getInstace();
    this->screen = Screen::getInstace();
  }
  ~Home() {
    delete dvd;
    delete popcorn;
    delete screen;
  }

public:
  void ready() {
    dvd->on();
    screen->on();
    popcorn->on();
  }
  void play() { dvd->play(); }

  void eat() { popcorn->pop(); }

  void off() {
    dvd->off();
    popcorn->off();
    screen->off();
  }

private:
  DVDPlayer *dvd;
  Popcorn *popcorn;
  Screen *screen;
};

int main() {
  Home *home = new Home;

  home->ready();
  cout << endl;
  home->play();
  cout << endl;
  home->eat();
  cout << endl;
  home->off();

  return 0;
}
