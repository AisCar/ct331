#include <stdio.h>
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n");

  //...
  enum dataType { typeString, typeChar, typeInt, typeFloat, typeDouble};

  printf("\nTesting: create linked list with one int value\n");
  enum dataType t1;
  t1 = typeInt;
  int num = 1;
  void *ptr1 = (void*)num;
  listElement* l = createEl(*ptr1, sizeof(num), t1);
   traverse(l);

   printf("\nTesting push a char \n ");
   enum dataType t2;
   t2 = typeChar;
   char c = 'a';
   void *ptr2 = (void*)c;
   push(&l, *ptr2, t2)
   traverse(l);

   printf("\nTesting: push a float\n");
   enum dataType t3;
   t3 = typeFloat;
   float num2 = 0.7;
   void *ptr3 = (void*)num2;
   push(&l, *ptr3, sizeof(float), t3);
   traverse(l);

   printf("\nTesting: enqueue a string\n");
   enum dataType t4;
   t4 = typeString;
   void *ptr4 = (void*)"Hello World";
   enqueue(&l, *ptr4, sizeof("Hello World"), t4);
   traverse(l);

   printf("\nTesting: enqueue a double\n");
   enum dataType t5 = typeDouble;
   double num3 = 200.8
   void *ptr5 = (void*)"Hello World";
   enqueue(&l, *ptr5, sizeof(double), t5);
   traverse(l);

   printf("\nTesting: dequeue\n");
   dequeue(l);
   traverse(l);

   printf("\nTesting: pop\n");
   pop(l);
   traverse(l);


  printf("\nTests complete.\n");
}
