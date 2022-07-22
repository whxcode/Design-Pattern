/************************************************************************* >
File Name: 14-Share/03.外部状态.cpp > Author: root > Mail: > Created Time:
2022年07月22日 星期五 20时32分47秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;
class User {
public:
  User(string n) : name(n) {}

public:
  string name;
};
class WebSite {
public:
  WebSite(string name) : type(name) {}

public:
  virtual void use(User *user) = 0;
  string getType() { return type; }

private:
  string type;
};

class ConcreteWebSite : public WebSite {
public:
  ConcreteWebSite(string type) : WebSite(type) {}

public:
  void use(User *user) override {
    cout << user->name << "在使用:"
         << "网站的发布形式:" << getType() << endl;
  }

public:
};

class WebSiteFactory {
public:
  WebSite *getWebSite(string type) {
    auto it = webs.find(type);

    if (it != webs.end()) {
      return it->second;
    }

    WebSite *web = new ConcreteWebSite(type);
    webs.insert(make_pair(type, web));

    return web;
  }

  void printfWebs() {
    auto start = webs.begin();
    auto end = webs.end();

    while (start != end) {
      cout << "网站类型:" << (start++)->second->getType() << endl;
      ;
    }
  }

private:
  map<string, WebSite *> webs;
};

void test01() {
  WebSiteFactory *factory = new WebSiteFactory();

  WebSite *w1 = factory->getWebSite("新闻");
  WebSite *w2 = factory->getWebSite("新闻");
  WebSite *w3 = factory->getWebSite("博客");
  WebSite *w4= factory->getWebSite("博客");

  User *u1 = new User("dog");
  User *u2 = new User("cat");

  w1->use(u1);
  w2->use(u2);

  w3->use(u1);
  w4->use(u2);

  cout << endl;

  factory->printfWebs();
}

int main() {
  test01();
  return 0;
}
