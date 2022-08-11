/*************************************************************************
> File Name:
/root/study/c/desgin-pattern/02-结构模式/01-适配器模式/03-函数适配器.c > Author:
> Mail:
> Created Time: 2022年08月11日 星期四 21时04分34秒
 ************************************************************************/

#include <stdio.h>

int voltageV220() { return 220; };

int voltageV5() { return voltageV220() / (voltageV220() / 5); }


void charge(int (*output)()) { 

  printf("charge:%d\n", output());

}

int main() {
  charge(voltageV5);

  return 0;
}
