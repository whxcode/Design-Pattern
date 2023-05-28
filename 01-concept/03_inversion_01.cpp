/*************************************************************************
> File Name: 01-concept/03_inversion_01.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 12:07:57 2023
 ************************************************************************/

#include<iostream>
using namespace std;

char *getEmail() {
  return (char *)"normal email";
}

void receive() {
  printf("receive %s\n",getEmail());
}

int main(){
  receive();
  return 0;
}
