/*************************************************************************
> File Name: 03-结构模式/03-组合模式/02.graphic.cpp
> Author:
> Mail:
> Created Time: 2022年08月13日 星期六 09时54分33秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Graphic {
public:
  static void drawGraphic(Graphic **graphic, int size) {
    for (int i = 0; i < size; ++i) {
      (*(graphic + i))->draw();
    }
  }

public:
  virtual void draw() = 0;
  virtual void add(Graphic *graphic) {}
  virtual void remove(Graphic *graphic) {}
  virtual Graphic **getChild() { return NULL; }

protected:
  string name;
};

class Picture : public Graphic {
public:
  Picture(string name) {
    this->name = name;
    index = 0;
    graphic = (Graphic **)calloc(sizeof(Graphic), 10);
  }

  ~Picture() {
    for (int i = 0; i < this->index; ++i) {
      delete *(graphic + i);
    }

    delete graphic;
  }

public:
  void draw() override {
    cout << "Picture:" << name << endl;
    Graphic::drawGraphic(graphic, index);
    cout << "--" << endl;
  }
  void add(Graphic *graphic) override {
    *(this->graphic + this->index++) = graphic;
  }

  int getIndex() { return index; }
  Graphic **getChild() override { return graphic; }

private:
  int index;
  Graphic **graphic;
};

class Line : public Graphic {
public:
  Line(string name) { this->name = name; }

public:
  void draw() override { cout << "Line:" << name << endl; }
};

class Text : public Graphic {
public:
  Text(string name) { this->name = name; }

public:
  void draw() override { cout << "Text:" << name << endl; }
};

void test01() {
  Picture* pic = new Picture("p1");
  pic->add(new Line("l1"));
  pic->add(new Line("l2"));

  pic->add(new Text("l1"));
  pic->add(new Text("l2"));

  pic->draw();

  delete pic;
}


void test02() {
  Picture* pic = new Picture("p1");
  Picture* pic1 = new Picture("pic1");

  pic->add(new Line("l1"));
  pic->add(new Line("l2"));

  pic->add(new Text("l1"));
  pic->add(new Text("l2"));


  pic1->add(pic);


  pic1->draw();

  cout << endl;
  cout << endl;
  cout << endl;

  Graphic::drawGraphic(pic1->getChild(),pic1->getIndex());

  delete pic1;
}


int main() {

   test02();
  // test01();
  return 0;
}
