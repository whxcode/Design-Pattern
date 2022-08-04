#include <iostream>
#include <string>

using namespace std;

class Sheep {
public:
  Sheep(string name, int age) {
    this->name = name;
    this->age = age;
  }

public:
  string name;
  int age;
};

void test01() {
  Sheep *sheep = new Sheep("whx", 12);

  for (int i = 0; i < 10; ++i) {
    Sheep *s = new Sheep(sheep->name, sheep->age);
    cout << "name:" << sheep->name << "age:" << sheep->age << endl;
  }
}

int main() {
  test01();
  return 0;
}
