

#ifndef _Linked_list_H

#define _Linked_list_H

#include<stdio.h>
#include<stdlib.h>


#define MAX_NUMBER_OF_LINKED_LIST 2
struct Node
{
    int Data;
    struct Node* next;
};

//-------------------- Section of Public Prototype of Functions API's --------------------------//
extern void createList(struct Node **);
extern void Insert_First_node( struct Node **, int new_data);
extern void Insert_last_node( struct Node **listhead ,int new_data);
extern void insertToList( struct Node **listHead, unsigned char Index, int new_data);
extern void deleteFromList(struct Node **listhead, int index);
extern int searchIntoList(struct Node **listHead, int Searched_Data);
extern void printList(struct Node **listHead);
//---------------------------------------------------------------------------------------------//




#endif
