/*************************************************************************
> File Name: 02.image.cpp
> Author:
> Mail:
> Created Time: 2022年08月14日 星期日 15时53分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Graphic {
public:
  virtual void draw() = 0;
  virtual int getExtent() = 0;
  virtual void store() = 0;
  virtual void load() = 0;
};

class Image : public Graphic {
public:
  Image(string name) { filename = name; }

public:
  void draw() override { cout << "draw file:" << filename << endl; }
  int getExtent() override { return 2; }
  void store() override { cout << "store image" << endl; }

  void load() override { cout << "load image" << endl; }

public:
  string filename;
};

class ProxyImage : public Graphic {
public:
  ProxyImage(Image *image) { this->image = image; }
  ~ProxyImage() {
    delete image;
  }

public:
  void draw() override {
    image->load();
    image->draw();
  }

  int getExtent() override { return image->getExtent(); }
  void store() override { image->store(); }

  void load() override { image->load(); }

public:
  Image *image;
};

void test01(Graphic *g) {
  g->draw();
  g->store();

  delete g;
}

int main() {
  test01(new ProxyImage(new Image("1.png")));
  cout << endl;
  test01(new ProxyImage(new Image("2.png")));

  return 0;
}
