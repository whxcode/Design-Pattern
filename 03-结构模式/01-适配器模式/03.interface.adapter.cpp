#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Animation {
public:
  virtual void start() {}
  virtual void run() {}
  virtual void end() {}
};

class StartAnimation : public Animation {
public:
  void start() override { cout << "开始动画了" << endl; }
};

class OAnimation : public Animation {
public:
  void start() override { cout << "开始动画了" << endl; }
  void end() override { cout << "动画结束了" << endl; }
};

void worker(Animation *animation) {
  animation->start();
  animation->run();
  animation->end();
}

int main() {
  StartAnimation *sa = new StartAnimation;
  OAnimation *oa = new OAnimation;

  worker(sa);

  cout << endl;

  worker(oa);

  delete sa;
  delete oa;

  return 0;
}
