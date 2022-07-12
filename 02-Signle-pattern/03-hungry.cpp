/*************************************************************************
> File Name: 03-hungry.cpp
> Author:
> Mail:
> Created Time: 2022年07月12日 星期二 21时15分25秒
 ************************************************************************/

#include <iostream>
#include <memory>
#include <mutex>
#include <pthread.h>
#include <string.h>
#include <string>
#include <unistd.h>

using namespace std;

typedef struct Student {
  char name[10];
  int age;
} Student;

class Singelton {
public:
  Singelton() { cout << "Singelton()" << endl; }

public:
  static const Singelton *getInstance() {
    if (Singelton::singelton == NULL) {
      Singelton::singelton = new Singelton();
    }

    return Singelton::singelton;
  }

  static void free();

private:
  static Singelton const *singelton;
};

void Singelton::free() {
  if (Singelton::singelton != NULL) {
    delete Singelton::singelton;
    Singelton::singelton = NULL;
  }
}

Singelton const *Singelton::singelton = NULL;

pthread_mutex_t mMutex = PTHREAD_MUTEX_INITIALIZER;

class SingeltonThread {
public:
  SingeltonThread() { sleep(1); }

public:
  static const SingeltonThread *getInstance() {
    if (SingeltonThread::singelton == NULL) {
      pthread_mutex_lock(&mMutex); //互斥锁
      if (SingeltonThread::singelton == NULL) {

        SingeltonThread::singelton = new SingeltonThread();
      }
      pthread_mutex_unlock(&mMutex); //互斥锁
    }

    printf("SingeltonThread = %p\n", SingeltonThread::singelton);
    return SingeltonThread::singelton;
  }

  static void free();

private:
  static SingeltonThread const *singelton;
};

SingeltonThread const *SingeltonThread::singelton = NULL;

void test01() {
  Singelton const *p1 = Singelton::getInstance();
  Singelton const *p2 = Singelton::getInstance();

  printf("p1 == p2 = %d\n", p1 == p2);

  Singelton::free();
}

void *worker(void *data) {
  SingeltonThread const *p1 = SingeltonThread::getInstance();

  strcpy((char *)data, "whx");
  *(int *)((char *)data + 10) = 10;

  return NULL;
}

void test02() {

  // int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void
  // *(*start_routine) (void *), void *arg);
  //
  pthread_t t1;
  pthread_t t2;

  Student *s1 = (Student *)calloc(sizeof(Student), 1);
  Student *s2 = (Student *)calloc(sizeof(Student), 1);

  pthread_create(&t1, NULL, worker, s1);
  pthread_create(&t2, NULL, worker, s2);

  printf("s1->name %s,s2-age %d\n", "whnx", *(int *)((char *)s1 + 10));

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}

int main() {

  // test01();
  test02();

  return 0;
}
