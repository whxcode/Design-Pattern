/*************************************************************************
> File Name: 01.soya.cpp
> Author: 
> Mail: 
> Created Time: 2022年10月15日 星期六 19时47分18秒
 ************************************************************************/

#include<iostream>
using namespace std;
class SoyaMilk {
  public:
    virtual  void make() final {
      select();
      addCommits();
      beat();
    }
  private:
    void select() {
      cout << "选择豆子" << endl;
    }

    virtual void addCommits() = 0;
    
    void soya() {
      cout << "侵泡豆子" << endl;
    }
    void beat() {
      cout << "开始打豆浆" << endl;
    }
};

class RedBeaSoyaMilk:public  SoyaMilk {
  private:
    void addCommits() override {
      cout << "选这🧋" <<endl;
    }
};

class PeanutSoyaMilk:public  SoyaMilk {
  private:
    void addCommits() override {
      cout << "选这🥜" <<endl;
    }
};

void worker(SoyaMilk* soya)  {
  soya->make();
}

int main(){
  worker(new RedBeaSoyaMilk);
  cout << endl;
  worker(new PeanutSoyaMilk);
  return 0;
}
