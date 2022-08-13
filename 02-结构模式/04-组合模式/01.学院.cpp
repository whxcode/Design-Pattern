/*************************************************************************
> File Name: 01.学院.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月13日 星期六 11时56分46秒
 ************************************************************************/

#include<iostream>
#include<list>

using namespace std;

class Organization {
  public:
    virtual void add(Organization* o)  {

    }

    virtual void remove(Organization* o)  {

    }
    virtual void display() = 0;
  protected:
    string name;
};


class University :public Organization {
  public:
    University(string name) {
      this->name = name;
      l.clear();
    }
    ~University() {
      for(auto it : l) {
        delete it;
        // it->display();
      }

    }
  public:
    void add(Organization *o) override {
      l.push_back(o);
    }
    void remove(Organization *o) override {
      l.remove(o);
    }
    void display() override {
      cout << "University:" << name << endl;

      for(auto it : l) {
        it->display();
      }

      cout << "-----" <<endl;
    }
  private:
   list<Organization* > l;
};

class College :public Organization {
  public:
    College(string name) {
      this->name = name;
      l.clear();
    }
    ~College() {
      for(auto it : l) {
        delete it;
        // it->display();
      }

    }
  public:
    void add(Organization *o) override {
      l.push_back(o);
    }
    void remove(Organization *o) override {
      l.remove(o);
    }
    void display() override {
      cout << "College:" << name << endl;

      for(auto it : l) {
        it->display();
      }

      cout << "-----" <<endl;
    }
  private:
   list<Organization* > l;
};


class Department :public Organization {
  public:
    Department(string name) {
      this->name = name;
    }
  public:
    void display() override {
      cout << "Department:" << name << endl;
    }
};
int main(){
  University* university = new University("大学");
  College* info = new College("计算机学院");
  College* computer = new College("信息工程");

  info->add(new Department("软件工程"));
  info->add(new Department("网络工程"));
  info->add(new Department("计算机科学与技术"));

  computer->add(new Department("通信工程"));
  computer->add(new Department("土木工程"));

  university->add(info);
  university->add(computer);

  university->display();

  delete university;

  return 0;
}
