#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree {
public:
    // Nested Node struct within AVLTree
    struct Node {
        int data, height;
        Node* left_node;
        Node* right_node;
        Node(int val) : data(val), height(1), left_node(nullptr), right_node(nullptr) {}
    };

    Node* root;

    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Get the height of a node
    int get_height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Get the balance factor of a node
    int get_balance_factor(Node* node) {
        if (node == nullptr)
            return 0;
        return get_height(node->left_node) - get_height(node->right_node);
    }

    // Right rotation (LL case)
    Node* LL_rotation(Node* node) {
        Node* child = node->left_node;
        node->left_node = child->right_node;
        child->right_node = node;

        node->height = max(get_height(node->left_node), get_height(node->right_node)) + 1;
        child->height = max(get_height(child->left_node), get_height(child->right_node)) + 1;

        return child;
    }

    // Left rotation (RR case)
    Node* RR_rotation(Node* node) {
        Node* child = node->right_node;
        node->right_node = child->left_node;
        child->left_node = node;

        node->height = max(get_height(node->left_node), get_height(node->right_node)) + 1;
        child->height = max(get_height(child->left_node), get_height(child->right_node)) + 1;

        return child;
    }

    // Insert a new node
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data) {
            node->left_node = insert(node->left_node, val);
        } else if (val > node->data) {
            node->right_node = insert(node->right_node, val);
        } else {
            return node; // Duplicate values not allowed
        }

        node->height = max(get_height(node->left_node), get_height(node->right_node)) + 1;
        int balance = get_balance_factor(node);

        // Balancing the tree
        // Left-Left (LL) case
        if (balance > 1 && val < node->left_node->data)
            return LL_rotation(node);

        // Right-Right (RR) case
        if (balance < -1 && val > node->right_node->data)
            return RR_rotation(node);

        // Left-Right (LR) case
        if (balance > 1 && val > node->left_node->data) {
            node->left_node = RR_rotation(node->left_node);
            return LL_rotation(node);
        }

        // Right-Left (RL) case
        if (balance < -1 && val < node->right_node->data) {
            node->right_node = LL_rotation(node->right_node);
            return RR_rotation(node);
        }

        return node;
    }

    // In-order traversal
    void in_order(Node* node) {
        if (node != nullptr) {
            in_order(node->left_node);
            cout << node->data << " ";
            in_order(node->right_node);
        }
    }

    // Find the in-order successor (smallest value in the right subtree)
    Node* min_value_node(Node* node) {
        Node* current = node;
        while (current->left_node != nullptr)
            current = current->left_node;
        return current;
    }

    // Delete a node
    Node* delete_node(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->data) {
            root->left_node = delete_node(root->left_node, key);
        } else if (key > root->data) {
            root->right_node = delete_node(root->right_node, key);
        } else {
            // Node with only one child or no child
            if ((root->left_node == nullptr) || (root->right_node == nullptr)) {
                Node* temp = root->left_node ? root->left_node : root->right_node;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp; // Copy the contents of the non-empty child
                }
                delete temp;
            } else {
                // Node with two children
                Node* temp = min_value_node(root->right_node);
                root->data = temp->data;
                root->right_node = delete_node(root->right_node, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        root->height = max(get_height(root->left_node), get_height(root->right_node)) + 1;
        int balance = get_balance_factor(root);

        // Balancing the tree
        // Left-Left (LL) case
        if (balance > 1 && get_balance_factor(root->left_node) >= 0)
            return LL_rotation(root);

        // Left-Right (LR) case
        if (balance > 1 && get_balance_factor(root->left_node) < 0) {
            root->left_node = RR_rotation(root->left_node);
            return LL_rotation(root);
        }

        // Right-Right (RR) case
        if (balance < -1 && get_balance_factor(root->right_node) <= 0)
            return RR_rotation(root);

        // Right-Left (RL) case
        if (balance < -1 && get_balance_factor(root->right_node) > 0) {
            root->right_node = LL_rotation(root->right_node);
            return RR_rotation(root);
        }

        return root;
    }
};

int main() {
    AVLTree tree;

    // Insert elements
    tree.root = tree.insert(tree.root, 17);
    tree.root = tree.insert(tree.root, 18);
    tree.root = tree.insert(tree.root, 19);
    tree.root = tree.insert(tree.root, 11);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 16);

    // In-order traversal before deletion
    cout << "In-order Traversal of the AVL Tree before deletion: ";
    tree.in_order(tree.root);
    cout << endl;

    // Delete a node
    tree.root = tree.delete_node(tree.root, 18);

    // In-order traversal after deletion
    cout << "In-order Traversal of the AVL Tree after deletion: ";
    tree.in_order(tree.root);
    cout << endl;

    return 0;
}
