/*************************************************************************
> File Name: 01-concept/03_inversion_01.cpp
> Author: 
> Mail: 
> Created Time: Sun May 28 12:07:57 2023
 ************************************************************************/

#include<iostream>
using namespace std;


void receive(char const *(*getEmail)()) {
  printf("receive %s\n",getEmail());
}

char const *qqEamil() {
  return (char *)"qq email";
}


char const *googleEmail() {
  return (char *)"google email";
}


int main(){
  receive(qqEamil);
  return 0;
}
