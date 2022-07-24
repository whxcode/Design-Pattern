/*************************************************************************
> File Name: 01-创建型模式/02-建造者模式/01.doc.transfer.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 18时07分19秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class TextDoc {
public:
  virtual void display() = 0;

public:
  int c;
};

class TextConverter {
public:
  virtual char convertCharacter(char c) { return c; }
  virtual void convertFontChange(char font) {}
  virtual void convertGrammar() {}
  virtual TextDoc *getProduct() final { return doc; }

protected:
  TextDoc *doc;
};

class ASCIIDoc : public TextDoc {
public:
  void display() override { printf("%d\n", c); }
};

class ASCIIConverter : public TextConverter {
public:
  ASCIIConverter() { doc = new ASCIIDoc; }

public:
  char convertCharacter(char c) override {
    doc->c = 97;
    return c;
  }
};

class TexDoc : public TextDoc {
public:
  void display() override { printf("%c\n", c); }
};

class TexConverter : public TextConverter {
public:
  TexConverter() { doc = new TexDoc; }

public:
  char convertCharacter(char c) override {
    doc->c = 97;
    return c;
  }
};

class TextEditDoc : public TextDoc {
public:
  void display() override { printf("%c\n", c); }
};

class TexEditConverter : public TextConverter {
public:
  TexEditConverter() { doc = new TextEditDoc; }

public:
  char convertCharacter(char x) override {
    doc->c = 111;
    return x;
  }
};

class RTFReader {
public:
  void setConvert(TextConverter *convert) { this->convert = convert; }
  TextDoc *construct() {
    convert->convertCharacter('a');
    convert->convertFontChange('a');
    convert->convertGrammar();

    return convert->getProduct();
  }

private:
  TextConverter *convert;
};

int main() {
  RTFReader *r = new RTFReader;
  TextConverter *a = new ASCIIConverter();

  r->setConvert(a);
  r->construct()->display();

  r->setConvert(new TexConverter);
  r->construct()->display();


  r->setConvert(new TexEditConverter);
  r->construct()->display();
  return 0;
}
