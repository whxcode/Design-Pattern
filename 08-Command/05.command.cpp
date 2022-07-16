/*************************************************************************
> File Name: 05.command.cpp
> Author: root
> Mail: 
> Created Time: 2022年07月16日 星期六 15时53分19秒
 ************************************************************************/

#include<iostream>
#include <list>

using namespace std;
class Command {
  public:
    virtual void treat() = 0;
};

class Doctor {
  public:
    void treatEye() {
      cout<< "看眼睛" <<endl;
    }

    void treatNose() {
      cout<< "看鼻子" <<endl;
    }
};

class CommandEye:public Command {
  public:
  CommandEye(Doctor* doctor) {
    this->doctor = doctor;
  }

  public:
    void treat() override {
      doctor->treatEye();
    }
  private:
    Doctor* doctor;

};

class CommandNose:public Command {
  public:
  CommandNose(Doctor* doctor) {
    this->doctor = doctor;
  }

  public:
    void treat() override {
      doctor->treatNose();
    }
  private:
    Doctor* doctor;
};

class BeautyNurse {
  public:
    BeautyNurse(Command* command) {
      this->command = command;
    }
  public:
    void submit() {
      command->treat();
    }
  private:
    Command* command;

};

void test01() {
  Doctor* doctor = new Doctor;
  Command* eye = new CommandEye(doctor);
  Command* nose = new CommandEye(doctor);

  BeautyNurse* nurseEye = new BeautyNurse(eye);
  BeautyNurse* nurseNorse = new BeautyNurse(nose);

  nurseEye->submit();

  delete nurseEye;
  delete (CommandNose* )nose;
  delete (CommandEye*)eye;
  delete doctor;
}

class MainNurse {
  public:
    MainNurse() {
      commands.clear();
    }
  public:
    void addCommand( Command*  command) {
      commands.push_back(command);
    }
    void treat() {
      auto it =  commands.begin();
      auto end =  commands.end();

      while(it !=end) {
        (*it++)->treat();
      }

    }
  private:
    list< Command*> commands;

};

void commands() {
  Doctor *doctor = new Doctor;
  Command *eye = new CommandEye(doctor);
  Command *nose = new CommandNose(doctor);
  MainNurse *nurse = new MainNurse;

  nurse->addCommand(eye);
  nurse->addCommand(nose);

  nurse->treat();
  delete nurse;
  delete nose;
  delete eye;
  delete doctor;
}
int main(){
  // test01();
  commands();
  return 0;
}
