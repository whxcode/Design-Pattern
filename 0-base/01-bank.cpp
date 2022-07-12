/*************************************************************************
> File Name: 0-base/01-bank.cpp
> Author:
> Mail:
> Created Time: 2022年07月10日 星期日 20时16分05秒
 ************************************************************************/

#include <iostream>
using namespace std;
class BankWorker {
public:
  void save() const { cout << "存款" << endl; }
  void transfer() const { cout << "转账" << endl; }
  void pay() const { cout << "缴费" << endl; }
};

class AbstractWorker {
  public:
  virtual void dothing() = 0;
};

class SaveBanker : public AbstractWorker {
public:
  void dothing() { cout << "存款" << endl; }
};

class Transfer : public AbstractWorker {
public:
  void dothing() { cout << "转账" << endl; }
};

class Pay : public AbstractWorker {
public:
  void dothing() { cout << "支付" << endl; }
};

void test01() {
  BankWorker *worker = new BankWorker();
  worker->pay();
  worker->transfer();
  worker->save();
}

void test02() {
  AbstractWorker *save = new SaveBanker();
  AbstractWorker *transfer = new Transfer();
  AbstractWorker *pay = new Pay();

  save->dothing();
  transfer->dothing();
  pay->dothing();
}

int main() {

  test02();
  return 0;
}
