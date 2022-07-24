/*************************************************************************
> File Name: 19-interpreter/01.express.cpp
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 20时29分04秒
 ************************************************************************/

#include <iostream>
using namespace std;

struct Context {
public:
  Context(int num) {
    this->num = num;
    this->res = 0;
  }
  int getNum() { return num; }
  void setNum(int num) { this->num = num; }

  int getResult() { return res; }
  void setResult(int res) { this->res = res; }

private:
  int num;
  int res;
};

struct Interpreter {
public:
  virtual void expression(Context *context) = 0;
};

struct PlusExpress : public Interpreter {
public:
  void expression(Context *context) override {
    int num = context->getNum();
    num++;
    context->setResult(num);
  }
};

struct DecreaseExpress : public Interpreter {
public:
  void expression(Context *context) override {
    int num = context->getNum();
    num--;
    context->setResult(num);
    context->setNum(num);
  }
};

void test01() {
  Context *ctx = new Context(10);
  Interpreter *plus = new PlusExpress();
  Interpreter *decrease = new DecreaseExpress();

  cout << ctx->getResult() << endl;

  plus->expression(ctx);
  cout << ctx->getResult() << endl;

  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);
  decrease->expression(ctx);

  cout << ctx->getResult() << endl;
}
int main() {

  test01();
  return 0;
}
