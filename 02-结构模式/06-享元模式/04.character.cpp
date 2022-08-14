/*************************************************************************
> File Name: 04.character.cpp
> Author:
> Mail:
> Created Time: 2022年08月14日 星期日 11时30分18秒
 ************************************************************************/

#include <cstring>
#include <iostream>
#include <map>
#include <strings.h>

using namespace std;

class Glyph {
public:
  virtual void draw() = 0;
  virtual void insertChar(char c, int x) = 0;
};

class Character : public Glyph {
public:
  Character(char c) { this->c = c; }

public:
  void draw() override {}
  void insertChar(char c, int x) override {
    cout << "point x:" << x << "put char of:" << c << endl;
  }

public:
  char c;
};

class GlyphFactory {
public:
  Glyph *getChar(char c) {
    auto it = chars.find(c);

    if (it != chars.end()) {
      return it->second;
    }

    Character *t = new Character(c);
    chars.insert(make_pair(c, t));
    return t;
  }

  void display() {
    cout << "current teacher amount:" << chars.size() << endl;
    cout << "----" << endl;

    for (auto it : chars) {
      cout << it.first << "  :  " << it.second->c << endl;
    }

    cout << "----" << endl;
  }

private:
  map<char, Character *> chars;
};

void test01() {
  const char *const letter = "qwertyuiopasdfghjklzxcvbnqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmm";
  GlyphFactory *factory = new GlyphFactory;

  for (int i = 0; i < strlen(letter) + 1; ++i) {
    char h = *(letter + i);
    Glyph *c = factory->getChar(h);

    c->insertChar(h, i);
  }

  factory->display();
}

int main() {

  test01();
  return 0;
}
