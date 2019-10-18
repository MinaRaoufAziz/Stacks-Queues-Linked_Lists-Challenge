#include <stdio.h>
#include <stdlib.h>


typedef struct {
int Size;
int Front;
int Rear;
int *Q;
}ST_queueInfo;

void createQueue(ST_queueInfo* info, int maxSize)
{
    info->Size=maxSize;
    info->Front = info->Rear =-1;
    info->Q = (int *) malloc(info->Size * sizeof(int));
}

void enqueue(ST_queueInfo *info, int data)
{
    if(info->Rear==(info->Size -1))
    {
        printf("Stack is Full/n");
    }
    else
    {
        info->Rear++;
      info->Q[info->Rear]=data;
    }

}

int dequeue(ST_queueInfo *info)
{
    int data=-1;
    if(info->Rear==(info->Front))
    {
        printf("Stack is Empty/n");
    }
    else
    {
        info->Front++;
      data=info->Q[info->Front];
    }
return data;
}

void display(ST_queueInfo info)
{
    int i =0;
    for(i=(info.Front)+1;i<=info.Rear;i++)
    {
        printf("%d ",info.Q[i]);
    }
    printf("\n");
}
int main()
{
    ST_queueInfo q;
    createQueue(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    display(q);

    printf("%d\n",dequeue(&q));
    return 0;
}
