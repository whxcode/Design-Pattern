/*************************************************************************
> File Name: 01-CreatePattern/17.简单工厂模式.皮萨.c
> Author: root
> Mail:
> Created Time: 2022年07月17日 星期日 16时41分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct Pizza {
  void (*prepare)();
  char *name;

} Pizza;

Pizza *create() {
  Pizza *pizza = calloc(sizeof(Pizza), 1);
  return pizza;
}
void prepareGreekPizza() { printf("希腊皮萨\n"); }

Pizza *createGreekPizza() {
  Pizza *pizza = create();
  pizza->prepare = prepareGreekPizza;

  return pizza;
}

void prepareChessePizza() { printf("奶酪皮萨\n"); }

Pizza *createChessePizza() {
  Pizza *pizza = create();
  pizza->prepare = prepareChessePizza;

  return pizza;
}

Pizza *createPizza(char type) {
  if (type == 'g') {
    return createGreekPizza();
  } else if (type == 'c') {
    return createChessePizza();
  }

  return NULL;
}

int main() {
  Pizza *greek = createPizza('g');
  Pizza *chessse = createPizza('c');

  greek->prepare();
  chessse->prepare();

  free(greek);
  free(chessse);

  return 0;
}
