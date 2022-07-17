/*************************************************************************
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 12时43分44秒
 ************************************************************************/

#include <functional>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

struct Singleton {
public:
  static const Singleton *getInstace() {
    sleep(1);
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

void test01() {
  const Singleton *s1 = Singleton::getInstace();
  const Singleton *s2 = Singleton::getInstace();

  printf("s1 == s2 %d\n", s1 == s2);
  printf("%p\n%p\n", s1, s2);
}

void *worke(void *data) {
  const Singleton *s1 = Singleton::getInstace();
  printf("%p\n", s1);

  return NULL;
}

void test02() {
  pthread_t t1;
  pthread_t t2;

  pthread_create(&t1, NULL, worke, NULL);
  pthread_create(&t2, NULL, worke, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}

int main() {

  test02();
  return 0;
}
