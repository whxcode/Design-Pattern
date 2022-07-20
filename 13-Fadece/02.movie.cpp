/*************************************************************************
> File Name: 13-Fadece/02.movie.cpp
> Author: root
> Mail:
> Created Time: 2022年07月20日 星期三 22时09分31秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

class DvdPlayer {
public:
  static DvdPlayer *getInstace() { return DvdPlayer::instace; }

public:
  void on() { cout << "dvd on" << endl; }

  void play() { cout << "dvd play" << endl; }

  void off() { cout << "dvd off" << endl; }

private:
  static DvdPlayer *instace;
};

class Popcorn {
public:
  static Popcorn *getInstace() { return Popcorn::instace; }

public:
  void on() { cout << "Popcorn on" << endl; }
  void play() { cout << "Popcorn play" << endl; }

  void off() { cout << "Popcorn off" << endl; }

private:
  static Popcorn *instace;
};

class Television {
public:
  static Television *getInstace() { return Television::instace; }

public:
  void on() { cout << "Popcorn on" << endl; }
  void play() { cout << "Popcorn play" << endl; }

  void off() { cout << "Popcorn off" << endl; }

private:
  static Television *instace;
};

DvdPlayer*  DvdPlayer::instace = new DvdPlayer;
Popcorn*  Popcorn::instace = new Popcorn;
Television*  Television::instace = new Television;

class HomeTheaterFacade {
public:
  HomeTheaterFacade() {
    dvd = DvdPlayer::getInstace();
    popcorn = Popcorn::getInstace();
    television = Television::getInstace();
  }

public:
  void read() {
    popcorn->on();
    dvd->on();
    television->on();
  };

  void play() {
    popcorn->play();
    dvd->play();
    television->play();
  };

  void off() {
    popcorn->off();
    dvd->off();
    television->off();
  }
private:
  DvdPlayer *dvd;
  Popcorn *popcorn;
  Television *television;
};

void test01() {
  HomeTheaterFacade* f = new HomeTheaterFacade;

  f->read();
  f->play();
  f->off();

}

int main() { 
  test01();
  return 0; }
