#include <bits/stdc++.h>
using namespace std;

class Table{
    public:
    int ID;
    string name;
    int age;

    Table(int ID = 0, string name= "", int age= 0) : ID(ID), name(name), age(age) {}
};

class BST{
    public:
    Table keys;
    BST* left;
    BST* right;

    BST(int ID = 0, string name = 0, int age = 0){ 
        keys = Table(ID, name, age);
        left = nullptr;
        right = nullptr;
    }

    BST(Table key){
        keys = key;
        left = nullptr;
        right = nullptr;
    }
   
    void insert(BST*& node, Table key){
        if(!node){
            node = new BST(key);
            return;
        }
        if(node->keys.ID == key.ID) return;
        if(node->keys.ID < key.ID) insert(node->right, key);
        else insert(node->right,key);
    }

    BST* getMinValueNode(BST* root){
        BST* temp = root;
        while(temp && temp->left){
            temp = temp->left;
        }
        return temp;
    }
    void delNode(BST*& root, int id){
        if(!root) return;

        if(root->keys.ID > id) delNode(root->left, id);
        else if(root->keys.ID < id) delNode(root->right, id);
        else{
            if(!root->left){ 
                BST* temp = root;
                root = root->right;
                delete temp;
                return;
            }
            if(!root->right){ 
                BST* temp = root;
                root = root->left;
                delete temp;
                return;
            }

            BST* temp = getMinValueNode(root->right);
            root->keys = temp->keys;
            delNode(root->right, temp->keys.ID);
        }
    }

    void search(BST* root, int id){
        if(!root){
            cout << "The id is not found in the record" << endl;
            return;
        }

        if(root->keys.ID == id){
            cout << "The id is found" << endl;
            cout << "ID: " << root->keys.ID << " name: " << root->keys.name << " age: " << root->keys.age << endl;     
        }

        if(root->keys.ID < id) search(root->right, id);
        else search(root->left, id);
    }

};

class AVL{
    public:
    int height;
    Table keys;
    AVL* left;
    AVL* right;

    AVL(int id = 0, string name = "", int age=0){
        keys = Table(id, name, age);
        left = nullptr;
        right = nullptr;
        height = 1;
    }
    AVL(Table key){
        keys = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }

    void updateHeight(AVL*& node){
        if(node){
            int leftHeight = (node->left) ? node->left->height : 0;
            int rightHeight = (node->right) ? node->right->height : 0;
            node->height = 1 + max(node->left->height, node->right->height);
        }
    }

    void rightRotate(AVL*& root){
        if (!root || !root->left) return;
        AVL* temp = root->left;
        root->left = temp->right;
        temp->right = root;
        updateHeight(root);
        updateHeight(temp);
        root = temp;
    }

    void leftRotate(AVL*& root){
        if (!root || !root->left) return;
        AVL* temp = root->right;
        root->right = temp->left;
        temp->left = root;
        updateHeight(root);
        updateHeight(temp);
        root = temp;
    }

    int getHeight(AVL* root){
        return root ? root->height : 0;
    }
    int getBalanceFactor(AVL* root){
        return root ? getHeight(root->left) - getHeight(root->right): 0;
    }
    void insert(AVL*& root, Table key){
        if(!root){
            root = new AVL(key);
            return;
        }

        if(root->keys.ID < key.ID){
            insert(root->right, key);
        }else if(root->keys.ID > key.ID){
            insert(root->left, key);
        }else{
            cout << "ID already exists" << endl;
        }


        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);


        if(balance > 1){
            if(key.ID < root->left->keys.ID){
                rightRotate(root);
            }else{
                leftRotate(root->left);
                rightRotate(root);
            }
        }else if(balance < -1){
            if(key.ID > root->right->keys.ID){
                leftRotate(root);
            }else{
                rightRotate(root->right);
                leftRotate(root);
            }
        }
    }

    AVL* search(AVL* root, int ID) {
        if (!root || root->keys.ID == ID) {
            return root;
        }
    
        if (ID < root->keys.ID) {
            return search(root->left, ID);
        }
    
        return search(root->right, ID);
    }


    AVL* minValueNode(AVL* root){
        AVL* current = root;
        while(current->left != NULL){
            current = current->left;
        }
        return current;
    }
    void deleteNode(AVL*& root, int ID){
        if(!root)
            return;

        if(ID < root->keys.ID){
            deleteNode(root->left, ID);
        }else if(ID > root->keys.ID){
            deleteNode(root->right, ID);
        }else{
            if(!root->left || !root->right){
                AVL* temp = root->left ? root->left : root->right;

                if(!temp){
                    temp = root;
                    root = nullptr;
                }else{
                    *root = *temp;
                }
            }else{
                AVL* temp = minValueNode(root->right);
                root->keys = temp->keys;
                deleteNode(root->right, temp->keys.ID);
            }
        }

        if(!root)
            return;

        updateHeight(root);

        int balance = getBalanceFactor(root);

        if(balance > 1 && root->left){
            if(root->left->keys.ID >= ID){
                rightRotate(root);
                return;
            }else{
                leftRotate(root->left);
                rightRotate(root);
            }
        }

        if(balance < -1 && root->right){
            if(root->right->keys.ID <= ID){
                leftRotate(root);
                return;
            }else{
                rightRotate(root->right);
                leftRotate(root);
                return;
            }
        }
    }
};
 
class BTreeNode {
public:
    vector<Table> keys;                
    vector<BTreeNode*> children;       
    int minDegree;                     
    bool isLeaf;                       

