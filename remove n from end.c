struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return head;
    }

    struct ListNode* temp = head;
    int count = 0;

    while (temp != NULL) {
        temp = temp->next;
        count++;
    }

    int a = count - n;

    if (a == 0) {
        struct ListNode* toDelete = head;
        head = head->next;
        free(toDelete);
        return head;
    }

    int i = 0;
    struct ListNode* new = head;

    while ((i < a - 1) && (new->next != NULL)) {
        new = new->next;
        i++;
    }

    if (new->next != NULL) {
        struct ListNode* toDelete = new->next;
        new->next = new->next->next;
        free(toDelete);
    }

    return head;
}
