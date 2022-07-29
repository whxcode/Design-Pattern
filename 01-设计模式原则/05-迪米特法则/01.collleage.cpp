/*************************************************************************
> File Name: 05-迪米特法则/01.collleage.cpp
> Author: root
> Mail:
> Created Time: 2022年07月29日 星期五 18时57分09秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class Student {};

class ManageStudent {
public:
  list<Student *> students;
};

class College {
public:
  // 该方法没有准守迪米特法则。
  void printAllStudents() {
    // ManageStudent 目前是 College 的陌生朋友。
    ManageStudent *m = new ManageStudent;

    // do something

  }

  // 该方法准守迪米特法则。
  void printAllStudentsImprove(ManageStudent *m) {
    // ManageStudent 是 College 的直接朋友。
    // do something
  }
  
  // 该方法准守迪米特法则。
  ManageStudent* getManager() {
    ManageStudent *m = new ManageStudent;

    return m;
  }
};

int main() { return 0; }
