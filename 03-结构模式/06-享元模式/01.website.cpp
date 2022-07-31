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

class WebSite {
public:
  virtual void use() = 0;
};

class WebsiteEmail : public WebSite {
public:
  WebsiteEmail(string type) : type(type) {}

public:
  void use() override { cout << "type:" << type << endl; }

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

  WebSite *w1 = w->get("新闻");
  WebSite *w2 = w->get("新闻");

  w1->use();
  w2->use();
  printf("%d\n",w1 == w2);

  return 0;
}
