/*************************************************************************
> File Name: 01.website.cpp
> Author:
> Mail:
> Created Time: 2022年08月13日 星期六 17时45分25秒
 ************************************************************************/

#include <iostream>
#include <map>

using namespace std;
class User {
public:
  User(string name) { this->name = name; }

public:
  string name;
};

class Website {
public:
  virtual void use(User *user) = 0;

protected:
  string type;
};

class Web : public Website {
public:
  Web(string type) { this->type = type; }

public:
  void use(User *user) override {
    cout << type << "形式:" << user->name << endl;
  }
};

class WebSiteFactory {
public:
  WebSiteFactory() { webs.clear(); }

public:
  Website *getWeb(string type) {
    auto it = webs.find(type);

    if (it != webs.end()) {

      return it->second;
    }

    Web *web = new Web(type);
    webs.insert(make_pair(type, web));

    return web;
  }

public:
  static WebSiteFactory *getInstance() { return WebSiteFactory::instance; }

private:
  static WebSiteFactory *instance;

private:
  map<string, Website *> webs;
};

WebSiteFactory *WebSiteFactory::instance = new WebSiteFactory;

int main() {
  User *s1 = new User("w1");
  User *s2 = new User("w2");

  WebSiteFactory *factory = new WebSiteFactory;

  Website *e1 = factory->getWeb("email");
  Website *e2 = factory->getWeb("email");
  Website *n1 = factory->getWeb("new");

  e1->use(s1);
  e1->use(s2);

  n1->use(s1);

  delete s1;
  delete s2;

  delete (Web *)e1;
  delete (Web *)e2;
  delete (Web *)n1;

  delete factory;

  return 0;
}
