#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class TextView {
public:
  string getString() { return text; }
  void setString(string text) { this->text = text; }

private:
  string text;
};

class Shape {
public:
  virtual void draw() = 0;
  virtual void edit() = 0;
};

class Line : public Shape {
public:
  void draw() override { cout << "draw line" << endl; }
};

class Text : public Shape {
public:
  void draw() override { cout << "draw text" << endl; }
};

int main() { return 0; }
