/*************************************************************************
> File Name: 10-obseriver/03.comple.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 18时22分55秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <string>

using namespace std;
class Secretary;

class PlaySerObserver {
public:
  PlaySerObserver() {}

public:
  void update(string acton) { cout << "action:" << acton << endl; }

private:
};

class Secretary {
public:
  void notify(string info) {
    auto start = os.begin();
    auto end = os.end();

    while (start != end) {
      (*start++)->update(info);
    }
  }
  void addO(PlaySerObserver *p) { os.push_back(p); }

private:
  list<PlaySerObserver *> os;
};

void test01() {
  Secretary *s = new Secretary;
  PlaySerObserver *p1 = new PlaySerObserver();
  PlaySerObserver *p2 = new PlaySerObserver();
  s->addO(p1);
  s->addO(p2);

  s->notify("whx");

}
int main() {
  test01();
  return 0;
}
