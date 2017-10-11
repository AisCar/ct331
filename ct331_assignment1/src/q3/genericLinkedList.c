

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
	void* data;
	size_t size;
	struct listElementStruct* next;
	void (*fp)();//void pointer to function
} listElement;

enum dataType { typeString, typeChar, typeInt, typeFloat, typeDouble };

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, enum dataType type){
	listElement* e = malloc(sizeof(listElement));

	if(e == NULL){
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}

	switch(type) {//This is a mess
	case 1:
		void* dataPointer = malloc(sizeof(*char)*size);
		*e->fp = *printString(); //I do not know how null function pointers work
	case 2:
		void* dataPointer = malloc(sizeof(char)*size);
		e->fp = *printChar();
	case 3:
		void* dataPointer = malloc(sizeof(int)*size);
		e->fp = *printInt();
	case 4:
		void* dataPointer = malloc(sizeof(float)*size);
		(*fp)() = *printFloat(); 
	case 5: 
		void* dataPointer = malloc(sizeof(double)*size);
		(*fp)() = *printDouble();
	default:
		printf("Invalid data type passed into constructor");
		return 0;

	}
	
	if(dataPointer == NULL){
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	strcpy(dataPointer, data);
	
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start, void *printFunction()){
	listElement* current = start;
	while (current != NULL) {
		*printFunction(current->data);
		current = current->next;
	}
}

//Print methods for different data types
void printString(void* data) {
	printf("%s\n", *(char*)data);
}
void printChar(void* data) {
	printf("%c\n", *(char*)data);
}
void printInt(void* data) {
	printf("%d\n", *(int*)data);
}
void printFloat(void* data) {
	printf("%f\n", *(float*)data);
}
void printDouble(void* data) {
	printf("%f\n", *(double*)data);
}



//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, enum dataType type){
	listElement* newEl = createEl(data, size, type);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}


//============================part 2 code below ===============

	//Returns the number of elements in a linked list.
	int length(listElement* first) {
		int len = 0;
		listElement* curr = first;
		while (curr != NULL) {
			len++;
			curr = curr->next;
		}
		return len;
	}

	//Push a new element onto the head of a list.
	//Update the list reference using side effects.
	void push(listElement** list, void* data, size_t size, enum dataType type) {
		listElement* newHead = createEl(data, size, type);
		newHead->next = *list;
		*list = newHead;
	}

	//Pop an element from the head of a list.
	// Update the list reference using side effect
	listElement* pop(listElement** list) {
		listElement* popped = *list;
		*list = popped->next;

		return popped;
	}

	//Enqueue a new element onto the head of the list.
	//Update the list reference using side effects.
	void enqueue(listElement** list, void* data, size_t size, enum dataType type) {
		listElement* newHead = createEl(data, size, type);
		newHead->next = *list;
		*list = newHead;

	}

	// Dequeue an element from the tail of the list.
	listElement* dequeue(listElement* list) {
		listElement* current = list;
		listElement* previous;

		if (length(list) <= 0) {
			printf("Cannot dequeue, list is empty.");
			return NULL;
		}

		for (int i = 1; i < length(list); i++){
			previous = current;
			current = current->next;
		}
		//current is now last item - the tail
		//previous is now second last item
		previous->next = NULL;
		return current;
	}

