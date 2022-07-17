/*************************************************************************
> File Name: 0-base/07.李氏替换原则.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 09时32分25秒
 ************************************************************************/

#include <functional>
#include <iostream>

using namespace std;

/*
struct A {
public:
  int plus(int a, int b) { return a + b; }
};

struct B : public A {
public:
  // 不小心重写了
  int plus(int a, int b) { return a + b - 2; }
};
*/

struct Base {};

struct A : public Base {
public:
  int plus(int a, int b) { return a + b; }
};

struct B : public Base {
public:
  int plus(int a, int b) { return a + b - 2; }

  // int useAplus(A *a, int b, int c) { return a->plus(b, c) + 2; }

  std::function<int(int a, int b)> useAplus(A *a) {
    return [&](int b, int c) -> int { return a->plus(c, b) + 2; };
  }
};

void test01() {
  int a = 10;

  [&a]() mutable -> void {
    a = 100;
    cout << "inner a" << a << endl;
  }();

  cout << "out a" << a << endl;
}

int main() {
  /*
  A *a = new A;
  B *b = new B;

  cout << a->plus(3, 2) << endl;
  cout << b->plus(3, 2) << endl;

  cout << b->useAplus(a)(10, 20) << endl;

  delete a;
  delete b;
  */
  test01();

  return 0;
}
