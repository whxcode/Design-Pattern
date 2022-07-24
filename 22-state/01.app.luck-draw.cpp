/*************************************************************************
> File Name: 22-state/01.app.luck-draw.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 09时52分05秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class State {
public:
  virtual void deduceMemory() = 0;
  virtual bool raffle() = 0;
  virtual void dispensePrize() = 0;
};

class RaffleActivity {
public:
  RaffleActivity(int count) {
    this->count = count;
    this->currentState = NULL;
  }

public:
  void setState(State *state) { currentState = state; }
  void inital(State *ns, State *cs, State *ds, State *dos) {

    this->ns = ns;
    this->cs = cs;
    this->ds = ds;
    this->dos = dos;
    this->currentState = ns;
  }

  State *getNoRaffleState() { return ns; }
  State *getCanRaffleState() { return cs; }
  State *getDispenseState() { return ds; }
  State *getDispenseOutState() { return dos; }
  int getCount() {
    int n = count;
    --count;
    return n;
  }

public:
  void deduceMoney() { currentState->deduceMemory(); }

  void raffle() {
    if (currentState->raffle() && this->count > 1) {
      currentState->dispensePrize();
    }
  }

private:
  State *currentState;
  int count;

  State *ns;
  State *cs;
  State *ds;
  State *dos;
};

class NoRaffleState : public State {
public:
  NoRaffleState(RaffleActivity *activity) { this->activity = activity; }

public:
  // 扣除了积分，将状态设置成可以抽将的状态
  void deduceMemory() override {
    cout << "扣除 50 积分了，你可以抽象了" << endl;
    activity->setState(activity->getCanRaffleState());
  }

  bool raffle() override {
    cout << "扣除了积分才能抽奖" << endl;
    return false;
  }

  void dispensePrize() override { cout << "不能发放奖品" << endl; }

private:
  RaffleActivity *activity;
};

class CanRaffleState : public State {
public:
  CanRaffleState(RaffleActivity *activity) { this->activity = activity; }

public:
  // 扣除了积分，将状态设置成可以抽将的状态
  void deduceMemory() override { cout << "可以抽奖了" << endl; }

  bool raffle() override {
    cout << "正在抽奖..." << endl;
    int n = 0;

    if (n == 0) {
      activity->setState(activity->getDispenseState());
      return true;
    }

    activity->setState(activity->getNoRaffleState());

    return false;
  }

  void dispensePrize() override { cout << "没中奖，你可以继续抽奖" << endl; }

private:
  RaffleActivity *activity;
};

class DispenseState : public State {
public:
  DispenseState(RaffleActivity *activity) { this->activity = activity; }

public:
  void deduceMemory() override { cout << "不能扣除积分了" << endl; }

  bool raffle() override {
    cout << "不能抽奖，以及获得了奖品了" << endl;
    return false;
  }

  void dispensePrize() override {
    if (activity->getCount() > 0) {
      cout << "恭喜你，中将了" << endl;
      activity->setState(activity->getNoRaffleState());
    } else {
      cout << "很遗憾，奖品发送完毕了" << endl;

      activity->setState(activity->getDispenseOutState());
    }
  }

private:
  RaffleActivity *activity;
};

class DispenseOutState : public State {
public:
  DispenseOutState(RaffleActivity *activity) { this->activity = activity; }

public:
  void deduceMemory() override { cout << "奖品已经抽完毕了" << endl; }

  bool raffle() override {
    cout << "奖品已经抽完毕了" << endl;
    return false;
  }

  void dispensePrize() override { cout << "奖品已经抽完毕了" << endl; }

private:
  RaffleActivity *activity;
};

int main() {
  RaffleActivity *a = new RaffleActivity(2);
  NoRaffleState *ns = new NoRaffleState(a);
  CanRaffleState *cs = new CanRaffleState(a);
  DispenseState *ds = new DispenseState(a);
  DispenseOutState *dos = new DispenseOutState(a);

  a->inital(ns, cs, ds, dos);

  int i = 0;
  while (i++ < 10) {
    cout << "-------------" << endl;
    a->deduceMoney();

    a->raffle();
    cout << endl;
  }

  return 0;
}
