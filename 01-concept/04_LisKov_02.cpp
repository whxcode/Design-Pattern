/*************************************************************************
> File Name: 01-concept/04_LisKov_01.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 13:01:14 2023
 ************************************************************************/

#include<iostream>
using namespace std;
class Base {};

class A: public Base {
  public:
    int subtract(int a,int b)  {

      return a - b;
    }

};

class B :public Base{
  public:
    B(A &a): a(a) {
    }
  public:
    // 不小心重写了
    int add(int a,int b) {

      return (a + b) ; }
    int subtract(int c,int b) {
      return a.subtract(c,b);
    }
  
  private:
    A &a;
};

int main(){

  A a;
  B b(a);

  cout << a.subtract(10,5) << endl;
  cout << b.add(10,5) << endl;
  cout << b.subtract(10,5) << endl;

  return 0;
}
