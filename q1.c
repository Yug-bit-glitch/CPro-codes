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

node* merge(node*l1,node* l2){
if(l1==NULL)return l2;
if(l2==NULL)return l1;

node*start=malloc(sizeof(node));
node*tail=malloc(sizeof(node));

if(l1->val<=l2->val){
    start=l1;
    l1=l1->next;
}else{
    start=l2;
    l2=l2->next;
}
tail=start;
while((l1 != NULL)&&(l2 != NULL)){
if(l1->val<=l2->val){
    tail->next=l1;
    l1=l1->next;
}else{
    tail->next=l2;
    l2=l2->next;
}
tail=tail->next;
}
if(l1 != NULL){
    tail->next=l1;
}else{
    tail->next=l2;
}
return start;

}


int main(){
// input of t
int t;
scanf("%d",&t);

for(int i=0;i<t;i++){
// input of n,m
int n,m;
scanf("%d %d",&n,&m);

node *l1=NULL;
node *l2=NULL;

int i=0;
while(i<n){
    int s;
    scanf("%d ",&s);
    l1=insertatback(l1,s);
    i++;
}

int j=0;
while(j<m){
    int d;
    scanf("%d",&d);
   l2=insertatback(l2,d);
    j++;
}

node*l3=merge(l1,l2);

while(l3 != NULL){
    printf("%d ",l3->val);
    l3=l3->next;
}
printf("\n");
}
return 0;
}