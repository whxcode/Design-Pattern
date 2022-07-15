/*************************************************************************
> File Name: ./desgin-pattern/03-proxy/03.bookshop.cpp
> Author: root
> Mail:
> Created Time: 2022年07月15日 星期五 22时05分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Subject {
public:
  virtual void sailBook() = 0;
};

class RealSubjectBook : public Subject {
  void sailBook() override { cout << "买书买书" << endl; }
};

class RealWood : public Subject {
  void sailBook() override { cout << "买木头买木头" << endl; }
};

class DangDangProxy : public Subject {
public:
  DangDangProxy(Subject *s) : subject(s) {}

public:
  void sailBook() override {
    cout << "当当网买书" << endl;
    this->subject->sailBook();
  }

private:
  Subject *subject;
};

int main() {
  Subject *book = new RealSubjectBook;
  Subject *proxyBook = new DangDangProxy(book);

  Subject *wood = new RealSubjectBook;
  Subject *proxyWood = new DangDangProxy(wood);

  proxyBook->sailBook();
  cout << endl;
  cout << endl;
  proxyWood->sailBook();

  return 0;
}
