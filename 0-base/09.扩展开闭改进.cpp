/*************************************************************************
> File Name: 0-base/09.扩展开闭原则.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 10时00分14秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct Shape {
public:
  virtual void draw() = 0;

public:
public:
  int type;
};

struct Rectangle : public Shape {
public:
  void draw() override { cout << "Rectangle" << endl; }
};

struct Circle : public Shape {
public:
  void draw() override { cout << "Circle" << endl; }
};

struct Triangle : public Shape {
public:
  void draw() override { cout << "Triangle" << endl; }
};

struct Line : public Shape {
public:
  void draw() override { cout << "Line" << endl; }
};

struct Editor {
public:
  void draw(Shape *shape) { shape->draw(); }
};

void test01() {
  Shape *circle = new Circle;
  Shape *rect = new Rectangle;
  Shape *triangle = new Triangle;
  Shape *line = new Line;
  Editor *editor = new Editor;

  editor->draw(circle);
  editor->draw(rect);
  editor->draw(triangle);
  editor->draw(line);

  free(circle);
  free(rect);
  free(triangle);
  free(editor);
  free(line);
}

int main() {
  test01();
  return 0;
}
