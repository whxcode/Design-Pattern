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
  virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
  void draw() override { cout << "绘制正方形" << endl; }
};

class Circle : public Shape {
public:
  void draw() override { cout << "绘制圆形" << endl; }
};

class Triangle : public Shape {
public:
  void draw() override { cout << "绘制三角形" << endl; }
};

class Star : public Shape {
public:
  void draw() override { cout << "绘制星星" << endl; }
};

class GraphicEditor {
public:
  void drawShape(Shape *s) { s->draw(); }
};

int main() {
  GraphicEditor *editor = new GraphicEditor;
  Rectangle *r = new Rectangle;
  Circle *c = new Circle;
  Triangle *t = new Triangle;
  Star *s = new Star;

  editor->drawShape(r);
  editor->drawShape(c);
  editor->drawShape(t);
  editor->drawShape(s);

  return 0;
}
