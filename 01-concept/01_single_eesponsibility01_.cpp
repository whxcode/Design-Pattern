/*************************************************************************
> File Name: 01_single_eesponsibility.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 10:54:25 2023
 ************************************************************************/

#include<iostream>
using namespace std;

// 交通工具类
// 1、在 run 方法中违反了单一职责原则；
class Vehicle {
  public :
    void run(string vehicle) {
      cout << "run in road: " << vehicle << endl;

  }
};

int main(){
  Vehicle v1;

  v1.run("汽车");
  v1.run("摩头车");
  
  return 0;
}
