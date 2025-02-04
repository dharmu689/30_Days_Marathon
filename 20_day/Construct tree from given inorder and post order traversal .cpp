#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to create a new tree node
Node* newNode(int data) {
    return new Node(data);
}

// Helper function to construct the binary tree
Node* buildTreeUtil(int in[], int post[], int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = post[postIndex--];
    Node* root = newNode(rootVal);

    int inIndex = inMap[rootVal];

    root->right = buildTreeUtil(in, post, inIndex + 1, inEnd, postIndex, inMap);
    root->left = buildTreeUtil(in, post, inStart, inIndex - 1, postIndex, inMap);

    return root;
}

// Main function to build the tree
Node* buildTree(int in[], int post[], int N) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < N; i++) {
        inMap[in[i]] = i;
    }

    int postIndex = N - 1;
    return buildTreeUtil(in, post, 0, N - 1, postIndex, inMap);
}

// Function to print the tree using preorder traversal
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Example usage (for testing):
int main() {
    int N = 6;
    int in[] = {4, 2, 5, 1, 6, 3};
    int post[] = {4, 5, 2, 6, 3, 1};

    Node* root = buildTree(in, post, N);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}


/* 
 *  struct Node {
 *    int data;
 *    Node *left, *right;
 *  };
 *  The above structure defines a tree node.
 *
 *  The function below is also provided to build a new node with the given data.
 *    Node* newNode(int data);
 
Node* buildTreeUtil(int in[], int post[], int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = post[postIndex--];
    Node* root = newNode(rootVal);

    int inIndex = inMap[rootVal];

    root->right = buildTreeUtil(in, post, inIndex + 1, inEnd, postIndex, inMap);
    root->left = buildTreeUtil(in, post, inStart, inIndex - 1, postIndex, inMap);

    return root;
}

Node* buildTree(int in[], int post[], int N) {
  // Write your code here
  
    unordered_map<int, int> inMap;
    for (int i = 0; i < N; i++) {
        inMap[in[i]] = i;
    }

    int postIndex = N - 1;
    return buildTreeUtil(in, post, 0, N - 1, postIndex, inMap);
}

// Function to print the tree using preorder traversal
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
    
}
*/