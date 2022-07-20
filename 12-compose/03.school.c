/*************************************************************************
> File Name: 12-compose/03.school.c
> Author: root
> Mail:
> Created Time: 2022年07月20日 星期三 21时28分13秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Base {
  char name[512];
  char describe[512];

} Base;

typedef struct Organization {
  Base base;
  void (*add)(struct Organization *o, void *data);
  void (*remove)(struct Organization *o);
  void (*printf)(void *data);
} Organization;

typedef struct University {
  Base base;

  int index;
  void *data[10];
  void (*add)(struct University *o, void *data);
  void (*remove)(struct Organization *o);
  void (*printf)(void *data);

} University;

typedef struct College {
  Base base;
  int index;
  void *data[10];

  void (*add)(struct College *o, void *data);
  void (*remove)(struct College *o, void *data);
  void (*printf)(void *data);

} College;

typedef struct Department {
  Base base;

  void (*printf)(void *data);
} Department;



void addUniversity(University *u, void *data) { u->data[u->index++] = data; }

void printfUniversity(void *data) {
  University *u = (University *)data;
  printf("--University--name:%s,describe:%s---\n", u->base.name,
         u->base.describe);
  for (int i = 0; i < u->index; ++i) {
    College *c = (College *)*(u->data + i);
    c->printf(c);
  }
}

University *createUniversity(const char *name, const char *describe) {
  University *u = calloc(sizeof(University), 1);
  u->printf = printfUniversity;
  u->add = addUniversity;
  u->index = 0;

  strcpy(u->base.name, name);
  strcpy(u->base.describe, describe);

  return u;
}

void printfCollege(void *data) {
  College *u = (College *)data;
  printf("--College--name:%s,describe:%s---\n", u->base.name, u->base.describe);
  for (int i = 0; i < u->index; ++i) {
    Department *c = (Department *)*(u->data + i);
    c->printf(c);
  }
}

void addCollege(College *u, void *data) { u->data[u->index++] = data; }

College *createCollege(const char *name, const char *describe) {
  College *u = calloc(sizeof(College), 1);

  u->printf = printfCollege;
  u->add = addCollege;
  u->index = 0;

  strcpy(u->base.name, name);
  strcpy(u->base.describe, describe);

  return u;
}

void printfDepartment(void *data) {
  Department *u = (Department *)data;
  printf("--Department--name:%s,describe:%s---\n", u->base.name, u->base.describe);
}


Department *createDepartment(const char *name, const char *describe) {
  Department *u = calloc(sizeof(Department), 1);

  u->printf = printfDepartment;

  strcpy(u->base.name, name);
  strcpy(u->base.describe, describe);

  return u;
}


void test01() {

  Department *d1 = createDepartment("信息工程系", "d1");
  Department *d2 = createDepartment("软件工程系", "d2");
  Department *d3 = createDepartment("网络工程", "d3");
  Department *d4 = createDepartment("人工智能", "d4");


  College *c1 = createCollege("信息工程学院", "c1");
  College *c2 = createCollege("计算机科学院", "c2");

  c1->add(c1,d1);
  c1->add(c1,d2);

  c2->add(c2,d3);
  c2->add(c2,d4);

  University *u1 = createUniversity("清华大学", "u1");

  u1->add(u1, c1);
  u1->add(u1, c2);

  u1->printf(u1);

  free(d1);
  free(d2);
  free(d3);
  free(d4);

  free(c1);
  free(c2);

  free(u1);
}

int main() {
  test01();
  return 0;
}
