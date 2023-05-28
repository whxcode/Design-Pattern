/*************************************************************************
> File Name: 01_single_eesponsibility.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 10:54:25 2023
 ************************************************************************/

#include<iostream>
using namespace std;

/**
 * 在一定的程度上遵守了单一职责；
 * 而且没有完全遵守开辟封闭原则
 *
 * **/

class Vehicle {
  public :
    void runRoad(string vehicle) {
      cout << "run in road: " << vehicle << endl;
  }

    void runFly(string vehicle) {
      cout << "run in fly: " << vehicle << endl;
  }

    void runWater(string vehicle) {
      cout << "run in water: " << vehicle << endl;
  }
};


int main(){
  Vehicle v1;

  v1.runRoad("汽车");
  v1.runRoad("摩头车");
  v1.runFly("jet");
  v1.runWater("ship");
  
  return 0;
}
