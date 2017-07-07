#include "linkedList.h"

/* ********************************************LinkedList ****************************************************** */
/*===================================== Setters functions =======================================================*/


void LL_initList(LinkedList* list,LinkedListElement* begin,LinkedListElement *end)
{
    if(!list)
        return;
    list->end=end;
    list->first=begin;
    list->length=0;
    if(end)
        list->length+=1;
    if(begin)
        list->length+=1;
}

LinkedList* LL_createList(LinkedListElement* first,LinkedListElement* end)
{
    //on crée une list
    LinkedList* newList=(LinkedList*)malloc(sizeof(*newList));
    LL_initList(newList,first,end);
    return newList;
}

void LL_addToList(LinkedList* list,LinkedListElement* element,long pos)
{
    if(!list)
        return;
    if(LL_isEmpty(list))
    {
        list->first=element;
        list->end=LL_getLastBrother(element);
        //printf("first et dernoer : %x et %x\n",list->first,list->end);
        list->length=1;
        return;
    }
    if(pos>=list->length)
    {

        element->prev=list->end;
        list->end->next=element;
        if(LL_getPortionLength(element)>1)
        {
            list->end=LL_getLastBrother(element);
        }
        else
        {

            list->end=element;
        }
    }
    else if(pos<=0)
    {
        if(LL_getPortionLength(element)>1)
        {
            LinkedListElement *endFrere=LL_getLastBrother(element);
            endFrere->next=list->first;
            list->first->prev=endFrere;
        }
        else
        {
            element->next=list->first;
            list->first->prev=element;
        }

        list->first=element;
    }
    else
    {
        //on recupère l'element à la position pos
        LinkedListElement* elementAtPos = LL_getAt(list,pos);
        if(!elementAtPos)
            return;
        LinkedListElement *elementPrec=elementAtPos->prev;

        element->next=elementAtPos;
        element->prev=elementPrec;

        elementAtPos->prev=element;
        if(elementPrec) elementPrec->next=element;
        //on incremente la taille de la list
    }
    list->length+=1;
}
/// -------------------------------------------------- La fonction LL_deleteFromList() -------------------------------------------

void LL_deleteFromList(LinkedList* list,long pos,long number,int del)
{
    if(!list || LL_isEmpty(list) || !number)
        return;
    LinkedListElement* elementASupprimer=LL_getAt(list,pos);
    if(!elementASupprimer)
        return;
    LinkedListElement *elementPrec,*elementSuiv;
    if(number!=0)
    {
        elementPrec=(number>0)?elementASupprimer->prev:LL_getBrotherAt(elementASupprimer,number),
        elementSuiv=(number<0)?elementASupprimer->next:LL_getBrotherAt(elementASupprimer,number);
    }
    else
    {
        elementPrec=elementASupprimer->prev;
        elementSuiv=elementASupprimer->next;
    }
    if(elementPrec && elementSuiv)
    {
        elementPrec->next=elementSuiv;
        elementSuiv->prev=elementPrec;

    }
    else if(!elementPrec && elementSuiv)
    {
        list->first=elementSuiv;
        elementSuiv->prev=NULL;
    }
    else if(elementPrec && !elementSuiv)
    {
        list->end=elementPrec;
        elementPrec->next=NULL;
    }
    else
    {
        list->first=NULL;
        list->end=NULL;
    }
    if(del) LL_freePortion(elementASupprimer,number);
    if(number+pos>=list->length)
        number=list->length-pos;
    else if(number+pos<=0)
        number=pos+1;
    list->length-=abs(number);
}

void LL_freeList(LinkedList* list)
{
    LL_freePortion(list->first,LL_getListLength(list));
    list->length=0;
    //free(list);
}


void LL_wipeList(LinkedList* list)
{
    if(!list || LL_isEmpty(list))
        return;
    list->first=NULL;
    list->end=NULL;
    list->length=0;
}

void LL_clearList(LinkedList* list)
{
    LL_wipeList(list);
}

long LL_freePortion(LinkedListElement* first,long number)
{
    if(!first)
        return 0;
    int inc=1;
    LinkedListElement *tmp=first;
    if(number<0)
        inc=-1;
    long i=0;
    for(;i!=number && first;first=(inc<0)?first->prev:first->next,i+=inc,LL_freeLinkedListElement(tmp),tmp=first);
    return i;
}

void LL_addAtListBegin(LinkedList* list,LinkedListElement* element)
{
    LL_addToList(list,element,0);
}

void LL_addAtListEnd(LinkedList* list,LinkedListElement* element)
{
    LL_addToList(list,element,list->length);
}

void LL_freeLinkedListElement(LinkedListElement* ele)
{
    if(ele->data)
        free(ele->data);
    free(ele);
}

 LinkedListElement* LL_createLinkedListElement(void* data)
 {
     LinkedListElement* nouveau=(LinkedListElement*)malloc(sizeof(*nouveau));
     if(!nouveau)
        return NULL;
     nouveau->next=NULL;
     nouveau->prev=NULL;
     if(!nouveau)
        return NULL;
     nouveau->data=data;
     return nouveau;
 }
/** ================================================== Fin des fonction setters ==============================================*/
/** ==================================================Les fonction getters ===================================================*/

///fonction returnant le end frère d'un element web

LinkedListElement* LL_getLastBrother(LinkedListElement* element)
{
    if(!element)
        return NULL;
    while(element->next)
    {
        element=element->next;
    }
    return element;
}
///La fonction retournant la longeur exacte de la list

long LL_getListLength(const LinkedList* list)
{
    /**
    * le champ length de la structure length contient normalenemt la longueur de la list mais on va pas le retourner , on va
    * parcourir la list et compte le number exacte d'element qu'elle contient
    */
    if(!list)
        return -1;
    LinkedListElement* element;
    long numberEl=0;
    for(element=list->first;element;element=element->next,numberEl++);
    ///on met à jour la longeur de la list si elle n'y est pas
    /*if(list->length!=numberEl)
        list->length=numberEl;*/
    return numberEl;
}
///fonction returnant la longueur d'une portion de list

int LL_isEmpty(const LinkedList* list)
{
    return (list->first==NULL)?1:0;
}

long LL_getPortionLength(const LinkedListElement* first)
{
    if(!first)
        return 0;
    long length=1;
    while((first=first->next))
        length+=1;
    return length;
}

LinkedListElement* LL_getAt(const LinkedList* list,long index)
{
    if(!list || LL_isEmpty(list))
        return NULL;
    if(index<0 || index>=list->length)
        return NULL;
    LinkedListElement* elementToReturn;
    long i;
    for(i=0,elementToReturn=list->first;i<index && elementToReturn;i++,elementToReturn=elementToReturn->next);
    return elementToReturn;
}

LinkedListElement* LL_getBrotherAt(LinkedListElement* element,long pos)
{
    if(!element)
        return NULL;
    int inc=1;
    if(pos<0)
        inc=-1;
   // LinkedListElement *tmp=(inc<0)?element->next:element->prev;
    long i=0;
    for(;i!=pos && element ; element=(inc<0)?element->prev:element->next,i+=inc);
    return element;
}

long LL_getSizeBetween(const LinkedListElement* first,const LinkedListElement* last)
{
    if(first==last)
        return 0;
    else if(first->next==last)
        return 0;
    long s=0;
    for(first=first->next;first!=last;first=first->next,s++);
    return s;
}
