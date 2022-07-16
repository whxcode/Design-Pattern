/*************************************************************************
> File Name: 09-strategy/03.strategy.cpp
> Author: root
> Mail: 
> Created Time: 2022年07月16日 星期六 17时06分36秒
 ************************************************************************/

#include<iostream>
#include <string>

using namespace std;


class Crypt {
  public:
    virtual string crypt(string text) = 0;
};

class  SymmetricEncryption: public Crypt{
  public:
    string crypt(string text) override {
      return text;
    }

};

class  AsymmetricEncryption: public Crypt{
  public:
    string crypt(string text) override {
      text.append("whx");

      return  text;
    }
};

class Context:public Crypt {
  public:
    void setCrypt(Crypt* crypt) {
      this->mCrypt= crypt;
    }

    string crypt(string text) override  {
      return this->mCrypt->crypt(text);
    }

  private:
    Crypt *mCrypt;
};

int main(){
  Crypt *symmetrictCrypt = new SymmetricEncryption;
  Crypt *asymmetrctCrypt = new AsymmetricEncryption;

  Context* context = new Context;

  context->setCrypt(symmetrictCrypt);
  cout<< context->crypt("whx")<<endl;

  context->setCrypt(asymmetrctCrypt);
  cout<< "2:"<<context->crypt("whx")<<endl;

  return 0;
}
