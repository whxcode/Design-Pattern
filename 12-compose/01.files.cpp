/*************************************************************************
> File Name: 12-compose/01.files.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 09时34分27秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <string.h>

using namespace std;
class IFile {
public:
  virtual void display() const = 0;
  virtual int add(IFile *file) = 0;
  virtual int remove(IFile *file) = 0;
  virtual int ls(int indent = 0) = 0;
  virtual const list<IFile *> *getChid() = 0;
};

class File : public IFile {
public:
  File(string name) : name(name) {}

public:
  void display() const override {
    cout << "file:";
    cout << name << endl;
  }
  int add(IFile *file) override { return 1; }
  int remove(IFile *file) override { return 1; }

  int ls(int indent = 0) override {

    for (int i = 0; i < indent; ++i) {
      cout << "----";
    }
    display();
    return 1;
  }
  const list<IFile *> *getChid() override { return NULL; };

private:
  string name;
};

class Dir : public IFile {
public:
  Dir(string name) : name(name) {}

public:
  void display() const override {
    cout << "dir:";
    cout << name << endl;
  }

  int add(IFile *file) override {
    files.push_back(file);
    return 0;
  }

  int remove(IFile *file) override {
    files.remove(file);
    return 0;
  }

  const list<IFile *> *getChid() override { return &files; };

public:
  int ls(int indent = 0) override {

    list<IFile *>::iterator start = files.begin();
    list<IFile *>::iterator end = files.end();

    for (int i = 0; i < indent; ++i) {
      cout << "----";
    }

    this->display();
    while (start != end) {
      int res = (*start++)->ls(indent + 1);
    }

    return 0;
  }

private:
  list<IFile *> files;
  string name;
};

int main() {
  Dir *root = new Dir("/");
  Dir *home = new Dir("home");
  Dir *tmp = new Dir("tmp");
  Dir *whxDesktop = new Dir("desktop");
  Dir *whx = new Dir("whx");
  File *language = new File("language c");

  root->display();
  root->add(home);
  root->add(tmp);
  whx->add(whxDesktop);
  whxDesktop->add(language);

  home->display();
  home->add(whx);
  cout << endl;

  root->ls();
  // home->ls();

  return 0;
}
