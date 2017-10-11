#include <stdio.h>

int main(int arg, char* argc[]){
	//Question 1

  int intVar;
  int* intPtr;
  long longVar;
  double* dblPtr;
  char** ch;

  printf("Size of int: %d bytes \n", sizeof(intVar));
  printf("Size of int pointer: %d bytes \n", sizeof(intPtr));
  printf("Size of long: %d bytes \n", sizeof(&longVar));
  printf("Size of double pointer: %d bytes \n", sizeof(dblPtr));
  printf("Size of char pointer pointer: %d bytes \n", sizeof(ch));


  return 0;
}
