/*************************************************************************
> File Name: 02-Wulin.cpp
> Author:
> Mail:
> Created Time: 2022年07月10日 星期日 17时33分57秒
 ************************************************************************/

#include <iostream>
#include <list>
#include <string>

using namespace std;
class Listenner {
public:
  virtual void onFriendBeFight(Listenner* one,Listenner* another) = 0;
  virtual void fighting(Listenner *another) = 0;
  virtual string getName() const = 0;
  virtual string getParty() const = 0;
};

class Notifier : public Listenner {
public:
  virtual void addListenner(Listenner *n) = 0;
  virtual void deleteListenner(Listenner *n) = 0;
  virtual void noticesAllListenner() = 0;
};

class Hero : public Listenner {
public:
  Hero(string name, string party) {
    this->name = name;
    this->party = party;
  }

public:
  void onFriendBeFight(Listenner* one,Listenner* another) override {

  }
  void fighting(Listenner *another) override {
    cout << name << "把" << another->getName() << "给打了一顿"
         << "[" << another->getParty() << "]" << endl;
    // 触发通知.
  }
  string getName() const override { return name; }

  string getParty() const override { return party; }

private:
  string name;
  string party;
};

class Baixiao : public Notifier {
public:
  void addListenner(Listenner *n) override {
    mList.push_back(n);
  }

  void deleteListenner(Listenner *n) override {
    mList.remove(n);
  }

  void noticesAllListenner() override {


    list<Listenner *>::iterator it = mList.begin();
    list<Listenner *>::iterator end = mList.end();

    while (it != end) {
      // (*it++)->onTeacherComming();
    }

  }

private:
  list<Listenner *> mList;
};

int main() {
  ;
  return 0;
}
