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
  virtual bool customerWantCondiments() { return true; }

public:
  virtual void make() final {
    select();

    if (customerWantCondiments()) {
      addIngredients();
    }
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

class PureSoya : public SoyaMilk {
private:
  void addIngredients() override { cout << "添加黄豆" << endl; }
  bool customerWantCondiments() override { return false; }
};

void test01() {
  PennutSoyaMilk *pennut = new PennutSoyaMilk;
  RedBeanSoyaMilk *redBean = new RedBeanSoyaMilk;
  PureSoya *pureBean = new PureSoya;

  pennut->make();
  cout << endl;
  redBean->make();
  cout << endl;
  pureBean->make();

  delete pennut;
  delete redBean;
  delete pureBean;
}

int main() {
  test01();
  return 0;
}
