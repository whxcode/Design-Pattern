/*************************************************************************
> File Name: 02.accept.c
> Author:
> Mail:
> Created Time: 2022年08月15日 星期一 20时44分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int ID = 0;

typedef struct Park {
  int id;
  void (*accept)(struct Park *p, void (*fn)(struct Park *park));
} Park;

void accpet(Park *p, void (*fn)(Park *p)) { fn(p); }

Park *createPark() {
  Park *par = (Park *)calloc(sizeof(Park), 1);
  par->accept = accpet;
  par->id = ID++;

  return par;
}

void success(Park *p) { printf("success %d\n", p->id); }

void fail(Park *p) { printf("fail %d\n", p->id); }

int main() {
  Park *p = createPark();
  p->accept(p, success);
  p->accept(p, fail);

  return 0;
}