    BTreeNode(int minDegree, bool isLeaf) {
        this->minDegree = minDegree;
        this->isLeaf = isLeaf;
        keys.reserve(2 * minDegree - 1);   
        children.reserve(2 * minDegree);  
    }

    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!isLeaf) children[i]->traverse();
            cout << "ID: " << keys[i].ID << " Name: " << keys[i].name << " Age: " << keys[i].age << endl;
        }

        if (!isLeaf)
            children[i]->traverse();
    }

    void insertNonFull(const Table& key) {
        int i = keys.size() - 1;

        if (isLeaf) {

            keys.push_back(key);
            while (i >= 0 && keys[i].ID > key.ID) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
        } else {
            while (i >= 0 && keys[i].ID > key.ID) {
                i--;
            }

            if (children[i + 1]->keys.size() == 2 * minDegree - 1) {
                splitChild(i + 1, children[i + 1]);

                if (keys[i + 1].ID < key.ID)
                    i++;
            }
            children[i + 1]->insertNonFull(key);
        }
    }

    void splitChild(int i, BTreeNode* childToSplit) {
    
        BTreeNode* newSibling = new BTreeNode(childToSplit->minDegree, childToSplit->isLeaf);
        newSibling->keys.resize(minDegree - 1);

        for (int j = 0; j < minDegree - 1; j++) {
            newSibling->keys[j] = childToSplit->keys[j + minDegree];
        }

        if (!childToSplit->isLeaf) {
            newSibling->children.resize(minDegree);
            for (int j = 0; j < minDegree; j++) {
                newSibling->children[j] = childToSplit->children[j + minDegree];
            }
        }
        childToSplit->keys.resize(minDegree - 1);

        children.insert(children.begin() + i + 1, newSibling);

        keys.insert(keys.begin() + i, childToSplit->keys[minDegree - 1]);
    }

    friend class BTree;
};

class BTree {
public:
    BTreeNode* root; 
    int minDegree;    

    BTree(int degree) {
        root = nullptr;
        minDegree = degree;
    }

    void insert(const Table& key) {
        if (!root) {
            root = new BTreeNode(minDegree, true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == 2 * minDegree - 1) {
                BTreeNode* newRoot = new BTreeNode(minDegree, false);

                newRoot->children.push_back(root);

                newRoot->splitChild(0, root);

                if (key.ID > newRoot->keys[0].ID) {
                    newRoot->children[1]->insertNonFull(key);
                } else {
                    newRoot->children[0]->insertNonFull(key);
                }

                root = newRoot;
            } else {
                root->insertNonFull(key);
            }
        }
    }

    void traverse() {
        if (root)
            root->traverse();
    }
};

template <typename TreeType>
void insert1000(TreeType*& tree){
    auto start = chrono::high_resolution_clock::now();
    if(!tree)
        tree = nullptr;

    for(int i=1; i <= 1000; i++){
        Table key = {i, "n",(3*i+3)/2};
        if constexpr (is_same<TreeType, BTree>::value)
            tree->insert(key);
        else
            tree->insert(tree, key);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken for 1000 insertions: " << duration.count() << " milliseconds" << endl;
}

template <typename TreeType>
void insert10000(TreeType*& tree){
    auto start = chrono::high_resolution_clock::now();
    if(!tree)
        tree = nullptr;

    for(int i=1001; i <= 11001; i++){
        Table key = {i, "n",(3*i+3)/2};
        if constexpr (is_same<TreeType, BTree>::value)
            tree->insert(key);
        else
            tree->insert(tree, key);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken for 10000 insertions: " << duration.count() << " milliseconds" << endl;
}

template <typename TreeType>
void insert50000(TreeType*& tree){
    auto start = chrono::high_resolution_clock::now();
    if(!tree)
        tree = nullptr;

    for(int i=11001; i <= 61001; i++){
        Table key = {i, "n",(3*i+3)/2};
        if constexpr (is_same<TreeType, BTree>::value)
            tree->insert(key);
        else
            tree->insert(tree, key);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken for 50000 insertions: " << duration.count() << " milliseconds" << endl;
}

template <typename TreeType>
void inorder(TreeType* node){
    if(!node)
        return; 
   
        inorder(node->left);
        cout << "ID: " << node->keys.ID << " name: " << node->keys.name << " age: " << node->keys.age << endl; 
        inorder(node->right);
}

int main(){

    BST* bst = nullptr;
    cout << "BST Inserting: " << endl;
    insert1000(bst);
    insert10000(bst);
    insert50000(bst);

    cout << "\nInorder traversal BST: " << endl;
    inorder(bst);

    bst->delNode(bst, 5);
    cout << "\nInorder traversal of BST after deletion: " << endl;
    inorder(bst);

    cout << "\nAvl Insertion: " << endl;
    AVL* avl = nullptr;
    insert1000(avl);
    insert10000(avl);
    insert50000(avl);

    cout << "\nInorder Traversal of AVL: " << endl;
    inorder(avl);

    avl->deleteNode(avl, 3);
    avl->deleteNode(avl, 4);
    cout << "\nInorder Traversal of AVL after deletion: " << endl;
    inorder(avl);

    int keyToSearch = 20;
    AVL* result = search(root, keyToSearch);

    cout << "\nB-Tree Insertion: " << endl;
    BTree *btree = new BTree(4);

    insert1000(btree);
    insert10000(btree);
    insert50000(btree);

    btree->traverse();
}
