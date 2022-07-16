/*************************************************************************
> File Name: 08-Command/04.doctor.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 13时57分39秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Doctor {
  public:
    void treatEye() {
      cout<< "看眼睛" <<endl;
    }

    void treatNose() {
      cout<< "看鼻子" <<endl;
    }

};


class NurseEye {
  public:
    NurseEye(Doctor*d) {
      this->doctor =  d;
    }
  public:
    void treat() {
      this->doctor->treatEye();
    }
  private:
    Doctor *doctor;
};

class NurseNose {
  public:
    NurseNose(Doctor*d) {
      this->doctor =  d;
    }
  public:
    void treat() {
      this->doctor->treatNose();
    }
  private:
    Doctor *doctor;
};

int main() { 
  Doctor *a = new Doctor;
  NurseEye *eye = new NurseEye(a);
  NurseNose *nose = new NurseNose(a);

  eye->treat();
  nose->treat();

  // a->treatEye();
  // a->treatNose();
  return 0;
}
