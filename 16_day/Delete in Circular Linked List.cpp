/*
 struct Node* deleteBeg(struct Node* head) {
    if (!head) return NULL;
    if (head->next == head) {
        free(head);
          return NULL;
    }
    struct Node* temp = head;
    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    head = head->next;
    tail->next = head;
    free(temp);
    return head;
 }
 struct Node* deleteEnd(struct Node* head) {
    if (!head) return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
 }
*/