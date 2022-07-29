/*************************************************************************
> File Name: 02-创建型模式/01-单列模式/01.俄汉式模式.cpp
> Author: root
> Mail:
> Created Time: 2022年07月29日 星期五 21时05分25秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Singleton {
public:
  static Singleton *getInstance() { return Singleton::instance; }

private:
  Singleton() {}

private:
  static Singleton *instance;
};

Singleton *Singleton::instance = new Singleton;

int main() {
  Singleton *s1 = Singleton::getInstance();
  Singleton *s2 = Singleton::getInstance();

  printf("s1 == s2 %d\n",s1 == s2);
  printf("s1 %p\n",s1);
  printf("s2 %p\n",s2);

  return 0;
}
