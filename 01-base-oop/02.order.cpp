#include<iostream>

using namespace std;

class AbsctrctOrder {

  public:
    virtual double getTotal() = 0;
};


class Order : public AbsctrctOrder {
  public:
    double getTotal() override {
      return 20;
    }
};

int main(){
  return 0;
}
