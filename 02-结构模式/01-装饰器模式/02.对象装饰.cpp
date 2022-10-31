/*************************************************************************
> File Name: 01.类装饰.cpp
> Author: 
> Mail: 
> Created Time: 2022年10月10日 星期一 11时44分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

class TextView {
  public:
    void getRect() {

    }

};

class Manipulator {
  public:
    virtual void mouseMove() = 0;

};

class LineManipulator:public Manipulator {
  public:
    void mouseMove() override {
    }
};

class Shape {
  public:
    virtual void boundBox() = 0;
    virtual Manipulator* createManipulator() =0;
};

class Line :public Shape {
  public:
    void boundBox() override {
      cout << "Line Bound" <<endl;
    }

    Manipulator* createManipulator() override { 
      return new LineManipulator();
    }
};


class Text :public Shape {
  public:
    Text(TextView* t)  {
      this->t = t;
    }
  public:
    void boundBox() override {
      this->t->getRect();
      cout << "Text Bound" <<endl;
    }

    Manipulator* createManipulator() override { 
      return NULL;
    }
  private:
    TextView* t ;
};


void worker(Shape* shape) {
  shape->boundBox();

}

int main(){
  worker(new Line);
  worker(new Text(new TextView));

  return 0;
}
