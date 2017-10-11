#ifndef CT331_ASSIGNMENT__GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, enum dataType type); 

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, enum dataType type);

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns the number of elements in a linked list.
int length(listElement* list);

//Push a new element onto the head of a list.
//Update the list reference using side effects.
void push(listElement** list, void* data, size_t size, enum dataType type);

//Pop an element from the head of a list.
// Update the list reference using side effect
listElement* pop(listElement** list);


//Enqueue a new element onto the head of the list.
void enqueue(listElement** list, void* data, size_t size, enum dataType type);

// Dequeue an element from the tail of the list.
listElement* dequeue(listElement* list);

#endif