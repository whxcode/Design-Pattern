#include <iostream>
using namespace std;
class VisualWindow {
public:
  virtual void draw() = 0;
};

class TextView : public VisualWindow {
public:
  void draw() override { cout << "TextView" << endl; }
};

class Picture : public VisualWindow {
public:
  void draw() override { cout << "Picture" << endl; }
};

class Decorator : public VisualWindow {
public:
  ~Decorator() { delete component; }

public:
  void draw() override { component->draw(); }

protected:
  VisualWindow *component;
};

class BorderDecorator : public Decorator {
public:
  BorderDecorator(VisualWindow *component) { this->component = component; }

public:
  void draw() override {
    Decorator::draw();
    cout << "BorderDecorator" << endl;
  }
};

class ScrollbarDecorator : public Decorator {
public:
  ScrollbarDecorator(VisualWindow *component) { this->component = component; }

public:
  void draw() override {
    Decorator::draw();
    cout << "ScrollbarDecorator" << endl;
  }
};

void worker(VisualWindow *component) {
  component->draw();

  delete component;

  cout << endl;
}

int main() {
  worker(new TextView());
  worker(new BorderDecorator(new TextView()));
  worker(new ScrollbarDecorator(new BorderDecorator(new TextView())));

  cout << endl;
  cout << endl;
  cout << endl;

  worker(new Picture());
  worker(new BorderDecorator(new Picture()));
  worker(new ScrollbarDecorator(new BorderDecorator(new Picture())));

  return 0;
}
