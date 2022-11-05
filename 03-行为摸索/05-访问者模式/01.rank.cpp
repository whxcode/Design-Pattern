/*************************************************************************
> File Name: 01.rank.cpp
> Author: 
> Mail: 
> Created Time: 2022年11月05日 星期六 20时35分25秒
 ************************************************************************/

#include <iostream>
#include <list>

using namespace std;
class Person;

class Action {
  public:
    virtual void getResult(Person* p) = 0;
};

class Success: public Action {
  void getResult(Person *p) override{
    cout << "成功" << endl;
  }
};

class Fail: public Action {
  void getResult(Person *p) override{
    cout << "失败" << endl;
  }
};

class Person {
  public:
    virtual void accept(Action *action)  =0;
};


class Man: public Person {
  public:
    void accept(Action *action) override {
      action->getResult(this);
    }
};

class Woman: public Person {
  public:
    void accept(Action *action) override {
      action->getResult(this);
    }
};

class  Manager {
  public:
    Manager() {
      ps.clear();
    }
    ~Manager() {
  for(auto it : ps) {
    delete it;
    // it->accept(&f);
  }
    }
  public:
    void attach(Person *p) {
      ps.push_back(p);
    }

    void remove(Person *p) {
      ps.remove(p);
    }

    void display(Action* c){
  for(auto it : ps) {
    it->accept(c);
  }
    }
    private:
  list<Person *>ps;

};




void test01() {
  list<Person *>ps;
  ps.clear();
  ps.push_back(new Man);
  ps.push_back(new Woman);

  Success s;
  Fail f;

  for(auto it : ps) {
    it->accept(&s);
  }
  cout <<  endl;

  for(auto it : ps) {
    it->accept(&f);
  }

  for(auto it : ps) {
    delete it;
    // it->accept(&f);
  }
}

void test02() {
  Manager ps;
  ps.attach(new Man);
  ps.attach(new Woman);

  Success s;
  Fail f;


  ps.display(&f);
  cout << endl;
  ps.display(&s);

}

int main(){
  // test01();
   test02();

  return 0;
}
