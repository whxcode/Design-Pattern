/*************************************************************************
> File Name: 01.computer.cpp
> Author: 
> Mail: 
> Created Time: 2022年10月31日 星期一 21时15分53秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<list>

using namespace std;

class DepartMent {
  public:
    DepartMent(string name,int age) {
      this->name = name;
      this->age =age;
    }
  public:
    void print() {
      cout << "name:" << name << "   " << "age: " << age << endl;
    }
  private:
    string name;
    int age;

};

class Iterator {
  public:
  virtual bool hasNext() = 0;
  virtual DepartMent* next() = 0;
  virtual void remove() = 0;
};


class ComputerCollegeIterator:public Iterator {
  public:
    ComputerCollegeIterator(int size,DepartMent *(*departments)[10]) {
      this->departments = departments;
      this->pos = 0;
      this->size  = size;;

    }
  public:
    bool hasNext() override {
      return  pos > size;
    }
    DepartMent * next() override {
      DepartMent* d =  (*departments)[this->pos ++ ];

      return  d;
    }

    void remove() override {

    }
  private:
    DepartMent *(*departments)[10];
    int pos;
    int size;
};

class InfoCollegeIterator:public Iterator {
  public:
    InfoCollegeIterator(list<DepartMent*> *departments) {
      this->departments = departments;
     it= departments->begin();
    }
  public:

    bool hasNext() override {
      return (this->it) != this->departments->end();

    }

    DepartMent * next() override {

      DepartMent* d = *this->it;
      ++ this->it;
      
      return d;
    }

    void remove() override {

    }
  private:
    list<DepartMent*> *departments;
    std::_List_iterator<DepartMent* > it;
};


class AggregateCollege {
  public:
  virtual Iterator*createIterator() = 0;
};


class InfoCollege:public AggregateCollege {
  public:
    InfoCollege() {
      l.clear();
      for(int i =0;i<10;++i){

        DepartMent*d = new DepartMent("whx",i* 100);
        l.push_back(d);
      }
    }
  public:
    Iterator * createIterator() override {
      return new InfoCollegeIterator(&l);
    }

  private:
    list<DepartMent*> l;

};


void worker(Iterator *it) {
  while(it->hasNext()){
    auto d = it->next();
    d->print();
  }
};

int main(){
    InfoCollege* info = new InfoCollege();
  worker(info->createIterator());
  return 0;
}
