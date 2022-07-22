/*************************************************************************
> File Name: 14-Share/02.fly_weight.cpp
> Author: root
> Mail:
> Created Time: 2022年07月22日 星期五 20时20分44秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;
class WebSite {
public:
  virtual void use() = 0;
};

class ConcreteWebSite : public WebSite {
public:
  ConcreteWebSite(string type) : type(type) {}

public:
  void use() override { cout << "网站的发布形式:" << type << endl; }

private:
  // 共享的模式
  string type;
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

  void printfWebs() {}

private:
  map<string, WebSite *> webs;
};

void test01() {
  WebSiteFactory *factory = new WebSiteFactory();

  WebSite *w1 = factory->getWebSite("新闻");
  WebSite *w2 = factory->getWebSite("新闻");

  w1->use();
  w2->use();
}

int main() {
  test01();
  return 0;
}
