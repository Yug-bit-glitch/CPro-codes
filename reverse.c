/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
 struct ListNode* prev=NULL;
 struct ListNode* curr=head;
 if(head == NULL){
    return head;
 }
 struct ListNode* new=head->next;

while(curr != NULL){
    new=curr->next;
    curr->next=prev;
    prev=curr;
    curr=new;
}
return prev;
}
