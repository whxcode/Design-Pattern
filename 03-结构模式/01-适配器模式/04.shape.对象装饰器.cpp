/*************************************************************************
> File Name: 03.shape.类装饰器.cpp
> Author: 
> Mail: 
> Created Time: 2022年08月12日 星期五 22时28分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

class TextView {
  public:
    int getTextSize() {
      return 10;
    }

    bool isEmpty() {
      return false;
    }
};

class Shape;
class Manipulator {
  public:
    Manipulator(Shape*shape) {
      this->shape = shape;
    }
  public:
    virtual void mouseDown() = 0;
  protected:
    Shape* shape;



};

class Shape {
  public:
    virtual int boundingBox() = 0;
    virtual  Manipulator *createManipulator() =0;
};

class LineManipulator:public Manipulator {
  public:
    LineManipulator(Shape*shape):Manipulator(shape) {}
  public:
    void mouseDown() override {
      cout << "line mouseDown" <<endl;
    }
};

class TextShapeManipulator:public Manipulator {
  public:
    TextShapeManipulator(Shape*shape):Manipulator(shape) {}
  public:
    void mouseDown() override {
      cout << "TextShapeManipulator mouseDown" <<endl;
    }
};

class LineShape :public Shape {
  public:
    int boundingBox() override {
      return 10;
    }

    Manipulator * createManipulator() override {
      return new LineManipulator(this);
    }
};

class TextShape :public Shape {
  public:
    TextShape(TextView* view) {
      this->view = view;
    }
  public:
    int boundingBox() override {
      return view->getTextSize() + 100;
    }

    bool isEmpty() {
      return view->isEmpty();
    }

    Manipulator * createManipulator() override {
      return new TextShapeManipulator(this);
    }
  private:
    TextView* view;
};

void worker(Shape*shape) {
  cout << shape->boundingBox() <<endl;
  Manipulator* m = shape->createManipulator();

  m->mouseDown();

  delete shape;
  delete m;
}

int main(){
  worker(new LineShape);
  worker(new TextShape(new TextView));

  return 0;
}
