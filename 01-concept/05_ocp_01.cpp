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
    int type;
};

class Rectangle :public Shape {
  public:
    Rectangle() {
      type = 0;
    }

};

class Triangle :public Shape {
  public:
    Triangle() {
      type = 3;
    }

};

class Circle :public Shape {
  public:
    Circle() {
      type = 1;
    }

};

class Editor {
  public:
    void draw(const Shape * const s )  {
      if(s->type == 0) {
        this->drawRectangle();
      } else if(s->type == 1) {
        this->drawCircle();
      } else if(s->type == 3) {
        this->drawTriangle();
      }

      delete  s;
    }

  private:
    void drawRectangle() {
      cout << "绘制矩形" << endl;
    }

    void drawCircle() {
      cout << "绘制圆形" << endl;
    }

    void drawTriangle() {
      cout << "绘制三角形" << endl;
    }

};

int main(){
  Editor e;

  e.draw( new Rectangle);
  e.draw( new Circle);
  e.draw( new Triangle);

  return 0;
}
