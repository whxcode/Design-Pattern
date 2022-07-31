/*************************************************************************
> File Name: 03-结构模式/06-享元模式/01.website.cpp
> Author: root
> Mail:
> Created Time: 2022年07月31日 星期日 11时46分17秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

class User {
public:
  string name;
};

class WebSite {
public:
  virtual void use(User *user) = 0;
};

class WebsiteEmail : public WebSite {
public:
  WebsiteEmail(string type) : type(type) {}

public:
  void use(User *user) override {
    cout << "type:" << type << endl;
    cout << "name:" << user->name << endl;
  }

private:
  string type;
};

class WebSiteFactory {
public:
  WebSiteFactory() { webs.clear(); }

public:
  static WebSiteFactory *getInstance() { return WebSiteFactory::instance; }

public:
  WebSite *get(string type) {
    auto it = webs.find(type);

    if (it != webs.end()) {
      return it->second;
    }

    WebSite *web = new WebsiteEmail(type);
    webs.insert(make_pair(type, web));

    return web;
  }

private:
  static WebSiteFactory *instance;

private:
  map<string, WebSite *> webs;
};

WebSiteFactory *WebSiteFactory::instance = new WebSiteFactory;

int main() {
  WebSiteFactory *w = WebSiteFactory::getInstance();
  User* whx = new User();
  whx->name ="whx";

  User* dog = new User();
  dog->name ="dog";

  WebSite *w1 = w->get("新闻");
  WebSite *w2 = w->get("新闻");

  w1->use(whx);
  w2->use(dog);

  printf("%d\n", w1 == w2);

  delete w;
  delete whx;
  delete dog;

  delete (WebsiteEmail* )w1;
  delete (WebsiteEmail* )w2;

  return 0;
}
