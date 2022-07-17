/*************************************************************************
02-Signle-pattern/04.饿汉式.静态成员.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 12时43分44秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

struct Singleton {
public:
  static const Singleton *getInstace() { return Singleton::instance; }

private:
  Singleton() {}

private:
  static Singleton *instance;
};

Singleton *Singleton::instance = new Singleton;

int main() {
  const Singleton *s1 = Singleton::getInstace();
  const Singleton *s2 = Singleton::getInstace();

  printf("s1 == s2 %d\n", s1 == s2);
  printf("%p\n%p\n", s1, s2);

  return 0;
}
