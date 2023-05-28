/*************************************************************************
> File Name: 02-creator-pattern/01.single.01.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 20:21:58 2023
 ************************************************************************/

#include<iostream>
using namespace std;

class Singletion01 {
  public:
    static const Singletion01* getInstance() {
      return Singletion01:: instance;
    }
  private:
    Singletion01(){}
  private:
    static const Singletion01 *instance;
};


// 饿汉模式
const Singletion01 *Singletion01::instance = new Singletion01();

class Singletion02 {
  public:
    static const Singletion02* getInstance() {
      if(Singletion02:: instance == NULL) {

        Singletion02::instance = new Singletion02();
      }

      return Singletion02:: instance;
    }
  private:
    Singletion02(){}
  private:
    static const Singletion02 *instance;
};

const Singletion02 * Singletion02::instance = NULL;


void test01() {

  auto s1 = Singletion01::getInstance();;
  auto s2 = Singletion01::getInstance();;
  
  printf("%d\n",s1 == s2);
}

void test02() {

  auto s1 = Singletion02::getInstance();;
  auto s2 = Singletion02::getInstance();;
  
  printf("%d\n",s1 == s2);
}

int main(){
  test01();
  test02();

  return 0;
}
