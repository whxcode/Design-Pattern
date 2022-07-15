/*************************************************************************
> File Name: 03-proxy/04-game.cpp
> Author: root
> Mail:
> Created Time: 2022年07月15日 星期五 22时15分24秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Hero {
public:
  Hero() { level = 0; }

public:
  virtual void startGame(int base) = 0;

protected:
  int level;
};

class HeroLi : public Hero {
public:
  void startGame(int base) override {
    cout << level << endl;
    while (level <= 100) {
      level += base;
      cout << "level:";
      cout << level << endl;
    }
  }
};

class ProxyLi : public Hero {
public:
  ProxyLi(Hero *l) : li(l) {}

public:
  void startGame(int base) override { li->startGame(base + 10); }

private:
  Hero *li;
};

int main() {
  Hero *li = new HeroLi;
  // li->startGame(1);

  Hero *proxyLi = new ProxyLi(li);

  proxyLi->startGame(1);

  return 0;
}
