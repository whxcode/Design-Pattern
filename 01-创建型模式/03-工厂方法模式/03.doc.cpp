/*************************************************************************
> File Name: 03.doc.cpp
> Author:
> Mail:
> Created Time: 2022年08月19日 星期五 22时49分30秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Document {
public:
  virtual void open() = 0;
};
class Application {
public:
  virtual Document *createDocument() = 0;
};

class MyDocument : public Document {
public:
  void open() override { cout << "open MyDocument" << endl; }
};

class YourDocument : public Document {
public:
  void open() override { cout << "open YourDocument" << endl; }
};

class MyApplication : public Application {
public:
  Document *createDocument() override { return new MyDocument; }
};

class YourApplication : public Application {
public:
  Document *createDocument() override { return new YourDocument; }
};

class Creator {
  public:
    Document* create(char type) {
      if(type == 'm') {
        return new MyDocument;
      }

      if(type == 'y') {
        return new YourDocument;
      }

      return NULL;
    }

};

void worker(Application *a) {
  Document *d = a->createDocument();

  d->open();
  cout << endl;

  delete d;
  delete a;
}

int main() {
  worker(new MyApplication);
  worker(new YourApplication);

  (new Creator)->create('m')->open();
  (new Creator)->create('y')->open();

  return 0;
}
