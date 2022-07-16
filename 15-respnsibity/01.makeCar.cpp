/*************************************************************************
> File Name: 15-respnsibity/01.makeCar.cpp
> Author: root
> Mail: 
> Created Time: 2022年07月16日 星期六 16时20分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct MakeCar {
  public:
    MakeCar() {
      makeCar = NULL;
    }
  public:
  virtual MakeCar*  handleCar() = 0;
  public:
  MakeCar* setNextHandle(MakeCar* handle) {
    this->makeCar = handle;

    return handle;
  }
  void work() {

    this->handleCar();
    MakeCar* handle = this->makeCar;

    while(handle) {
      handle = handle->handleCar();
    }

  };
  protected:
  MakeCar *makeCar;
};

struct MakeCarHead :public  MakeCar{
  public:
    MakeCar* handleCar() override {
      cout << "make car head" <<endl;

      return this->makeCar;
    }
};

struct MakeCarBody :public  MakeCar{
  public:
    MakeCar* handleCar() override {
      cout << "make car body" <<endl;
      return this->makeCar;
    }
};

struct MakeCarTail :public  MakeCar{
  public:
    MakeCar* handleCar() override {
      cout << "make car tail" <<endl;
      return this->makeCar;
    }
};

void test01() {
  MakeCar *head = new MakeCarHead;
  MakeCar *body = new MakeCarBody;
  MakeCar *tail = new MakeCarTail;

  head->handleCar();
  body->handleCar();
  tail->handleCar();

  delete (MakeCarHead *)head;
  delete (MakeCarBody *)body;
  delete (MakeCarTail*)tail;
}

void test02() {
  MakeCar *head = new MakeCarHead;
  MakeCar *body = new MakeCarBody;
  MakeCar *tail = new MakeCarTail;

  head->setNextHandle(tail)->setNextHandle(body);

  // head->handleCar();
  head->work();

  delete (MakeCarHead *)head;
  delete (MakeCarBody *)body;
  delete (MakeCarTail*)tail;
}

int main(){
  test02();

  return 0;
}
