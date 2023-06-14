#include<stdio.h>
#include<stdlib.h>

typedef  struct Procut {
  void (*transport)(struct Procut *this);
} Procut ;


typedef struct Factory {
  Procut * (* const create)(int type);
} Factory;


typedef struct Truck{
  void (*transport)(struct Procut *this);
  int id;
}Truck;


void trackTransport(Truck* this) {
  printf("Track transport %d:\n",this->id);
}


Truck* createTruck() {
  Truck* f = (Truck *)calloc(sizeof(Truck),1);
  void **fc = (void **)&f->transport;
  *fc = trackTransport;


  f->id = 100;


  return f;
};


Procut* factoryCreateMethod(int type) {
  if(type == 0) {
    return (Procut *)createTruck();
  }

  return NULL;
}

Factory* createFactory() {
  Factory* f = (Factory *)calloc(sizeof(Factory),1);
  void **fc = (void **)&f->create;

  *fc = factoryCreateMethod;

  return f;
};


void test02() {

  printf("fawef\n\n");
}

void test01() {
   long int a = (int long)test02;

   printf("%d\n",sizeof(long int));
   printf("%d\n",sizeof(void *));

   printf("%p\n",a);
   printf("%p\n",test02);
  // void* a = test02;
  
  // ((void (*)())(void *)a)();
  //

     ( (void(*)())((void *)a))();

   printf("55\n");
}

int main() {
  test01();
  calloc;
  malloc;
  // printf("hello word");
  //

  /*
  Factory * f = createFactory();
  Procut* p = f->create(0);

   printf("%p\n",factoryCreateMethod);
   printf("%p\n",f->create);
   printf("\n\n");

   printf("%p\n",trackTransport);
   printf("%p\n",p->transport);
   p->transport(p);
   */

  return 0;
}
