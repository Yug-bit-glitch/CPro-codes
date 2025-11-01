#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node*next;
}node;

int main(){
// code wriitten as logic to implement the sum two numbers whose digits are two linked lists
//creating a dummy head as we need to kind of reverse it
node*dummy=malloc(sizeof(node));
// curr points to dummy head
node*curr=dummy;
// we are implementing addition from lsb (initial carry assumed=0)
int carry=0;
while(l1 != NULL || l2 != NULL || carry !=0){
    // we would also check whether l1/l2 is null as no of digits can be different
    int sum=carry;
    if(l1 != NULL){
        sum += l1->val;
        l1->next;
    }
    if(l2 != NULL){
        sum += l2->val;
        l2->next;
    }
    carry=sum/10;
     
    node* sum=malloc(sizeof(node));
    sum->val=sum % 10;

    curr->next=sum;
    curr=curr->next;

}
node*result=dummy->next;
free(dummy);
return result;
    return 0;
}