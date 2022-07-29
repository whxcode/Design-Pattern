/*************************************************************************
> File Name: 04-开闭原则/01.shape.cpp
> Author: root
> Mail:
> Created Time: 2022年07月29日 星期五 14时47分21秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Shape {
public:
  int type;
};

class Rectangle : public Shape {
public:
  Rectangle() { type = 1; }
};

class Circle : public Shape {
public:
  Circle() { type = 2; }
};

class Triangle : public Shape {
public:
  Triangle() { this->type = 3; }
};

class GraphicEditor {
public:
  void drawShape(Shape *s) {
    if (s->type == 1) {
      cout << "矩形" << endl;
    } else if (s->type == 2) {
      cout << "圆形" << endl;
    } else if (s->type == 3) {
      cout << "三角形" << endl;
    }
  }
};

int main() {
  GraphicEditor *editor = new GraphicEditor;
  Rectangle *r = new Rectangle;
  Circle *c = new Circle;
  Triangle *t = new Triangle;

  editor->drawShape(r);
  editor->drawShape(c);

  //  增加一个对象，适用方也要修改。
  editor->drawShape(t);

  return 0;
}
