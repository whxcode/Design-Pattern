/*************************************************************************
> File Name: 01.simple.cpp
> Author: root
> Mail:
> Created Time: 2022年07月25日 星期一 21时41分18秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Singleton {
public:
  static Singleton *getInstance() { return Singleton::instace; }

private:
  static Singleton *instace;
};

Singleton *Singleton::instace = new Singleton;

int main() { 

  auto *s1 =  Singleton::getInstance();
  auto *s2 =  Singleton::getInstance();

  printf("%d\n",s1 == s2);

  return 0; }
