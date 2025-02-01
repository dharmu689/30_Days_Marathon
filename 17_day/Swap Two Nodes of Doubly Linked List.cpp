
#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node* swapNodes(Node* head, int x, int y) {
    if (x == y) return head; // No need to swap if values are the same

    Node *nodeX = nullptr, *nodeY = nullptr;
    Node *curr = head;

    // Find the nodes with data x and y
    while (curr != nullptr) {
        if (curr->data == x) nodeX = curr;
        if (curr->data == y) nodeY = curr;
        curr = curr->next;
    }

    // If either node is not found, return the original list
    if (nodeX == nullptr || nodeY == nullptr) return head;

    // Swap the nodes
    if (nodeX->prev != nullptr) {
        nodeX->prev->next = nodeY;
    } else {
        head = nodeY; // If nodeX was the head, update the head
    }
    if (nodeY->prev != nullptr) {
        nodeY->prev->next = nodeX;
    } else {
        head = nodeX; // If nodeY was the head, update the head
    }

    Node *temp = nodeX->next;
    nodeX->next = nodeY->next;
    nodeY->next = temp;

    if (nodeX->next != nullptr) nodeX->next->prev = nodeX;
    if (nodeY->next != nullptr) nodeY->next->prev = nodeY;

    nodeX->prev = nodeY->prev;
    nodeY->prev = nodeX->prev;

    return head;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        Node *head = nullptr, *tail = nullptr;
        for (int i = 0; i < n; i++) {
            int data;
            std::cin >> data;
            Node *newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            if (head == nullptr) {
                head = newNode;
                newNode->prev = nullptr;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        int x, y;
        std::cin >> x >> y;
        head = swapNodes(head, x, y);
        while (head != nullptr) {
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
    return 0;
}
/*
if (x == y)
        return head;

    // Search for x (keep track of previous and current node)
    Node* prevX = nullptr;
    Node* currX = head;
    while (currX != nullptr && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y (keep track of previous and current node)
    Node* prevY = nullptr;
    Node* currY = head;
    while (currY != nullptr && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, return head
    if (currX == nullptr || currY == nullptr)
        return head;

    // If x is not head of the linked list
    if (prevX != nullptr)
        prevX->next = currY;
    else // Make y the new head
        head = currY;

    // If y is not head of the linked list
    if (prevY != nullptr)
        prevY->next = currX;
    else // Make x the new head
        head = currX;

    // Swap next pointers
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    // Swap prev pointers
    if (currX->next != nullptr)
        currX->next->prev = currX;
    if (currY->next != nullptr)
        currY->next->prev = currY;

    temp = currX->prev;
    currX->prev = currY->prev;
    currY->prev = temp;

    return head;
    
}
*/