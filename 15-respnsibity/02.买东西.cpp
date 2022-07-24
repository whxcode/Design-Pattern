/*************************************************************************
> File Name: 15-respnsibity/02.买东西.cpp
> Author: root
> Mail:
> Created Time: 2022年07月24日 星期日 11时47分04秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

int globalID = 0;
class PurchaseRequest {
public:
  PurchaseRequest(int type, double price) {
    this->type = type;
    this->price = price;
  }

public:
  int getType() { return type; }
  int getId() { return id; }
  double getPrice() { return price; }

private:
  int type;
  int id;
  double price;
};

class Approver {
public:
  Approver(string name) { this->name = name; }

public:
  void setNextApprover(Approver *approver) { this->approver = approver; }

public:
  virtual void processRequest(PurchaseRequest *request) = 0;

protected:
  string name;
  Approver *approver;
};

class DepartmentApprover : public Approver {
public:
  DepartmentApprover(string name) : Approver(name) {}

public:
  void processRequest(PurchaseRequest *request) override {
    if (request->getPrice() <= 5000) {
      cout << "请求编号:" << request->getId() << "被:" << name << ":处理了"
           << endl;
      return;
    }

    approver->processRequest(request);
  }
};

class CollegeApprover : public Approver {
public:
  CollegeApprover(string name) : Approver(name) {}

public:
  void processRequest(PurchaseRequest *request) override {
    auto price = request->getPrice();
    if (price >= 5000 && price <= 10000) {
      cout << "请求编号:" << request->getId() << "被:" << name << ":处理了"
           << endl;
      return;
    }
    approver->processRequest(request);
  }
};

class ViceSchoolApprover : public Approver {
public:
  ViceSchoolApprover(string name) : Approver(name) {}

public:
  void processRequest(PurchaseRequest *request) override {
    auto price = request->getPrice();

    if (price >= 1000 && price <= 20000) {
      cout << "请求编号:" << request->getId() << "被:" << name << ":处理了"
           << endl;
      return;
    }
    approver->processRequest(request);
  }
};

class SchoolApprover : public Approver {
public:
  SchoolApprover(string name) : Approver(name) {}

public:
  void processRequest(PurchaseRequest *request) override {
    auto price = request->getPrice();

    if (price > 20000) {
      cout << "请求编号:" << request->getId() << "被:" << name << ":处理了"
           << endl;
      return;
    }

    approver->processRequest(request);
  }
};

int main() {
  PurchaseRequest *r = new PurchaseRequest(1, 10000);
  DepartmentApprover *d = new DepartmentApprover("系主任");
  CollegeApprover *c = new CollegeApprover("学院主任");
  ViceSchoolApprover *v = new ViceSchoolApprover("副校长");
  SchoolApprover *s = new SchoolApprover("校长");

  d->setNextApprover(c);
  c->setNextApprover(v);
  v->setNextApprover(s);
  s->setNextApprover(d);

  d->processRequest(r);
  s->processRequest(r);

  return 0;
}
