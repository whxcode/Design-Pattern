/*************************************************************************
  > File Name: 03.grahpic.cpp
  > Author: 
  > Mail: 
  > Created Time: 2022年08月27日 星期六 21时59分35秒
 ************************************************************************/

#include<iostream>
#include<list>

using namespace std;


class Graphic {
  public:
    static void print(list<Graphic*>*g) {
      for(auto it:*g) {
        cout << it->name <<"\t";
      }
      cout << endl;
    }
  public:
    virtual void draw() = 0;
    virtual void add(Graphic* g) {}
    virtual void remove(Graphic*g){}
    virtual list<Graphic*>*getChild(){return NULL;}
  protected:
    string name;
};

class Picture :public Graphic {
  public:
    Picture(string name) {
      this->name = name;
      l.clear();
    }
  public:
    void draw() override {
      for(auto it :l) {
        it->draw();
      }
    }
    void add(Graphic *g) override {
      l.push_back(g);
    }
    void remove(Graphic *g) override{
      l.remove(g);
    }

    list<Graphic *> * getChild() override {
      return &l;
    }

  private:
    list<Graphic*>l;
};

class  Line :public Graphic {
  public:
    Line(string name) {
      this->name = name;
    }
  public:
    void draw() override {
      cout << "draw Line:" << name <<endl;
    }
};

class  Text :public Graphic {
  public:
    Text(string name) {
      this->name = name;
    }
  public:
    void draw() override {
      cout << "draw Text:" << name <<endl;
    }
};

int main(){
  Picture*p = new Picture("p1 piture");

  p->add(new Line("l1 line"));
  p->add(new Line("l2 line"));

  p->add(new Text("t1 text"));

  p->draw();

  cout <<endl;

  Graphic::print(p->getChild());
    
  return 0;
}
