/*************************************************************************
  > File Name: 04.doc.cpp
  > Author: 
  > Mail: 
  > Created Time: 2022年08月27日 星期六 22时13分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Document {
  public:
    virtual void draw()  =0;
};

class TextView:public Document {
  public:
    void draw() override {
      cout << "TextView Draw" <<endl;
    }
};

class DocumentDecorator:public Document {
  public:
    virtual void draw() override {
      d->draw();
    }
  protected:
    Document* d;
};

class BorderDecorator:public DocumentDecorator {
  public:
    BorderDecorator(Document*d) {
      this->d = d;
    }
  public:
    void draw() override {
      DocumentDecorator::draw();
      cout << "BorderDecorator:"<<endl;
    }
};

class ScrollbarDecorator:public DocumentDecorator {
  public:
    ScrollbarDecorator(Document*d) {
      this->d = d;
    }
  public:
    void draw() override {
      DocumentDecorator::draw();
      cout << "ScrollbarDecorator:"<<endl;
    }
};

void worker(Document*d) {
  d->draw();
}
int main(){
  worker(new BorderDecorator(new TextView));
  cout << endl;
  cout << endl;
  worker( new ScrollbarDecorator(new TextView));
  cout << endl;
  cout << endl;
  worker(  new ScrollbarDecorator( new BorderDecorator( new TextView)));
  return 0;
}
