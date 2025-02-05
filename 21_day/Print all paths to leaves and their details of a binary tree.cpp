/* 
 *  struct Node {
 *    int data;
 *    Node *left, *right;
 *  };
 *
 *  The above structure defines a tree node.
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void findPaths(Node* root, vector<int> &path, int &totalPaths) {
    if (!root) return;

    // Add current node to path
    path.push_back(root->data);

    // Check if it's a leaf node
    if (!root->left && !root->right) {
        totalPaths++;
        for (int val : path) {
            cout << val << " ";
        }
        cout << path.size() - 1 << endl; // Print depth (number of edges in the path)
    }

    // Recur for left and right subtrees
    findPaths(root->left, path, totalPaths);
    findPaths(root->right, path, totalPaths);

    // Remove current node from path (backtracking)
    path.pop_back();
}

void printAllPaths(Node* root) {
    if (!root) return;

    vector<int> path;
    int totalPaths = 0;
    
    findPaths(root, path, totalPaths);

    // Print total number of paths
    cout << totalPaths << endl;
}

int main() {
    // Construct the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "All paths from root to leaves:" << endl;
    printAllPaths(root);

    return 0;
}




/* 
 *  struct Node {
 *    int data;
 *    Node *left, *right;
 *  };
 *
 *  The above structure defines a tree node.
 

#include <iostream>
#include <vector>
using namespace std;



void findPaths(Node* root, vector<int> &path, int &totalPaths) {
    if (!root) return;

    path.push_back(root->data);


    if (!root->left && !root->right) {
        totalPaths++;
        for (int val : path) {
            cout << val << " ";
        }
        cout << path.size() - 1 << endl; 
    }


    findPaths(root->left, path, totalPaths);
    findPaths(root->right, path, totalPaths);

    path.pop_back();
}

void printAllPaths(Node* root) {
    if (!root) return;

    vector<int> path;
    int totalPaths = 0;
    
    findPaths(root, path, totalPaths);

    // Print total paths
    cout << totalPaths << endl;
}

*/