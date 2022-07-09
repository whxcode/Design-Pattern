/*************************************************************************
> File Name: 01-MazaGame.cpp
> Author:
> Mail:
> Created Time: 2022年07月03日 星期日 10时56分04秒
 ************************************************************************/

#include <iostream>
using namespace std;
enum Direction { East, North, West, South };

class MapSite {
public:
  virtual void Enter() = 0;
};

class Room : public MapSite {
public:
  Room(int roomNo);

  MapSite *getSide(Direction direction) const;
  void setSide(Direction direction, MapSite *mapSide);
  virtual void Enter();

private:
  MapSite *sides[4];
  int roomNumber;
};
class Wall : public MapSite {
public:
  Wall();
  virtual void Enter();
};

class Door : public MapSite {

public:
  Door(Room * = 0, Room * = 0);
  virtual void Enter();
  Room *otherSideFrom(Room *room);

private:
  Room *room1;
  Room *room2;
  bool isOpen;
};

class Maze {
public:
  Maze();
  void addRoom(Room *room);
  Room *getRoomByNo(int roomNo) const;
};

class MazeGame {
  Maze *CreateGaze();
};

Maze *MazeGame::CreateGaze() {
  Maze *maze = new Maze();
  Room *r1 = new Room(1);
  Room *r2 = new Room(2);
  Door *theDoor = new Door(r1, r2);

  maze->addRoom(r1);
  maze->addRoom(r2);

  r1->setSide(North, new Wall);
  r1->setSide(East, theDoor);
  r1->setSide(South, new Wall);
  r1->setSide(West, theDoor);

  r2->setSide(North, new Wall);
  r2->setSide(East, theDoor);
  r2->setSide(South, new Wall);
  r2->setSide(West, theDoor);

  return maze;
}

int main() { return 0; }
