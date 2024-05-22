#include <iostream>
#include <queue>

using namespace std;
struct node{
    int value;
    node *left;
    node *right;
    int height;

    node(int value){
        this->value = value;
        left = right = nullptr;
        this->height = 1;
    }
};

void level(node *root){
    if (root == nullptr) {
        return ;
    }
    queue<node*> queue;
    queue.push(root);
    int level = 1;
    while (!queue.empty()) {
        int levelSize = queue.size();
        cout << "Level" << level++ << " - nodes: " << levelSize << " -> Nodes: ";

        for (int i = 0; i < levelSize; ++i) {
            node *current = queue.front();
            queue.pop();
            cout << current->value << " ";
            if (current->left) queue.push(current->left);
            if (current->right) queue.push(current->right);
        }
        cout << endl;
    }
}

void preorder(node *root){
    cout << "\n";
    if(root != nullptr){
        cout << root->value << "->" ;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root){
    cout << "\n";
    if(root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout << root->value << "->" ;

    }
}


int height(node *root){
    if(root != nullptr){
        return root->height;
    }
    return 0;
}

int getBalance(node *root){
    if(root == nullptr){
        return 0;
    }
    return height(root->left) - height(root->right);
}


node* leftRotate(node *x){
    node* y = x->right;
    node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // return the new root
    return y;
}

node* rightRotate(node *x){
    node* y = x->left;
    node* t2 = y->right;

    y->right = x;
    x->left = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // return the new root
    return y;
}

node* insert(node *root, int value){
    if(root == nullptr){
        return new node(value);
    }else if(root->value > value){
        root->left = insert(root->left, value);
    }else if(root->value < value){
        root->right = insert(root->right, value);
    }

    root->height = 1 + std::max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if(balance > 1 && root->left->value > value ){
        root = rightRotate(root);
    }else if(balance > 1 &&  root->left->value < value ){
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }else if(balance < -1 && root->right->value < value ){
        root = leftRotate(root);
    }else if(balance < -1 && root->right->value > value){
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;
}

node *minValue(node *root){
    node *current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}

node *deleteNode(node *root, int value){
    if (root == nullptr) {
        cout << "No such value\n";
        return root;
    }else if(root->value > value){
        root->left = deleteNode(root->left, value);
    }else if(root->value < value){
        root->right = deleteNode(root->right, value);
    }else{
        if ((root->left == nullptr) || (root->right == nullptr)) {
            node *temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        }else{
            node *temp = minValue(root->right);
            root->value = temp->value;
            deleteNode(root->right, temp->value);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0  ){
        return rightRotate(root);
    }else if(balance > 1 &&  getBalance(root->left) < 0 ){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }else if(balance < -1 && getBalance(root->right) <= 0 ){
        return  leftRotate(root);
    }else if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return  leftRotate(root);
    }
    return root;
}



int main(){
    int arr[] = {8,9,10,2,1,5,3,6,4,7,11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    node *root = nullptr;
    for(int i = 0; i < n; i++){
        root = insert(root, arr[i]);
    }

    cout << "AVL Tree after Insertion: ";
    level(root);
    cout << endl;

    deleteNode(root, 11);
    cout << "Delete Right Lonely child" << endl ;
    level(root);
    cout << endl;

    deleteNode(root, 2);
    cout << "Delete Left lonely child" << endl ;
    level(root);
    cout << endl;


    deleteNode(root, 12);
    cout << "Delete Lonely" << endl ;
    level(root);
    cout << endl;


    deleteNode(root, 5);
    cout << "Delete Root" << endl ;
    level(root);
    cout << endl;
}