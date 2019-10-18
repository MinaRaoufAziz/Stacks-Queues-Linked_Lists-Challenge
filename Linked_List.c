

#include "Linked_List.h"

 //---------------------------------------------------------//



void createList(struct Node **listhead)
{
    *listhead = NULL;
}


void Insert_First_node( struct Node **listhead, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->Data = new_data;
	new_node->next = (*listhead);
	(*listhead) = new_node;
}

void Insert_last_node( struct Node **listhead ,int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *listhead;

	new_node->Data = new_data;

	new_node->next = NULL;

	if (*listhead == NULL)
	{
	*listhead = new_node;
	return;
	}

	while (last->next != NULL)
		{last = last->next;}

	last->next = new_node;
	return;
}


void insertToList( struct Node **listHead, unsigned char Index, int new_data)
{
       int i=0;
       if( *listHead == NULL)
        {
          Insert_First_node (listHead ,new_data);
          return;
        }

      if( Index == 0 )
      {
         Insert_First_node (listHead ,new_data);
          return;
      }

       struct Node* pointer = *listHead;

        for(i=0; i<Index ; i++)
        {
            if( (pointer->next) == NULL )
            {
               Insert_last_node (listHead, new_data);
               return;
            }
            else
            {pointer=pointer->next ;}
        }

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->Data = new_data ;
        new_node->next= pointer->next;
        pointer->next=new_node ;
}




void deleteFromList(struct Node **listhead, int index)
{
    int i=0;
    if(*listhead==NULL)       //  the linked_listed is empty
    {
        return ;
    }

    struct Node* pointer = *listhead;


	if (index == 0)
	{
		*listhead = pointer->next; // Change head
		free(pointer);			      // free old head
		return;
	}

	// Find previous ST_node of the ST_node to be deleted
     for( i=0;i<index-1;i++)
     {
         if((pointer->next)== NULL)
             {
                 printf("\n Error the index is not found \n");
                 return;
             }
         else
            {
                pointer=pointer->next ;
            }
     }

	struct Node* temp;
	temp = pointer->next->next;

	free(pointer->next);
	pointer->next = temp;
}


int searchIntoList(struct Node **listHead, int Searched_Data)
{
    struct Node* pointer ;  // Initialize current
    int key_counter = 0;

    for(pointer = (*listHead) ; pointer != NULL ; pointer = pointer->next)
    {
        if (pointer->Data == Searched_Data)
        {
            return key_counter;
        }
        key_counter++;
    }

    printf("\nYour Searched Data is not Found\n");
    return -1;
}


void printList(struct Node **listHead)
{
    struct Node* pointer= *listHead;

	while (pointer != NULL)
	{
		printf(" %d ", pointer->Data);
		pointer = pointer->next;
	}
}



