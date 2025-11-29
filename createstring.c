struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    struct ListNode*new=malloc(sizeof(struct ListNode));
    new->next=head;
   struct ListNode*prev=new; 
    while((prev->next != NULL)&&(prev->next->next != NULL)){
     struct ListNode*first=prev->next;
     struct ListNode*second=first->next;
    
    if((first->val+second->val)==0){
        prev->next=prev->next->next->next;
    }
    prev=prev->next;
    }
return new->next;
}