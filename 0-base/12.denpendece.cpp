/*************************************************************************
> File Name: 0-base/12.denpendece.cpp
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 11时19分48秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
using namespace std;

struct Person {};
struct IDCard {};

struct PersonServerBean {
public:
  void save(Person *p) {}
  Person *getPerson(){};
  void doThing() { IDCard card; };

private:
  Person p;
};

int main() { return 0; }
