/*************************************************************************
> File Name: 03-proxy/06.动态代理.cpp
> Author: root
> Mail:
> Created Time: 2022年07月22日 星期五 21时28分39秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

typedef map<string, const void *> Teach;

Teach m;

class ProxyFactory {
public:
  ProxyFactory(Teach *t) { this->t = t; }

private:
  class Proxy {
  public:
    const static string name;

  public:
    Proxy(Teach *t) { this->t = t; }

  public:
    void const *get(string name) {
      auto it = this->t->find(name);
      if (name == "name") {
        return &Proxy::name;
      }

      return it->second;
    }

    void pritnf() { cout << Proxy::name << endl; }

  private:
    Teach *t;
  };

public:
  Proxy *getProxyInstance() { return new Proxy(this->t); };

private:
  Teach *t;
};

const string ProxyFactory::Proxy::name = "我思，故我在";

void initial() {}

int main() {
  function<string(void)> getName1 = []() -> string { return "dog"; };
  string name = "cat";
  m.insert(make_pair("getName", (void *)&getName1));
  m.insert(make_pair("name", (void *)&name));

  ProxyFactory *factory = new ProxyFactory(&m);

  auto *proxy = factory->getProxyInstance();

  function<string(void)> *getName =
      (function<string(void)> *)proxy->get("getName");

  cout << (*getName)() << endl;
  string *name1 = ( string *)proxy->get("name");

  *name1 = "ww";

  cout << *name1 << endl;

  proxy->pritnf();

  return 0;
}
