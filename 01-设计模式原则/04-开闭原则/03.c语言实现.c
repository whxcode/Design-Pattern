/*************************************************************************
> File Name: ./04-开闭原则/03.c语言实现.c
> Author: root
> Mail:
> Created Time: 2022年07月29日 星期五 15时04分03秒
 ************************************************************************/

#include <stdio.h>

void drawRectangle() { printf("绘制矩形\n"); }

void drawCircle() { printf("绘制圆形\n"); }

void drawTriangle() { printf("绘制三角形\n"); }
void drawStar() { printf("绘制星星\n"); }

void worker(void (*draw)()) { draw(); }

int main() {
  worker(drawCircle);
  worker(drawCircle);
  worker(drawTriangle);

  return 0;
}
