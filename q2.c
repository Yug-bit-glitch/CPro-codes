
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int val;
    struct node *next;
}node;

node* insertatback(node*head,int data){
node*new=(node*)malloc(sizeof(node));
if(new==NULL){
    printf("NULL\n");
    return head;
}
new->marks=data;
new->next=NULL;

   if(head==NULL){
    head=new;
   }
   else{
    node*temp=head;
    while(temp->next != NULL){
        temp=temp->next;

    }
    temp->next=new;
   }
   return head;
}

int main(){
   int t;
   scanf("%d",&t);


   for(int i=0;i<t;i++){

    int n,q;
    scanf("%d %d",&n,&q);

    node*l=NULL;

    int i=0;
    while(i<n){
    int s;
    insertatback(l,s);
    }

  for(int i=0;i<q;i++){
   
    int y;
    scanf("%d",&y);

    if(y==1){
        int x;
        scanf("%d",&x);
        node*temp=l;
        while(temp != NULL){
            temp=temp->next;
        }
        temp->val+x;
    }




  }
    


   }

    return 0;
}

