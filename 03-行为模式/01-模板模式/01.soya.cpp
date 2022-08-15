/*************************************************************************
> File Name: 01.soya.cpp
> Author:
> Mail:
> Created Time: 2022年08月14日 星期日 18时32分26秒
 ************************************************************************/

#include <iostream>
using namespace std;

class SoyaMilk {
public:
  virtual void make() final {
    select();
    addCondiments();
    soak();
    beat();
  }

protected:
  void select() { cout << "选择豆子" << endl; }

  virtual void addCondiments() = 0;
  void soak() { cout << "侵泡豆子" << endl; }
  void beat() { cout << "放置豆浆机器，打豆浆出来" << endl; }
};

class RedSBeanSoyaMilk : public SoyaMilk {
protected:
  void addCondiments() override { cout << "加入红豆子" << endl; }
};

class PennutBeanSoyMilk : public SoyaMilk {
protected:
  void addCondiments() override { cout << "加入花生" << endl; }
};

void makeSoya(SoyaMilk *soya) {
  soya->make();

  delete soya;
}

int main() {
  makeSoya(new RedSBeanSoyaMilk);
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  makeSoya(new PennutBeanSoyMilk);

  return 0;
}
