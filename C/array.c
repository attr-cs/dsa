#include <stdio.h>
#define SIZE 10

typedef struct MyList{
    int array[SIZE];
    int count;
}list;

// prototypes
void printList(list l);
void addElement(list *l);
int isEmpty(list l);
int isFull(list l);
void printArrayDetails(list l);
int findElement(list l, int ele);
void seperator();

int main()
{   
    list l;
    l.count = 0;
    printList(l);
    seperator();
    addElement(&l);
    seperator();
    printList(l);
    seperator();
    printArrayDetails(l);
    seperator();
    findElement(l, 54);
    seperator();
    return 0;
}

void printList(list l)
{
    if(isEmpty(l)){
        printf("List is empty!\n");
    } 
    else{
        for(int i=0; i<l.count;i++)
        {
            printf("%d ",l.array[i]);
        }
    }
}

void addElement(list *l){
    int noOfElements=0,i=0;
    if(!isFull(*l))
    {
        do{
            printf("Enter no of element want to add: ");
            scanf("%d",&noOfElements);
            if(noOfElements>(SIZE-l->count) || noOfElements<=0)
            {
                printf("Range(1,10)\n");
            }
        }while(noOfElements>(SIZE-l->count) || noOfElements<=0);
        
        for(i; i<noOfElements;i++)
        {
            printf("Enter list[%d]: ",i,l->array[l->count]);
            scanf("%d",&l->array[l->count]);
            l->count++;
        }

    }
    else{
        printf("List is full!\n");
    }
}

int isEmpty(list l){
    if(l.count==0)
    {
        return 1;
    }
    return 0;
}
int isFull(list l){
    if(l.count>=10)
    {
        return 1;
    }
    return 0;
}

void printArrayDetails(list l){
    printf("\nArray has %d elements.\n",l.count);
    printf("Consist: ");
    for(int i=0; i < l.count;i++){
        printf("%d ",l.array[i]);
    }
}

int findElement(list l, int element)
{
    for(int i=0 ; i<l.count ;i++)
    {
        if(l.array[i]==element)
        {
            printf("\nElement %d fount at index : %d\n",element,i);
            return 1;
        }
    }
    printf("Element not found!");
    return 0;
}

void seperator(){
    printf("\n**************************************\n");
}