#include <iostream>
using namespace std;

// Definition for a tree node
struct Node {
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node in BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Function to find the Lowest Common Ancestor (LCA)
int lowestCommonAncestor(Node* root, int k1, int k2) {
    if (root == nullptr) 
        return -1; // Return -1 for an empty tree

    // If both nodes are smaller, LCA is in the left subtree
    if (k1 < root->data && k2 < root->data)
        return lowestCommonAncestor(root->left, k1, k2);

    // If both nodes are larger, LCA is in the right subtree
    if (k1 > root->data && k2 > root->data)
        return lowestCommonAncestor(root->right, k1, k2);

    // If one key is on the left and the other is on the right, the root is the LCA
    return root->data;
}

// Function to build BST from level order input
Node* buildBST(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) // -1 represents a NULL node
            root = insert(root, arr[i]);
    }
    return root;
}

// Driver Code
int main() {
    int n;
    cout << "Enter number of nodes in BST: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in level order (-1 for NULL): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildBST(arr, n);

    int k1, k2;
    cout << "Enter two nodes to find LCA: ";
    cin >> k1 >> k2;

    int lca = lowestCommonAncestor(root, k1, k2);
    cout << "Lowest Common Ancestor: " << lca << endl;

    return 0;
}



/* 
 *  struct Node {
 *    int data;
 *    Node *left, *right;
 *  };
 *
 *  The above structure defines a tree node.
 
 int lowestCommonAncestor(Node* root, int k1, int k2) {
    // Write your code here
      if (root == nullptr) 
          return -1; 
   
      if (k1 < root->data && k2 < root->data)
          return lowestCommonAncestor(root->left, k1, k2);
   
      if (k1 > root->data && k2 > root->data)
          return lowestCommonAncestor(root->right, k1, k2);
   
      return root->data;
    
  }

*/