/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
struct ListNode* temp=head;
int k=0;
while(temp!=NULL){
    k++;
    temp=temp->next;
    }
int result=0;
int high=k-1;
int count=0;
while((count<k)&&(head != NULL)&&(k>=0)){
   head=head->next;
   int h;
   head->val=h;
   result+=(h*pow(2,high));
   high--;
}
return result;
}
