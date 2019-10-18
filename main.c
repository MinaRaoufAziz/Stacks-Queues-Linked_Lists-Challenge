
#include "Linked_List.h"




int main (void)
{

    struct Node* List_Head[MAX_NUMBER_OF_LINKED_LIST] ;

    int key;

    createList(&List_Head[0]);

    insertToList(&List_Head[0], 1, 20);
    insertToList(&List_Head[0], 2, 10);
    insertToList(&List_Head[0], 0 , 5);
    printList(&List_Head[0]);

    key=searchIntoList(&List_Head[0], 20);

    if(key != (-1))
    {
        printf("\nYour Searched Data is Found at index = %d\n",key);
    }

    deleteFromList(&List_Head[0],2);

    printList(&List_Head[0]);

    return 0;
}
