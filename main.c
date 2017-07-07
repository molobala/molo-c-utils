#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct _Student Student;
struct _Student{
    char nom[50];
    char prenom[50];
    int age;
    int id;
};
int main()
{
    LinkedList* list=LL_createList(NULL,NULL);
    Student* st=(Student*)malloc(sizeof(*st));
    st->age=18;
    st->id=1;
    strcpy(st->nom,"Doumbia");
    strcpy(st->prenom,"Molobala");
    LL_addAtListBegin(list,LL_createLinkedListElement(st));
    printf("The list size is : %ld \n",LL_getListLength(list));
    st=(Student*)malloc(sizeof(*st));
    st->age=18;
    st->id=2;
    strcpy(st->nom,"Doumbia");
    strcpy(st->prenom,"Alou");
    LL_addAtListEnd(list,LL_createLinkedListElement(st));
    st=(Student*)malloc(sizeof(*st));
    st->age=18;
    st->id=3;
    strcpy(st->nom,"Traore");
    strcpy(st->prenom,"Alou");
    LL_addAtListEnd(list,LL_createLinkedListElement(st));
    printf("After 2 operations, the list size is : %ld \n",LL_getListLength(list));
    printf("---------------------------------------------------\n");
    LinkedListElement *it=list->first;
    while(it){
        Student* tmp=(Student*)it->data;
        printf("Student : %d \n",tmp->id);
        printf("\t%s\n\t%s\n--------------------------------------------\n",tmp->nom,tmp->prenom);
        it=it->next;
    }
    LL_freeList(list);
    free(list);
    return 0;
}
