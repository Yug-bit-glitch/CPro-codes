int strStr(char* haystack, char* needle) {
    int len1=strlen(haystack);

    int len2=strlen(needle);

for(int i=0;i<=len1-len2;i++){
    int start=i;
    int j=0;
    while((j<len2)&&(haystack[i+j]==needle[j])){
        j++;
    }
    if(j==len2){
        return start;
    }
}
return -1;
}



bool isPalindrome(char* s) {
    int len=strlen(s);
    int low=0;
    int high=len-1;

    while(low<high){
    if(isalnum(s[low])==0){
        low++;
        continue;
    }

     if(isalnum(s[high])==0){
        high--;
        continue;
    }

    // now tolower is used

    if(tolower(s[low])!= tolower(s[high])){
        return false;
    }
    high--;
    low++;
    }
    return true;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL){
        return head;
    }
    struct ListNode* temp=malloc(sizeof(struct ListNode));
    temp->next=head;
    struct ListNode* curr=temp;

    while(curr->next != NULL){
     if((curr->next)->val==val){
        curr->next=curr->next->next;
     }else{
        curr=curr->next;
     }
    }
    return temp->next;
    }

