#include <iostream>
#include <queue>
using namespace std;

class FullBinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function for preorder traversal (Root -> Left -> Right)
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for inorder traversal (Left -> Root -> Right)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for postorder traversal (Left -> Right -> Root)
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Insertion for full binary tree
    Node* insertFull(Node* root, int value) {
        if (!root) return new Node(value);

        // Queue to track nodes level by level
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            // Check left child
            if (temp->left == nullptr) {
                temp->left = new Node(value);
                break;
            } else if (temp->right == nullptr) {
                temp->right = new Node(value);
                break;
            } else {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return root;
    }

public:
    FullBinaryTree() : root(nullptr) {}

    // Insert function to enforce full binary structure
    void insert(int value) {
        root = insertFull(root, value);
    }

    // Preorder Traversal (Root -> Left -> Right)
    void preorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    // Inorder Traversal (Left -> Root -> Right)
    void inorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // Postorder Traversal (Left -> Right -> Root)
    void postorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    // Level-order (Breadth-First Search) Traversal for visual confirmation
    void levelOrder() {
        cout << "Level-order Traversal: ";
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
};

int main() {
    FullBinaryTree tree;

    // Insert nodes to maintain full binary tree
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    // Perform traversals
    tree.preorder();    // Should print: 1 2 4 5 3 6 7
    tree.inorder();     // Should print: 4 2 5 1 6 3 7
    tree.postorder();   // Should print: 4 5 2 6 7 3 1
    tree.levelOrder();  // Should print: 1 2 3 4 5 6 7

    return 0;
}
