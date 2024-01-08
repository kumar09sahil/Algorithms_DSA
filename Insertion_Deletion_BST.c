/* C program to implement insertion and deletion of an ITEM of information in a
BST. In this program  1. Create a binary search tree
2. Find the smallest element
3. Find the largest element
4. Search a node in the BST
5. Deleting a node from the BST
6. Inorder traversal
7. Exit prom the program */

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct tree *left;
struct tree *right;
};

struct node *createbst(struct node*root,int x)
{
    struct node*newnode,*temp=NULL,*p;
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=x;
        root->left=root->right=NULL;
        p=root;
    }
    else
    {
        p=root;
        while(p!=NULL)
        {
            if(x>p->data)
            {
                temp=p;
                p=p->right;
            }
            else if(x<p->data)
            {
                temp=p;
                p=p->left;
            }
            else
            return root;
            
        }

    
        if(x>temp->data)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=x;
            newnode->left=newnode->right=NULL; 
            temp->right=newnode;

        }
        else if(x<temp->data)
        {

            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=x;
            newnode->left=newnode->right=NULL; 
            temp->left=newnode;
        }
    }
    return root;
}

void inorder(struct node*root)
{
    struct node*p=root;
    if(p)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

struct node*smallestbst(struct node*root)
{
    struct node*t=root;
    if(t->left!=NULL)
    {
        t=smallestbst(t->left);
    }
    return t;
}

struct node*largestbst(struct node*root)
{
    struct node*t=root;
    if(t->right!=NULL)
    {
        t=largestbst(t->right);
    }
    return t;
}


void searchanodebst(struct node*root,int x)
{
    int addr=0;
    struct node*temp=root;
    while(temp)
    {
        addr++;
        if (x==temp->data)
        {
            printf("address of the element %d is at %d ",x,addr);
            return;
        }
        else if(x>temp->data)
        {
        temp=temp->right;
        }
        else if(x<temp->data)
        {
        temp=temp->left;
        }
        else
        printf("element not present");

    }    
}

 int height(struct node*p)
    {
        int x,y;
        if(p==NULL)
        return 0;
        x=height(p->left);
        y=height(p->right);
        return x>y?x+1:y+1;
    }
    struct node*inpredessor(struct node*p)
    {
        while(p&&p->right!=NULL)
        p=p->right;
        return p;
    }
     struct node*insuccessor(struct node*p)
    {
        while(p&&p->left!=NULL)
        p=p->left;
        return p;
    }
    struct node*deleteanodebst(struct node*p,int key)
    {
        struct node*p1=p;
        struct node*q;
        if(p==NULL)
        return NULL;
        if(p->left==NULL&&p->right==NULL)
        {
            if(p==p1)
            p=NULL;
            free(p);
            return NULL;
        }
        if(key<p->data)
        p->left=deleteanodebst(p->left,key);
        else if(key>p->data)
        p->right=deleteanodebst(p->right,key);
        else
        {
            if(height(p->left)>height(p->right))
            {
                q=inpredessor(p->left);
                p->data=q->data;
                p->left=deleteanodebst(p->left,q->data);
            }
            else
            {
                q=insuccessor(p->right);
                p->data=q->data;
                p->right=deleteanodebst(p->right,q->data);
            }
        }
      return p;
    }


int main()
{
struct node*ptr,*root=NULL;
int x,item;

do
{
printf("\n\n1. Create a binary search tree  \n");
printf("2. Find the smallest element   \n");
printf("3. Find the largest element    \n");
printf("4. Search a node in the BST  \n");
printf("5. Deleting a node from the BST  \n");
printf("6. Inorder traversal  \n");
printf("7. Exit prom the program  \n");
printf("Enter your option  \n");
scanf("%d", &x);
switch(x)
{
case 1: printf("Enter -1 to terminate  \n");
        printf("Enter the data item:  \n");
        scanf("%d",&item);
        while(item!=-1)
    {
        root=createbst(root,item);
        printf("Enter the data item:  ");
        scanf("%d",&item);
    }
        printf("Binary tree is created  \n");
        break;
case 2:
    ptr = smallestbst(root);
    printf("Smallest element is:%d",ptr->data);
    break;
case 3:
    ptr = largestbst(root);
    printf("Largest element is: %d",ptr->data);
    break;
case 4:
         printf("Which element you want to search ");
         scanf("%d",&item);
         searchanodebst(root,item);
         break;
case 5:
        printf("Which element you want to delete ");
        scanf("%d",&item);
        deleteanodebst(root,item);
        break;
case 6:
        if(root==NULL)
        printf("In-order Traversal: Binary tree is empty  \n");
        else
        {
            printf("In-order Traversal :  ");
            inorder(root);
            break;
        }
    
    break;
}
}while(x<=6);

return 0;

}

