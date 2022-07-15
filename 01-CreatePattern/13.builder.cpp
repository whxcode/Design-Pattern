/*************************************************************************
> File Name: /root/study/c/desgin-pattern/01-CreatePattern/13.builder.cpp
> Author: root
> Mail:
> Created Time: 2022年07月14日 星期四 21时56分59秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;
class House {
public:
  void setWall(string wall) { this->wall = wall; }
  void setDoor(string door) { this->door = door; }
  void setFloor(string floor) { this->floor = floor; }
  void prinf() const {
    cout << wall << endl;
    cout << floor << endl;
    cout << door << endl;
  }

private:
  string wall;
  string floor;
  string door;
};

class Builder {
public:
  virtual void makeFloor() const = 0;
  virtual void makeWall() const = 0;
  virtual void makeDoor() const = 0;
  virtual const House *getHouse() const = 0;
};

class ApartMent : public Builder {
public:
  ApartMent() { house = new House; }

public:
  void makeDoor() const override { house->setDoor("ApartMent Door"); }
  void makeWall() const override { house->setWall("ApartMent Wall"); }
  void makeFloor() const override { house->setFloor("ApartMent Floor"); }

  const House *getHouse() const override { return house; }

private:
  House *house;
};

class Villa : public Builder {
public:
  Villa() { house = new House; }

public:
  void makeDoor() const override { house->setDoor("Villa Door"); }
  void makeWall() const override { house->setWall("Villa Wall"); }
  void makeFloor() const override { house->setFloor("Villa Floor"); }

  const House *getHouse() const override { return house; }

private:
  House *house;
};

class Director {
public:
  Director(Builder *builder) { this->builder = builder; }

public:
  void setBuilder(Builder *builder) { this->builder = builder; }

public:
  void constrcut() {
    builder->makeDoor();
    builder->makeFloor();
    builder->makeWall();
  }

private:
  Builder *builder;
};

void testApartment() {
  Builder *apart = new ApartMent;
  Builder *villa = new Villa;
  Director *apartMent = new Director(apart);

  apartMent->constrcut();

  const House *apartHouse = apart->getHouse();
  apartHouse->prinf();

  delete apart;

  apartMent->setBuilder(villa);
  apartMent->constrcut();
  const House *villaHouse = villa->getHouse();
  cout << endl;

  villaHouse->prinf();
}

int main() {
  testApartment();

  return 0;
}
