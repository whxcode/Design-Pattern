/*************************************************************************
> File Name: ./02-依赖倒置原则/03.c语言实现.c
> Author: root
> Mail:
> Created Time: 2022年07月26日 星期二 21时31分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
  void (*dispay)(const char *(*getMessage)());
} Person;

void dispay(const char *(*getMessage)()) { printf("%s\n", getMessage()); }

Person *createPerson() {
  Person *p = (Person *)calloc(sizeof(Person), 1);
  p->dispay = dispay;

  return p;
}

const char *email() { return "Hell Email"; }
const char *wechat() { return "Hell Wechat"; }

int main() {

  Person *p = createPerson();

  p->dispay(email);
  p->dispay(wechat);

  return 0;
}
