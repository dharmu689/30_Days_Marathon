/*
int loopInList(Node* head) {
    if (!head || !head->next) return 0;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int loopCount = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                temp = temp->next;
                loopCount++;
            }
            return loopCount;
        }
    }
    return 0;
}
*/