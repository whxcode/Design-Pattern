/*************************************************************************
> File Name: 02-print.cpp
> Author:
> Mail:
> Created Time: 2022年07月04日 星期一 21时35分54秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;
class Printer {
public:
  static Printer *getPrinter() { return Printer::printer; }
  void print(string text) {
    cout << text << endl;
    ++Printer::sequence;
  }

private:
  Printer() {}
  static Printer *printer;
  static int sequence;
  class Garbo {
    private:
      ~G
  }
};

Printer *Printer::printer = new Printer;
int Printer::sequence = 0;

int console() {
  Printer *p1 = Printer::getPrinter();
  p1->print("简历.");

  Printer *p2 = Printer::getPrinter();
  p2->print("离职.");

  return 0;
}
