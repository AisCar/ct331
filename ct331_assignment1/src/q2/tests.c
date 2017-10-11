#include <stdio.h>
#include "tests.h"
#include "linkedList.h"
#include <string.h>


void lengthTest(){

	listElement* l2 = createEl("My String 0", 30);

	//Test length

	printf("Length: %d \n", length(l2));
	printf("\n");

}

void stackTests() {
	//Test push
	printf("push test\n");
	listElement* l3 = createEl("My String 0", 30);
	push(&l3, "My String 1", 12);
	push(&l3, "My String 2", 12);
	push(&l3, "My String 3", 12);
	push(&l3, "My String 4", 12);
	printf("Items in linkedlist:\n");
	traverse(l3);
	printf("\nLength: %d \n", length(l3));


	//Test pop
	printf("pop test\n");
	listElement* poppedEl = pop(&l3);
	printf("\nItems remaining in linkedlist:\n");
	traverse(l3);
	printf("\nLength: %d \n\n", length(l3));


}

void queueTests(){
	//Create linked list
	listElement* l4 = createEl("My String 0", 30);

	//Test enqueue
	printf("enqueue test \n");
	enqueue(&l4, "First Enqueuing String", 17);
	enqueue(&l4, "Another Enqueuing String", 25);
	printf("Items in linkedlist:\n");
	traverse(l4);
	printf("\nLength: %d \n\n", length(l4));


	//Test dequeue
	printf("dequeue test\n");
	listElement* dequeuedEl = dequeue(l4);
	printf("\nItem's remaining:\n");
	traverse(l4);
	printf("\nLength: %d \n\n", length(l4));

}


void runTests() {
	printf("Tests running...\n");
	listElement* l = createEl("Test String (1).", 30);
	traverse(l);
	printf("\n");

	//Test insert after
	listElement* l2 = insertAfter(l, "another string (2)", 30);
	insertAfter(l2, "a final string (3)", 30);
	traverse(l);
	printf("\n");

	// Test delete after
	deleteAfter(l);
	traverse(l);
	printf("\n");


	printf("Other tests... \n");
	lengthTest();
	queueTests();
	stackTests();

	printf("\nTests complete.\n");

}
