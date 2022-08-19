/************* {}**********************************************************
> File Name: 03.conveter.cpp
> Author:
> Mail:
> Created Time: 2022年08月18日 星期四 22时49分11秒
 ************************************************************************/

#include <iostream>
using namespace std;

class ASCII {
public:
  int c;
};

class Tex {};

class Doc {};

class ConveterText {
public:
  virtual void conveterChar(char c) = 0;
  virtual void conveterFont(char font) {}
  virtual void conveterParagraph(char *sentence) {}
};

class ASCIIConveter : public ConveterText {
public:
  ASCIIConveter() { a = new ASCII; }

public:
  void conveterChar(char c) override { a->c = c + 0; }
  ASCII *getASCII() { return a; }

private:
  ASCII *a;
};

class TexConveter : public ConveterText {
public:
  TexConveter() { t = new Tex; }

public:
  void conveterChar(char c) override {}
  void conveterParagraph(char *c) override {}
  Tex *getTex() { return t; }

private:
  Tex *t;
};

class DocConveter : public ConveterText {
public:
  DocConveter() { t = new Doc; }

public:
  void conveterChar(char c) override {}
  void conveterFont(char font) override {}
  void conveterParagraph(char *c) override {}
  Doc *getDoc() { return t; }

private:
  Doc *t;
};

class Director {
public:
  void parse(ConveterText *t, char *c) {}
};

int main() {

  Director *d = new Director;

  d->parse(new ASCIIConveter, (char *)"abc");
  return 0;
}
