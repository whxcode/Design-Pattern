/*************************************************************************
> File Name: ../01-创建型模式/02-建造者模式/02.text.converter.cpp
> Author:
> Mail:
> Created Time: 2022年08月10日 星期三 22时22分06秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Font {};
class Text {

};

class ASCII {

};
class Tex{

};


class AbstractConverter {
  public:
  virtual char converterChar() = 0;
  virtual Font *converterFont() = 0;
  virtual void converterParagraph() = 0;
};

class ASCIIConverter : public AbstractConverter {
public:
  char converterChar() override { return 'c'; }

  Font *converterFont() override { return new Font; }

  void converterParagraph() override {}
private:
  ASCII* ascii;
};

class TeXConverter : public AbstractConverter {
public:
  char converterChar() override { return 'x'; }
  Font *converterFont() override { return new Font; }

  void converterParagraph() override {}

private:
  Tex* tex;
};

class TextConverter : public AbstractConverter {
public:
  char converterChar() override { return 'l'; }
  Font *converterFont() override { return new Font; }
  void converterParagraph() override {}
private:
  Text* text;
};


class Reader {
  public:
    void worker(AbstractConverter* convert){
      convert->converterChar();
      convert->converterFont();
      convert->converterParagraph();
    };
};


int main() { return 0; }
