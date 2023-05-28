/*************************************************************************
> File Name: 01-concept/04_LisKov_01.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 13:01:14 2023
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
  public:
    int subtract(int a,int b)  {

      return a - b;
    }

};

class B :public A{
  public:
    // 不小心重写了
    int subtract(int a,int b) {

      return (a + b) ; }

};

int main(){

  A a;
  B b;

  cout << a.subtract(10,5) << endl;
  cout << b.subtract(10,5) << endl;

  return 0;
}
