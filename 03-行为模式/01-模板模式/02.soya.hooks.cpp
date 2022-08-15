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

class PureBeanSoyaMilk : public SoyaMilk {
protected:
  void addCondiments() override {  }
};


void makeSoya(SoyaMilk *soya) {
  soya->make();

  delete soya;
}

int main() {
  makeSoya(new RedSBeanSoyaMilk);
  cout << endl;
  cout << endl;
  makeSoya(new PennutBeanSoyMilk);
  cout << endl;
  cout << endl;
  makeSoya(new PureBeanSoyaMilk);

  return 0;
}
