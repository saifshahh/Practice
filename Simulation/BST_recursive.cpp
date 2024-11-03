#include <iostream>
using namespace std;

class BST{

    private:

    struct Node{
        int data;
        Node* left;
        Node* right;

        Node(int data=0) : data(data), left(nullptr), right(nullptr) {}
    };

    void preorder(Node *root){
        if(root==nullptr) return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root){
        if(root==nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    void inorder(Node *root){
        if(root==nullptr) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    Node* insertion(Node* root, int value){
        if(root == nullptr) return new Node(value);
        if(value < root->data) root->left = insertion(root->left, value);
        else if(value > root->data) root->right = insertion(root->right, value);
        return root;
    }

    bool searching(Node* node, int key){
        if(node == nullptr) return false;
        if(node->data == key) return true;
        if(key < node->data) return searching(node->left, key);
        return searching(node->right, key);
    }

    Node* minNode(Node* node){
        while(node && node->left != NULL) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int value){
        if(root == nullptr) return root;
        if(root->data < value) root->right = deleteNode(root->right, value);
        else if(root->data > value) root->left = deleteNode(root->left, value);
        else{
            if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node* temp = minNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data); 
            }
        }
        return root;
    }

    public:
    
    Node *root;
    BST(): root(nullptr) {}

    void insert(int value){
        root = insertion(root, value);
    }

    void search(int key){
        bool flag = searching(root, key);
        if(flag) cout<<"\nElement Found!"<<endl;
        else cout<<"\nElement Not Found!"<<endl;  
    }

    void deleteNode(int key){
        Node* toDelete = deleteNode(root, key);
        if(toDelete) cout<<"Node Deleted!"<<endl;
        else cout<<"Such node doesnt exsist in the tree!"<<endl;
    }

    void inorder(){ inorder(root); }
    void postorder(){ postorder(root); }
    void preorder(){ preorder(root); }

};

int main(){
    BST tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);

    tree.preorder();
    cout<<endl;
    tree.postorder();
    cout<<endl;
    tree.inorder();

    tree.search(3);

    tree.deleteNode(3);
    tree.preorder();
    cout<<endl;
    tree.postorder();
    cout<<endl;
    tree.inorder();
    
}
