/*
now the question is to remove a k th node given that the adress of kth node is provided not of head
the idea of the logic is to copy the data in the next element and delete the next node cause we copied the
data earlier
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

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
new->val=data;
new->next=head;
head=new;
return head;
}
node* deletek(node* l1){
    l1->val=(l1->next)->val;

}
int main(){








    return 0;
}






#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

node* insert_at_start(node *head, int data) {
    node *n = malloc(sizeof(*n));
    if (!n) return head; // allocation failed, return unchanged list
    n->val = data;
    n->next = head;
    return n;
}

/* Delete a node when only its address is given (not the head).
   Method: copy next node's data into this node, unlink and free next.
   Cannot delete the last node this way; caller must not pass the last node. */
void deletek(node *p) {
    if (!p || !p->next) return; // nothing to do (or cannot delete last node)
    node *next = p->next;
    p->val = next->val;
    p->next = next->next;
    free(next);
}

void print_list(node *h) {
    for (; h; h = h->next) {
        printf("%d", h->val);
        if (h->next) printf(" -> ");
    }
    printf("\n");
}

int main(void) {
    node *head = NULL;
    // build list 1->2->3->4->5
    for (int i = 5; i >= 1; --i) head = insert_at_start(head, i);

    printf("Original: ");
    print_list(head);

    // delete node with value 3 when we only have its address
    node *p = head->next->next; // points to value 3
    deletek(p); // list becomes 1->2->4->5

    printf("After deletek: ");
    print_list(head);

    // cleanup
    while (head) {
        node *t = head->next;
        free(head);
        head = t;
    }
    return 0;
}
