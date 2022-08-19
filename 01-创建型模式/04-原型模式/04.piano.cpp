/*************************************************************************
> File Name: 04.piano.cpp
> Author:
> Mail:
> Created Time: 2022年08月19日 星期五 22时39分06秒
 ************************************************************************/

#include <iostream>
#include <list>

using namespace std;
class Graphic {
public:
  virtual Graphic *clone() = 0;
  virtual void draw(int x, int y) = 0;
};

class MusicNote : public Graphic {
public:
};

class WholeNote : public MusicNote {
public:
  WholeNote(string name) { this->name = name; }

public:
  Graphic *clone() override {
    WholeNote *h = new WholeNote(this->name);
    *h = *this;

    return h;
  }

  void draw(int x, int y) override {
    cout << "draw WholeNote:" << name << "  "
         << "x:" << x << "y:" << y << endl;
  }

protected:
  string name;
};

class HalfNote : public MusicNote {
public:
  HalfNote(string name) { this->name = name; }

public:
  Graphic *clone() override {
    HalfNote *h = new HalfNote(this->name);
    *h = *this;

    return h;
  }

  void draw(int x, int y) override {
    cout << "draw HalfNote:" << name << "  "
         << "x:" << x << "y:" << y << endl;
  }

protected:
  string name;
};

class Tool {
public:
  virtual void manipulate(list<Graphic *> graphs) = 0;
};

class GraphTool : public Tool {
public:
  void manipulate(list<Graphic *> graphs) override {
    int i = 0;

    for (auto it : graphs) {
      Graphic *p = it->clone();
      p->draw(i, i + 1);
      i++;

      delete p;
    }
  }
};

void worker(Tool *t) {

  list<Graphic *> g;
  g.clear();

  g.push_back(new HalfNote("w"));
  g.push_back(new WholeNote("m"));
  g.push_back(new HalfNote("s"));

  t->manipulate(g);

  delete t;

  for (auto it : g) {
    delete it;
  }
}

int main() {
  worker(new GraphTool);

  return 0;
}
