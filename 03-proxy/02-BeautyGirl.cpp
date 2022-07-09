/*************************************************************************
> File Name: 02-BeautyGirl.cpp
> Author:
> Mail:
> Created Time: 2022年07月05日 星期二 21时10分52秒
 ************************************************************************/

#include <iostream>
using namespace std;

class BeautyGirl {
public:
  virtual void MakeEysWithMan() = 0;
  virtual void HappyWithMan() = 0;
};

class JinLian : public BeautyGirl {
public:
  virtual void MakeEysWithMan() override {
    cout << "JinLian MakeEysWithMan" << endl;
  }
  virtual void HappyWithMan() override {
    cout << "JinLian HappyWithMan" << endl;
  }
};

class WangPo : public BeautyGirl {
public:
  WangPo(JinLian *jinLian) { this->girl = jinLian; }
  virtual void MakeEysWithMan() override { this->girl->MakeEysWithMan(); }
  virtual void HappyWithMan() override { this->girl->HappyWithMan(); }

private:
  BeautyGirl *girl;
};

int console() {
  JinLian *jinLan = new JinLian();
  WangPo *wangPo = new WangPo(jinLan);

  wangPo->MakeEysWithMan();
  wangPo->HappyWithMan();

  return 0;
}
