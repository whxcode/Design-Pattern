/*************************************************************************
> File Name: ./01-创建型模式/05-单列模式/02.complex.cpp
> Author: root
> Mail:
> Created Time: 2022年07月25日 星期一 21时44分13秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Singleton {

protected:
  static void regist(char name, Singleton *s) {
    Singleton::m.insert(make_pair(name, s));
  }
  static Singleton *getInstance(char name) {
    auto it = Singleton::m.find(name);

    if (it != Singleton::m.end()) {
      return it->second;
    }

    return NULL;
  };

private:
  static map<char, Singleton *> m;
};

map<char, Singleton *> Singleton::m;

class ImageManage : public Singleton {
public:
  static Singleton *getInstance() {
    auto *it = Singleton::getInstance('i');
    if (it == 0) {
      auto *self = new ImageManage;
      Singleton::regist('i', self);

      return self;
    }

    return it;
  }

private:
  ImageManage() {}
};

int main() {

  Singleton *image1 = ImageManage::getInstance();
  Singleton *image2 = ImageManage::getInstance();

  printf("%d\n", image1 == image2);

  return 0;
}
