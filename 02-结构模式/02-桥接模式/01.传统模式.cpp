/*************************************************************************
> File Name: 01.传统模式.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月11日 星期四 21时52分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Phone {
  public:
    virtual void call() = 0;
};

class Folded:public Phone {
  public:
    virtual void call() =0;
};

class UpRight:public Phone {
  public:
    virtual void call() =0;
};

class Silder:public Phone {
  public:
    virtual void call() =0;
};


class HuaWeiFolded: public Folded {
  public:
    void call() override {
      cout  << "Folded HuaWei" <<endl;
    }
};


class HuaWeiUpRight: public UpRight {
  public:
    void call() override {
      cout  << "UpRight HuaWei" <<endl;
    }
};

class HuaWeiSilder: public Silder {
  public:
    void call() override {
      cout  << "Silder HuaWei" <<endl;
    }
};


class VivoFolded: public Folded {
  public:
    void call() override {
      cout  << "Folded Vivo" <<endl;
    }
};


class VivoUpRight: public UpRight {
  public:
    void call() override {
      cout  << "UpRight Vivo" <<endl;
    }
};

class VivoSilder: public Silder {
  public:
    void call() override {
      cout  << "Silder Vivo" <<endl;
    }
};

class XiaoMiFolded: public Folded {
  public:
    void call() override {
      cout  << "Folded Vivo" <<endl;
    }
};


class XiaoMiUpRight: public UpRight {
  public:
    void call() override {
      cout  << "UpRight XiaoMi" <<endl;
    }
};

class XiaoMiSilder: public Silder {
  public:
    void call() override {
      cout  << "Silder XiaoMi" <<endl;
    }
};

class AppleFolded: public Folded {
  public:
    void call() override {
      cout  << "Folded Vivo" <<endl;
    }
};


class AppleUpRight: public UpRight {
  public:
    void call() override {
      cout  << "UpRight Apple" <<endl;
    }
};

class AppleSilder: public Silder {
  public:
    void call() override {
      cout  << "Silder Apple" <<endl;
    }
};


void worker(Phone*phone) {
  phone->call();

  delete phone;
  cout << endl;
}

int main(){
  worker(new HuaWeiFolded);
  worker(new HuaWeiUpRight);
  worker(new HuaWeiSilder);

  cout <<endl;
  cout <<endl;

  worker(new XiaoMiFolded);
  worker(new XiaoMiUpRight);
  worker(new XiaoMiSilder);

  cout <<endl;
  cout <<endl;
  worker(new VivoFolded);
  worker(new VivoUpRight);
  worker(new VivoSilder);

  cout <<endl;
  cout <<endl;
  worker(new AppleFolded);
  worker(new AppleUpRight);
  worker(new AppleSilder);
return 0;
}
