// Set operations using linked lists

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int info;
    struct node *next;
};

void display(struct node *start)
{
    struct node*p;
    if (start==NULL)
    {
        printf("The set is empty!\n");
        return;
    }

  
    p=start;
    
    while(p!=NULL)
        {
            printf("%d ",p->info);
            p=p->next;
        }
    
    printf("\n");
}

struct node *addatbeg(struct node *start, int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    temp->info=data;
    temp->next=start;
    start=temp;
    return start;
}

struct node *addatend(struct node *start, int data)
{
    struct node *temp,*p;
    
    temp=(struct node *)malloc(sizeof(struct node));

    temp->info=data;

    p=start;
    while(p->next!=NULL)
        p=p->next;
    
    p->next=temp;
    temp->next=NULL;
    return start;
}

struct node *createList(struct node *start)
{
    int i,n,data;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    start=NULL;

    if(n==0)
        return start;

   
    for(i=0;i<n;i++)
    {
        if (i==0)
        {
            printf("Enter element 0: ");
            scanf("%d",&data);
            start=addatbeg(start,data);
        }


        else 
        {
            printf("Enter element %d: ",i);
            scanf("%d",&data);
            start=addatend(start,data);
        }
            
        
                
    }
    return start;
}




struct node *insertElement(struct node *start, int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    temp->info=data;
    temp->next=start;
    start=temp;
}

bool isPresent(struct node *start, int data)
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        if(p->info==data)
            return 1;
        
        p=p->next;
    }
    return 0;
}


void sort(struct node *start)
{
    struct node *p1,*p2;
    int temp;

    p1=start;

    while(p1!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p1->info>p2->info)
            {
                temp=p1->info;
                p1->info=p2->info;
                p2->info=temp;
            }
            p2=p2->next;
        }

        p1=p1->next;        
    }    
}

struct node *getUnion(struct node *start1, struct node *start2)
{

    struct node* un = NULL;
    struct node *p1=start1;
    struct node *p2=start2;
  
    
    while (p1!= NULL)
	{
        un=insertElement(un,p1->info);
        p1=p1->next;
     }
  
  
  
    while (p2 != NULL) 
    {
        if (!isPresent(un, p2->info))
		{
            un=insertElement(un, p2->info);
         }
            
        p2=p2->next;
    }

  
    return un;

}


struct node *getIntersection(struct node* start1,struct node* start2)
{
    struct node* inter = NULL;
    struct node* p1 = start1;
  
    
    while (p1 != NULL) 
    {
        if (isPresent(start2, p1->info))
        {
            insertElement(inter, p1->info);
        }
        p1 = p1->next;
    }
  
    return inter;
}



int main()
{
    struct node *start1=NULL,*start2=NULL,*un=NULL,*inter=NULL;
    int choice;

    printf("Enter set 1:-\n");
    start1=createList(start1);
    sort(start1);

    printf("\nEnter set 2:-\n");
    start2=createList(start2);
    sort(start2);

    printf("Set 1: ");
    display(start1);

    printf("Set 2: ");
    display(start2);

    printf("Enter the operation you want to perform on the two sets:-\n"
           "1. Union\n"
           "2. Intersection\n"
           "Enter your choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
        printf("\nUnion: ");
        un=getUnion(start1,start2);
        sort(un);
        display(un);
        break;

        case 2:
        printf("Intersect: ");
        inter=getIntersection(start1,start2);
        display(inter);
        break;

        default:
        printf("Invalid input!\n");
        break;
    }


    

}
