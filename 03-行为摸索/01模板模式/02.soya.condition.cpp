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
      if(!isAddCommits()) {
      addCommits();
      }
      beat();
    }
  private:
    virtual int isAddCommits() {
      return 0;
    }

    void select() {
      cout << "选择豆子" << endl;
    }

    virtual void addCommits() {
      
    }
    
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


class PureSoyaMilk:public  SoyaMilk {
  private:
    int isAddCommits() override {
      return 1;
    }
};

void worker(SoyaMilk* soya)  {
  soya->make();
  delete soya;
}

int main(){
  worker(new RedBeaSoyaMilk);
  cout << endl;
  worker(new PeanutSoyaMilk);
  cout << endl;
  worker(new PureSoyaMilk);
  return 0;
}
