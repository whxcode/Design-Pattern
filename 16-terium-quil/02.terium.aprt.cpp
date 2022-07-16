/*************************************************************************
> File Name: 16-terium-quil/01.part.cpp
> Author: root
> Mail: 
> Created Time: 2022年07月16日 星期六 17时32分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
enum ESex {
  EFemale,
  EMale,
};

class Person;
class Medium {
  public:
    virtual void getParter(Person *male,Person* female) = 0;
};

class Person {
  public:
    Person(string name,int age,int condi,ESex sex) {
      this->name = name;
      this->age = age;
      this->condi = condi;
      this->sex = sex;
    }

    inline int getCond(){
      return condi;
    }

    inline ESex getSex(){
      return sex;
    }

    virtual void getParter(Person *p) =0;

  protected:
    string name;
    ESex sex;
    int age;
    int condi;
};

class Female: public Person {
  public:
    Female(string n,int a,int c,ESex s):Person(n,a,c,s) {

    }
  public:
    void getParter(Person *p) override {
      if(p->getSex() == this->getSex()) {
        cout <<"我不是同性恋" <<endl;
        return;
      }

      if(p->getCond() != this->getCond()) {
        cout << "达不到我的要求" << endl;
        return;
      }

      cout << "可以匹配" <<endl;
    }


};

class Male: public Person {
  public:
    Male(string n,int a,int c,ESex s):Person(n,a,c,s) {

    }
    void getParter(Person *p) override{}

};

class WomanMatchMaker:public Medium {
  public:
    void getParter(Person *a,Person* b) override {
      a->getParter(b);
    }

};

void test01() {
  Female* cat = new Female("小秒",10,10,EFemale);
  Male* dog = new Male("dog",10,10,EFemale);
  Male* duck = new Male("duck",10,10,EMale);

  cat->getParter(dog);
  cat->getParter(duck);
}

void test02() {
  Female* cat = new Female("小秒",10,10,EFemale);
  Male* dog = new Male("dog",10,10,EFemale);
  Male* duck = new Male("duck",10,10,EMale);

  Medium *woman = new WomanMatchMaker();

  woman->getParter(cat,dog);
  cout << endl;  
  woman->getParter(cat,duck);
}
  
int main(){
  test02();
  // test01();
return 0;
}
