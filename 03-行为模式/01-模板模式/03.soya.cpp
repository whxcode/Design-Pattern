/*************************************************************************
> File Name: 03.soya.cpp
> Author: 
> Mail: 
> Created Time: 2022年09月07日 星期三 20时34分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

class SoyaMilk {
  public:
    virtual void make() final {
      select();
      addCondiments();
      soak();
      beat();
    }

    virtual void select() {

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

void worker(SoyaMilk* soya) {
  soya->make();
  
  delete soya;
}

int main(){

  worker(new RedBeanSoya);
  worker(new BlackBeanSoya);

  return 0;
}
