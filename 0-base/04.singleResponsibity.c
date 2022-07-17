/*************************************************************************
> File Name: 0-base/04.singleResponsibity.c
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 08时41分26秒
 ************************************************************************/

#include <stdio.h>

// 对于 c 语言
//
void doWorke(const char *name, void (*method)(const char *name)) {
  method(name);
}

void flyRun(const char *name) { printf("战斗机:%s\n", name); }
void roadRun(const char *name) { printf("汽车:%s\n", name); }
void shipRun(const char *name) { printf("轮船:%s\n", name); }

void test01() {
  doWorke("bf109", flyRun);
  doWorke("摩托车", roadRun);
  doWorke("a", shipRun);
}

int main() {
  test01();
  return 0;
}
