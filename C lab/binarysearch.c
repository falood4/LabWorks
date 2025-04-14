#include<stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node * left;
  struct node * right;
}*root=NULL;
struct node * insert(struct node * ptr)
{
   int item,ch;
   if(ptr==NULL)
   {
     printf("\nEnter data to insert:");
     scanf("%d",&item);
     ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=item;
     ptr->left=NULL;
     ptr->right=NULL;
     return(ptr);
   }
   else
   {
    printf("\n1.Left of %d",ptr->data);
    printf("\n2.Right of %d",ptr->data);
    printf("\nEnter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
	ptr->left=insert(ptr->left);
	break;

       case 2:
	ptr->right=insert(ptr->right);
	break;
    }
   }
   return(ptr);
}
void inorder(struct node* a)
{
  if(a!=NULL)
  {
    inorder(a->left);
    printf("%d\t",a->data);
    inorder(a->right);
  }
}
void search(struct node *temp, int val)
{
    if (temp == NULL)
        printf("Item not found\n");
    else if (val == temp->data)
        printf("Item found\n");
    else if (val < temp->data)
        search(temp->left, val);
    else if (val > temp->data)
        search(temp->right, val);
}


void main()
{
 int ch, key;
  do
 {
   printf("\n1.insert");
   printf("\n2.inorder");
   printf("\n3.search");
   printf("\n4.exit");
   printf("\nEnter choice:");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:
	root=insert(root);
	break;
      case 2:
	{
          if(root==NULL)
          printf("\nTree Empty");
          else
	    inorder(root);
	    break;
      }
      case 3:
	    printf("\n enter value to search: ");	
	    scanf("%d",&key);
	    search(root, key);
	    break;
      case 4:
	exit(0);
   }
 }while(1);
}

