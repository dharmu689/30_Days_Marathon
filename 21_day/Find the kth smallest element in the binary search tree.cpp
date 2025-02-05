#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to perform in-order traversal
void inOrder(Node* root, int &k, int &result) {
    // Base case
    if (root == nullptr || k == 0) {
        return;
    }

    // Traverse the left subtree
    inOrder(root->left, k, result);

    // Visit the current node
    k--;  // Decrease k each time we visit a node
    if (k == 0) {
        result = root->data;  // Found the kth smallest
        return;
    }

    // Traverse the right subtree
    inOrder(root->right, k, result);
}

// Main function to find the kth smallest element in BST
int kSmallest(Node* root, int k) {
    // Validate k
    if (k <= 0) {
        return -1;  // Invalid k, return -1 (or handle as needed)
    }

    int result = 0;
    inOrder(root, k, result);  // Start in-order traversal
    return result;
}

// Sample usage for testing
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(8);

    int k1 = 4;
    int k2 = 6;

    cout << "The 4th smallest element is " << kSmallest(root, k1) << endl; // Output: 4
    cout << "The 6th smallest element is " << kSmallest(root, k2) << endl; // Output: 7

    return 0;
}




/*void inOrder(Node* root, int &k, int &result) {
    // Base case
    if (root == nullptr || k == 0) {
        return;
    }

    // Traverse the left subtree
    inOrder(root->left, k, result);

    // Visit the current node
    k--;  // Decrease k each time we visit a node
    if (k == 0) {
        result = root->data;  // Found the kth smallest
        return;
    }

    // Traverse the right subtree
    inOrder(root->right, k, result);
}

int kSmallest(Node* root, int k) {
    // Validate k
    if (k <= 0) {
        return 0 ;  // Invalid k, return -1 (or handle as needed)
    }

    int result = 0;
    inOrder(root, k, result);  // Start in-order traversal
    return result;
}
*/