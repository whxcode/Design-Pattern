/*************************************************************************
> File Name: 02-creator-pattern/01.single.01.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 20:21:58 2023
 ************************************************************************/

#include<iostream>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


using namespace std;


pthread_mutex_t t = PTHREAD_MUTEX_INITIALIZER;;


class Singletion {
  public:
    static const Singletion* getInstance() {
      if(Singletion:: instance == NULL) {
      sleep(1);

pthread_mutex_lock(&t);

      if(Singletion:: instance == NULL) {

        Singletion::instance = new Singletion();
      }

pthread_mutex_unlock(&t);
      }

      return Singletion:: instance;
    }
  private:
    Singletion(){}
  private:
    static const Singletion *instance;
};

const Singletion * Singletion::instance = NULL;


class Singletion01 {
  public:
    static const Singletion01* getInstance() {
      sleep(1);
      if(Singletion01:: instance == NULL) {

        Singletion01::instance = new Singletion01();
      }

      return Singletion01:: instance;
    }
  private:
    Singletion01(){}
  private:
    static const Singletion01 *instance;
};

const Singletion01 * Singletion01::instance = NULL;


void test02() {

  auto s2 = Singletion01::getInstance();;
  auto s3 = Singletion01::getInstance();;
  
  printf("%d\n",s2 == s3);
}

void *worker(void *) {
  auto s = Singletion::getInstance();
  printf("%p\n",s);
  return NULL;
}


void test03() {
  pthread_t t[10];

  for(int i = 0;i< 10;++ i) {
    pthread_create(t + i,NULL,worker,NULL);
  }

  for(int i = 0;i< 10;++ i) {
    pthread_join(*(t + i),NULL); }
}

int main(){
  // test02();
  test03();

  return 0;
}
