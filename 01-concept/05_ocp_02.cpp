/*************************************************************************
> File Name: 01-concept/05_ocp_01.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 13:22:16 2023
 ************************************************************************/

#include<iostream>
using namespace std;
class Shape {
  public:
    virtual void draw() = 0;
  public:
    int type;

};

class Rectangle :public Shape {
  public:
    Rectangle() {
      type = 0;
    }
  public:
    void draw() override {
      cout << "绘制矩形" << endl;
    }

};

class Triangle :public Shape {
  public:
    Triangle() {
      type = 3;
    }

  public:
    void draw() override {
      cout << "绘制圆形" << endl;
    }

};

class Circle :public Shape {
  public:
    Circle() {
      type = 1;
    }

  public:
    void draw() override {
      cout << "绘制三角形" << endl;
    }

};

class Editor {
  public:
    void draw( Shape * const s )  {
      s->draw();
      delete  s;
    }

};

int main(){
  Editor e;

  e.draw( new Rectangle);
  e.draw( new Circle);
  e.draw( new Triangle);

  return 0;
}
