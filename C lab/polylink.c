
#include <stdio.h>
#include <stdlib.h>
struct node{
    int coef;
    int expo;
    struct node *next;
};
struct node *start=NULL;
struct node *starta=NULL;
struct node *startb=NULL;

int insert(struct node **star,int c,int e){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("OVERFLOW ERROR!!!");
        return 0;
    }
    ptr->expo=e;
    ptr->coef=c;
    ptr->next=NULL;
    if(*star==NULL){
        *star=ptr;
    }else{
        struct node *temp=*star;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
    return 1;
    
    
}
void addpoly(){
    struct node *tempa=starta;
    struct node *tempb=startb;
    while(tempa!=NULL || tempb!=NULL){
        if(tempa==NULL){
            insert(&start,tempb->coef,tempb->expo);
            tempb=tempb->next;
        }else if(tempb==NULL){
            insert(&start,tempa->coef,tempa->expo);
            tempa=tempa->next;
        }else{
            if(tempa->expo == tempb->expo){
                insert(&start,tempa->coef+tempb->coef,tempa->expo);
                tempa=tempa->next;
                tempb=tempb->next;
            }else if(tempa->expo > tempb->expo){
                insert(&start,tempa->coef,tempa->expo);
                tempa=tempa->next;
            }else{
                insert(&start,tempb->coef,tempb->expo);
                tempb=tempb->next;
            }
        }
    }
}

int display(struct node **star){
    if(*star==NULL){
        printf("EMPTY!!!");
        return 0;
    }else{
        struct node*temp=*star;
        while(temp!=NULL){
            printf("%dx^%d",temp->coef,temp->expo);
            temp=temp->next;
            if(temp!=NULL){
                printf(" + ");
            }
        }
        printf("\n");
    }
}


int main()
{
    int n1,n2,i,ex,co;
    printf("Enter the size of first poly:");
    scanf("%d",&n1);
    printf("Enter the size of second poly:");
    scanf("%d",&n2);
    printf("Enter first polynomial values:\n");
    for(i=0;i<n1;i++){
        printf("Coefficient:");
        scanf("%d",&co);
        printf("Exponent:");
        scanf("%d",&ex);
        insert(&starta,co,ex);
    }
    printf("Enter second polynomial values:\n");
    for(i=0;i<n2;i++){
        printf("Coefficient:");
        scanf("%d",&co);
        printf("Exponent:");
        scanf("%d",&ex);
        insert(&startb,co,ex);
    }
    printf("first polynomial:\n");
    display(&starta);
    printf("second polynomial:\n");
    display(&startb);
    printf("result:\n");
    addpoly();
    display(&start);
    
    return 0;
}
