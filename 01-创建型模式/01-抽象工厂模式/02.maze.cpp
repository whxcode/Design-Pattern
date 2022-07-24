/*************************************************************************
> File Name: 01-创建型模式/01-抽象工厂模式/02.maze.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 16时04分07秒

抽象工厂模式，当增加一种写的迷游戏，不不需要修改原先的类。
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;
class Wall {};
class Door {};
class Room {};

class Maze {
private:
  Wall *wall;
  Door *door;
  Room *room;
};

class EnchantedMaze : public Maze {};
class BombedMaze : public Maze {};

class EnchantedWall : public Wall {};
class EnchantedDoor : public Door {};
class EnchantedRoom : public Room {};

class BombedWall : public Wall {};
class BombedDoor : public Door {};
class BombedRoom : public Room {};

class MazeFactory {
public:
  virtual Maze *makeMaze() = 0;
  virtual Wall *makeWall() = 0;
  virtual Door *makeDoor() = 0;
  virtual Room *makeRoom() = 0;
};

class EnchantedFactory : public MazeFactory {
  Maze *makeMaze() override { return new EnchantedMaze; }
  Wall *makeWall() override { return new EnchantedWall; }
  Door *makeDoor() override { return new EnchantedDoor; }
  Room *makeRoom() override { return new EnchantedRoom; }
};

class BombedFactory : public MazeFactory {
  Maze *makeMaze() override { return new BombedMaze; }
  Wall *makeWall() override { return new BombedWall; }
  Door *makeDoor() override { return new BombedDoor; }
  Room *makeRoom() override { return new BombedRoom; }
};

int main() { return 0; }
