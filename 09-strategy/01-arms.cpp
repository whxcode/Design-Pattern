/*************************************************************************
> File Name: 01-arms.cpp
> Author:
> Mail:
> Created Time: 2022年07月10日 星期日 16时13分22秒
 ************************************************************************/

#include <iostream>
using namespace std;

class AbstractStrategy {

public:
  virtual void useWeapon() const = 0;
};

class KnifeStrategy : public AbstractStrategy {

public:
  void useWeapon() const override {
    cout << "使用 KnifeStrategy 进行攻击 " << endl;
  };
};

class AkGun : public AbstractStrategy {

public:
  void useWeapon() const override { cout << "使用 AK47 进行攻击 " << endl; };
};

class Hero {
public:
  Hero() { arms = NULL; }
  void setArms(const AbstractStrategy *arms) volatile { this->arms = arms; }
  void attack() const { this->arms->useWeapon(); }

private:
  const AbstractStrategy *arms;
};

int main() {
  const AbstractStrategy *knife = new KnifeStrategy();
  const AbstractStrategy *akGun = new AkGun();

  Hero *hero = new Hero();

  hero->setArms(knife);
  hero->attack();

  hero->setArms(akGun);
  hero->attack();

  return 0;
}
