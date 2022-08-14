/*************************************************************************
> File Name: 01.标准实现.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月12日 星期五 22时53分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Implementor {
  public:
    virtual string execute() = 0;
};

class Absctraction {
  public:
    ~Absctraction() {
      delete imp;
    }
  public:
    virtual void call() =0;
  protected:
    Implementor* imp;
};

class Apple :public Absctraction {
  public:
    Apple(Implementor* imp) {
      this->imp = imp;
    }
  public:
    void call() override {
      cout << "Apple:" << imp->execute() << endl;;
    }
};

class X5:public Implementor {
  public:
    string execute() override {
      return "i'm is x5";
    }
};

class X10:public Implementor {
  public:
    string execute() override {
      return "i'm is x10";
    }
};


class Google :public Absctraction {
  public:
    Google(Implementor* imp) {
      this->imp = imp;
    }
  public:
    void call() override {
      cout << "Google:" << imp->execute() << endl;;
    }
};


void worker(Absctraction* abs) {
  abs->call();

  delete abs;
}

int main(){
  worker(new Apple(new X5));
  worker(new Apple(new X10));

  cout << endl;

  worker(new Google(new X5));
  worker(new Google(new X10));
  return 0;
}
