#include<stdio.h>
#include<stdlib.h>

// defined a node with marks and pointer to the next node

typedef struct node{
int marks;
struct node*next;
}node;
// here since we are returning head we have to data type as node* as head is basically like a pointer to node*head
node*insertatstart(node*head,int data){
node*new=(node*)malloc(sizeof(node));
// checking if it malloced properly
if(new==NULL){
    printf("NOT POSSIBLE");
    return 0;
}
// defined a new node then adding the val into it
// then pointing its next to present head
// then updating present head to new
new->marks=data;
new->next=head;
head=new;
return head;
}

int main(){
    node*head=NULL;
   head=insertatstart(head,10);
   head=insertatstart(head,20);
   head=insertatstart(head,30);
   head=insertatstart(head,40);
   node*temp=head;
   while(temp != NULL){
    printf("%d\n",temp->marks);
    temp=temp->next;

   }
    return 0;
}
