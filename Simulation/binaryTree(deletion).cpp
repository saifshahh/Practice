#include <iostream>
#include <queue>
using namespace std;

class CompleteBinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Level-order insertion to maintain complete structure
    void insertComplete(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            // Check left child
            if (!temp->left) {
                temp->left = newNode;
                break;
            } else {
                q.push(temp->left);
            }

            // Check right child
            if (!temp->right) {
                temp->right = newNode;
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    // Helper function to perform level-order traversal and delete the last node
    Node* deleteLastNode(Node* root, Node* lastNode) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            // Check and delete left child if it's the last node
            if (temp->left) {
                if (temp->left == lastNode) {
                    delete temp->left;
                    temp->left = nullptr;
                    return nullptr;
                } else {
                    q.push(temp->left);
                }
            }

            // Check and delete right child if it's the last node
            if (temp->right) {
                if (temp->right == lastNode) {
                    delete temp->right;
                    temp->right = nullptr;
                    return nullptr;
                } else {
                    q.push(temp->right);
                }
            }
        }
        return nullptr;
    }

    // Delete node function
    void deleteNode(int key) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);
        Node* keyNode = nullptr;
        Node* lastNode = nullptr;

        // Find the node to delete and the last node
        while (!q.empty()) {
            lastNode = q.front();
            q.pop();

            if (lastNode->data == key) keyNode = lastNode;

            if (lastNode->left) q.push(lastNode->left);
            if (lastNode->right) q.push(lastNode->right);
        }

        // If keyNode exists, replace it with the last node's data and delete the last node
        if (keyNode != nullptr) {
            keyNode->data = lastNode->data;
            deleteLastNode(root, lastNode);
            cout << "Node Deleted!" << endl;
        } else {
            cout << "Node not found!" << endl;
        }
    }

    // Preorder traversal for displaying tree
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

public:
    CompleteBinaryTree() : root(nullptr) {}

    void insert(int value) {
        insertComplete(value);
    }

    void deleteValue(int value) {
        deleteNode(value);
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }
};

int main() {
    CompleteBinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);

    cout << "Preorder Traversal before deletion: ";
    tree.preorder();

    tree.deleteValue(3);

    cout << "Preorder Traversal after deletion: ";
    tree.preorder();

    return 0;
}
