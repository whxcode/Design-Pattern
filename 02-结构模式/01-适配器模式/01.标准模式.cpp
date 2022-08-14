/*************************************************************************
> File Name: 01.标准模式.cpp
> Author: root
> Mail:
> Created Time: 2022年08月01日 星期一 21时40分07秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

class Point {
public:
  double x;
  double y;
};

class Manipulator {};

class TextView {
public:
  void getOrigin() {}
  void getExtent() {}
  virtual bool isEmpty() { return false; }
};

class Shape {
public:
  virtual void boundingBox(Point *bottomLeft, Point *topRight) = 0;
  virtual Manipulator *createManipulator() = 0;
};

class TextShape : public Shape, private TextView {
public:
  void boundingBox(Point *bottomLeft, Point *topRight) override;
  Manipulator *createManipulator() override;
  bool isEmpty() override;
};

void TextShape::boundingBox(Point *bottomLeft, Point *topRight) {}
bool TextShape::isEmpty() { return TextView::isEmpty(); }

class TextManipulator : public Manipulator {
public:
  TextManipulator(Shape *shape) {}
};

Manipulator *TextShape::createManipulator() {
  return new TextManipulator(this);
};

int main() { return 0; }
