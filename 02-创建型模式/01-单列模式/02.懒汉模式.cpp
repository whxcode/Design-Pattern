/*************************************************************************
> File Name: 02-创建型模式/01-单列模式/01.俄汉式模式.cpp
> Author: root
> Mail:
> Created Time: 2022年07月29日 星期五 21时05分25秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <threads.h>
#include <unistd.h>
using namespace std;

class Singleton {
public:
  //  该静态方法存在线程安全问题
  static Singleton *getInstance() {
    if (Singleton::instance == NULL) {
      Singleton::instance = new Singleton;
    }

    return Singleton::instance;
  }

  //  该静态方法不存在线程安全问题
  static Singleton *getInstanceImprove() {
    if (Singleton::instance == NULL) {
      pthread_mutex_lock(&Singleton::mutex);

      if (Singleton::instance == NULL) {
        Singleton::instance = new Singleton;
      }

       pthread_mutex_unlock(&Singleton::mutex);
    }

    return Singleton::instance;
  }

private:
  Singleton() {}

private:
  static pthread_mutex_t mutex;
  static Singleton *instance;
};

Singleton *Singleton::instance = NULL;
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;

void *unsafe(void *data) {
  Singleton *s1 = Singleton::getInstance();
  printf("s1 %p\n", s1);

  return NULL;
}

void *safe(void *data) {
  Singleton *s1 = Singleton::getInstanceImprove();
  printf("s1 %p\n", s1);

  return NULL;
}

void worker(void *(*w)(void *)) {
  pthread_t t1;
  pthread_t t2;
  pthread_t t3;
  pthread_t t4;

  pthread_create(&t1, NULL, w, NULL);
  pthread_create(&t2, NULL, w, NULL);
  pthread_create(&t3, NULL, w, NULL);
  pthread_create(&t4, NULL, w, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
}

int main() {
  // worker(unsafe);
  // sleep(1);
  // cout << endl;

  // sleep(3);
  worker(safe);
  int a;

  return 0;
}
