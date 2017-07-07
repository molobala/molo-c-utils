/**
* Authors: Doumbia Mahamadou
* this file is under free licence , anyone can use , modify it
*/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct _LinkedListElement LinkedListElement;
typedef struct _LinkedList LinkedList;
/**
* \field data : the data that holds the linkedlist , this data can be any kind of pointer
* \field next : the next element pointed by this @LinkedListElement element in the @LinkedList
* \field prev : the previous element pointed by this @LinkedListElement element in the @LinkedList
*/
struct _LinkedListElement{
    void *data;///contient un pointeur sur la donnée de la list
    LinkedListElement *next;
    LinkedListElement *prev;
};
/**
* \field first: that is the first @LinkedListElement int the list
* \field end: that is the last @LinkedListElement in the list
* \field length that is the length of the list
*/
struct _LinkedList{
    LinkedListElement * first;
    LinkedListElement * end;
    long length;
    int freeData;
};

///Differents functions for manipulate a linkedlist
/**
* That function initialise a LinkedList pointer , and set it's begin element and it's end element
* @param list is the list pointer to initialise
* @param begin is the first element
* @param end is the end element
* @return void
**/
void LL_initList(LinkedList* list,LinkedListElement* begin,LinkedListElement *end);
/**
* That function is used to create a @LinkedListElement with data the @param data passed ass parameter
* @param data is the data of the element
* @return new @LinkedListElement
**/
LinkedListElement* LL_createLinkedListElement(void* data);
/**
* That function is called to create and initialise a new LinkedList pointer , the return type is @LinkedList pointer.
* @param first is the first element to put in the list, can be null
* @param end is the end of the list , can be null
* @return @LinkedList pointer
*/
LinkedList* LL_createList(LinkedListElement* premier,LinkedListElement* dernier);//impl
/**
* That function add an element ( @LinkedList ) to the linkedlist pointer passed to parameter at position pos
* @param list is the list to which we add the element
* @param element is the element to be added to the list
* @param pos is the position of insertion
* @return void
*/
void LL_addToList(LinkedList* list,LinkedListElement *element,long pos);//impl
/**
* That function is used to add an element at the end to the list
* @param list is the operand list
* @param element is element to to to the list
* @return void
*/
void LL_addAtListEnd(LinkedList* list,LinkedListElement* element);
/**
* That function is used to add an element at the begin to the list
* @param list is the operand list
* @param element is element to to to the list
* @return void
*/
void LL_addAtListBegin(LinkedList* list,LinkedListElement* element);
/**
* That function is called to delete or remove from a list a certain number of element.
* @param list is the list for operation
* @param pos is position from to begin the removing or deletion operation
* @param number is the number of elements to remove or delete
* @param del if true (!=0) then we free removed elements from the memory
* @return void
**/
void LL_deleteFromList(LinkedList* list,long pos,long number,int del);
/**
* That function is to free a portion of list from @param first
* @param first is the element form to begin the free operation
* number is the number of element to be freed from @param first
* @return the number of freed elements
*/
long LL_freePortion(LinkedListElement* first,long number);
/**
* That function is used to free a linkedlist
* @param list is the list to be freed
* @return void
**/
void LL_freeList(LinkedList* list);
/**
* That function is used to wipe a list but it does not free the list
* @param list is the list to be wiped
* @return void
**/
void LL_wipeList(LinkedList* list);
/**
* see @LL_wipeList
**/
void LL_clearList(LinkedList* list);
/**
* That function free a list element, it free the element list and it's data  pointer
* @param ele : the element  to be freed
* @return void
**/
void LL_freeLinkedListElement(LinkedListElement* ele);
/**
* That function check if a list is empty (list->first==list->end==NULL)
* @param list is the operand list
* @return 0 is the list is not empty otherwise 1
*/
int LL_isEmpty(const LinkedList* list);
/*getters functions*/
/**
* That function returns the number of element between two given @LinkedListElement
* @param first is the first @LinkedListElement
* @param last is the last @LinkedListElement
* @return the number of element between @param first and @param last
*/
long LL_getSizeBetween(const LinkedListElement* first,const LinkedListElement* last);
/**
* That function returns the length of the list
* @param list is the operand list
* @return the length of @param list
*/
long LL_getListLength(const LinkedList* list);
/**
* That function returns a @LinkedListElement at position index
* @param list is the operand list
* @param index the index in the list
* @return the element at the index @param index
*/
LinkedListElement *LL_getAt(const LinkedList* list,long index);//impl
/**
* That function returns the length of a portion of the list beginning from @param first element to then last reachable element
* @param first the element from to begin the calculation
* @return the number of element between @param first and the last reachable element
*/
long LL_getPortionLength(const LinkedListElement* first);
/**
* That function return the last @LinkedListElement element reachable from @param element pointer
* @param element is the element from which to begin research
* @return a @LinkedListElement representing the last accessible element from @param element
**/
LinkedListElement* LL_getLastBrother(LinkedListElement* first);
/**
* That function returns the @LinkedListElement at @param pos beginning from @param element to the last element accessible
* @param element is the element from which to begin operation
* @param pos is the index in that portion of list,that index can be negative in such case browsing is in descendant order
* @return the length of @param list
**/
LinkedListElement* LL_getBrotherAt(LinkedListElement* element,long pos);

#endif // LINKEDLIST_H_INCLUDED
