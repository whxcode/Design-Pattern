/*************************************************************************
> File Name: 01-doctor.cpp
> Author:
> Mail:
> Created Time: 2022年07月09日 星期六 09时51分45秒
 ************************************************************************/

#include <iostream>
using namespace std;
class Docotr {
public:
  void treatEyes() { cout << "医生治疗眼睛" << endl; }

  void treatNose() { cout << "医生治疗鼻子" << endl; }
};

class CommandEyes {
public:
  ~CommandEyes() { delete doctor; }
  CommandEyes(Docotr *doctor) : doctor(doctor) {}
  void treat() { doctor->treatEyes(); }

private:
  Docotr *doctor;
};

class CommandNose {
public:
  ~CommandNose() { delete doctor; }
  CommandNose(Docotr *doctor) : doctor(doctor) {}
  void treat() { doctor->treatNose(); }

private:
  Docotr *doctor;
};

int main() {

  CommandEyes *cmdEyes = new CommandEyes(new Docotr);
  CommandNose *cmdNose = new CommandNose(new Docotr);

  cmdEyes->treat();
  cmdNose->treat();

  return 0;
}
