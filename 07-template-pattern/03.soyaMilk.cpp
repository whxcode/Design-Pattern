/*************************************************************************
> File Name: 07-template-pattern/03.soyaMilk.cpp
> Author: root
> Mail:
> Created Time: 2022年07月23日 星期六 08时07分22秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class SoyaMilk {
private:
  void select() { cout << "选好新鲜的豆浆" << endl; }
  virtual void addIngredients() = 0;
  void soak() { cout << "黄豆和配两开始侵泡" << endl; }
  void beat() { cout << "放到豆浆及打损，开始作豆浆。" << endl; }

public:
  virtual void make() final {
    select();
    addIngredients();
    soak();
    beat();
  }
};

class RedBeanSoyaMilk : public SoyaMilk {
private:
  void addIngredients() override { cout << "添加红豆" << endl; }
};

class PennutSoyaMilk : public SoyaMilk {
private:
  void addIngredients() override { cout << "添加花生" << endl; }
};

void test01() {
  SoyaMilk *pennut = new PennutSoyaMilk;
  SoyaMilk *redBean = new RedBeanSoyaMilk;

  pennut->make();
  redBean->make();
}
int main() {
  test01();
  return 0;
}
