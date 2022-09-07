#include<iostream>
using namespace std;

class SoyaMilk {
  public:
    virtual void make() final {
      select();
      if(isAddCondiments()) {

      addCondiments();
      }
      soak();
      beat();
    }

    virtual void select() {

    }
    virtual bool isAddCondiments() {
      return true;
    }

    virtual void addCondiments() = 0;

  private:
    void soak() {

    }

    void beat() {

    }


};


class  RedBeanSoya :public SoyaMilk {
  public:
    void addCondiments() override {
      cout << "添加红豆" << endl;
    }
};

class  BlackBeanSoya :public SoyaMilk {
  public:
    void addCondiments() override {
      cout << "添加黑豆" << endl;
    }
};

class  PureBeanSoya :public SoyaMilk {
  public:
    void addCondiments() override {
    }
};

void worker(SoyaMilk* soya) {
  soya->make();
  
  delete soya;
}

int main(){

  worker(new RedBeanSoya);
  worker(new BlackBeanSoya);
  worker(new PureBeanSoya);

  return 0;
}
