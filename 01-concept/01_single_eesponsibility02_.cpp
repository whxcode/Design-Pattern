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

class RoadVehicle {
  public :
    void run(string vehicle) {
      cout << "run in road: " << vehicle << endl;
  }
};

class FlyVehicle {
  public :
    void run(string vehicle) {
      cout << "run in fly: " << vehicle << endl;
  }
};


class WaterVehicle {
  public :
    void run(string vehicle) {
      cout << "run in water: " << vehicle << endl;
  }
};

int main(){
  RoadVehicle v1;
  FlyVehicle v2;
  WaterVehicle v3;

  v1.run("汽车");
  v1.run("摩头车");

  v2.run("jet");

  v3.run("ship");
  
  return 0;
}
