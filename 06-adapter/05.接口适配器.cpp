/*************************************************************************
> Author: root
> Mail:
> Created Time: 2022年07月18日 星期一 21时55分55秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

struct Animation {
public:
  virtual void start(){};
  virtual void run(){};
  virtual void end(){};
};

struct AnimationAdapter : public Animation {
public:
  void start() override { cout << "AnimalAdapter start" << endl; }
};

void worker(Animation *animation) {
  animation->start();
  animation->run();
  animation->end();
}

int main() {
  AnimationAdapter *a = new AnimationAdapter;
  worker(a);

  delete a;
  return 0;
}
