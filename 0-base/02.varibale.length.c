/*************************************************************************
> File Name: 0-base/02.varibale.length.c
> Author: root
> Mail:
> Created Time: 2022年07月16日 星期六 21时35分18秒
 ************************************************************************/

#include <stdio.h>
int dog[10] = {0};

int (*getDog(int size))[10] { return &dog; }

void test01() {
  int a = 100;
  int(*dog)[10] = getDog(10);
  *(int *)dog = 10;

  *((int *)dog + 9) = 100000;
  *((int *)dog + 100) = 100000;

  printf("a=%d\n",a);
  printf("%d\n", (*dog)[0]);
  printf("%d\n", *((int *)dog + 9));
}
int main() {

  test01();
  return 0;
}
