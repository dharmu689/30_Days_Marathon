
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

    // Adjust prev pointers
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
    
    // Adjust next pointers
    Node *temp = nodeX->next;
    nodeX->next = nodeY->next;
    nodeY->next = temp;

    // Adjust prev pointers of the next nodes (if they exist)
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

        // Memory cleanup (important!) -  Add this to avoid memory leaks
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr; // Reset head after cleanup

    }
    return 0;
}



/*

 *  struct Node {
 *    int data;
 *    Node *next;
 *    Node *prev;
 *  };
 *
 *  The above structure defines the linked list node.
 

Node* rearrangeList(Node* head) {
  // Write your code here
    
    if (!head || !head->next)
        return head;

    Node* evenStart = nullptr;
    Node* evenEnd = nullptr;
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;

    Node* curr = head;
    int pos = 1;

    while (curr != nullptr) {
        if (pos % 2 == 0) { // even position
            if (evenStart == nullptr) {
                evenStart = curr;
                evenEnd = evenStart;
            } else {
                evenEnd->next = curr;
                curr->prev = evenEnd;
                evenEnd = evenEnd->next;
            }
        } else { // odd position
            if (oddStart == nullptr) {
                oddStart = curr;
                oddEnd = oddStart;
            } else {
                oddEnd->next = curr;
                curr->prev = oddEnd;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
        pos++;
    }

    if (evenStart == nullptr || oddStart == nullptr)
        return head;

    // Connect the end of even list to the start of odd list
    evenEnd->next = oddStart;
    oddStart->prev = evenEnd;
    oddEnd->next = nullptr;

    return evenStart;
  
}
*/