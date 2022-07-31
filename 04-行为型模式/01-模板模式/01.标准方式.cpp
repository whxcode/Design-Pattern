/*************************************************************************
> File Name: 04-行为型模式/01-模板模式/01.标准方式.cpp
> Author: root
> Mail:
> Created Time: 2022年07月31日 星期日 21时40分18秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class SoyaMilk {
public:
  // 添加原材料
  virtual void make() final {
    select();
    add();
    soak();
    beat();
  };

protected:
  virtual void add() = 0;

private:
  // 原则原材料。
  virtual void select() final { cout << "select  SoyaMilk" << endl; }
  virtual void soak() final { cout << "soak SoyaMilk"; }
  virtual void beat() { cout << "beat SoyaMilk" << endl; }
};

class BlackBeanSoyaMilk : public SoyaMilk {
protected:
  void add() override { cout << "add BlackBeanSoyaMilk " << endl; }
};

class PeanutSoyaMilk : public SoyaMilk {
protected:
  void add() override { cout << "add PeanutSoyaMilk " << endl; }
};

int main() {
  PeanutSoyaMilk *peanut = new PeanutSoyaMilk;
  BlackBeanSoyaMilk *bean = new BlackBeanSoyaMilk;

  peanut->make();
  bean->make();

  delete peanut;
  delete bean;

  return 0;
}
