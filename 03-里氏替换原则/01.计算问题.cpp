/*************************************************************************
> File Name: 03-里氏替换原则/01.计算问题.cpp
> Author: root
> Mail:
> Created Time: 2022年07月26日 星期二 21时51分46秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Calculate {
public:
  int fun1(int num1, int num2) { return num1 + num2; }
};

class A : public Calculate {

public:
  // 不小心重写了父类的方法
  int fun1(int a, int b) { return a - b; }
  int fun2(int a, int b) { return this->fun1(a, b) + 1; }
};

int main() {

  A *a = new A;

  int res  = a->fun2(1, 2);
  cout <<  res << endl;;

  return 0;
}
