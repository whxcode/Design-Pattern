/*************************************************************************
> File Name: 04.接口适配器.cpp
> Author:
> Mail:
> Created Time: 2022年08月11日 星期四 21时22分22秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Animation {
public:
  virtual void start() {}
  virtual void run() {}
  virtual void end() {}
};

class Rotate : public Animation {
  void start() override { cout << "rotate start" << endl; }
  void end() override { cout << "rotate end" << endl; }
};

class Transform : public Animation {
public:
  void run() override { cout << "transform run" << endl; }
};

void worker(Animation *a) {
  a->start();
  a->run();
  a->end();
}

int main() {
  Rotate *r = new Rotate;
  Transform *t = new Transform;

  worker(r);
  worker(t);

  delete r;
  delete t;
  return 0;
}
