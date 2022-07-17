/*************************************************************************
> File Name: 0-base/08.扩展开闭原则.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 10时00分14秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct Shape {
public:
  Shape(int type) { this->type = type; }

public:
  void drawRect() { cout << "画矩形" << endl; }
  void drawCircle() { cout << "画园形" << endl; }
  void drawTrangle() { cout << "画三角形" << endl; }

public:
  int type;
};

struct Rectangle : public Shape {
public:
  Rectangle() : Shape(1) {}
};

struct Circle : public Shape {
public:
  Circle() : Shape(0) {}
};

struct Triangle : public Shape {
public:
  Triangle() : Shape(2) {}
};

struct Editor {
public:
  void draw(Shape *shape) {
    if (shape->type == 0) {
      shape->drawRect();
    } else if (shape->type == 1) {
      shape->drawCircle();
    } else if (shape->type == 2) {
      shape->drawTrangle();
    }
  }
};

void test01() {
  Shape*circle = new Circle;
  Shape*rect = new Rectangle;
  Shape*triangle = new Triangle;
  Editor *editor = new Editor;

  editor->draw(circle);
  editor->draw(rect);
  editor->draw(triangle);

  free(circle);
  free(rect);
  free(triangle);
  free(editor);

}

int main() {
  test01();
  return 0;
}
