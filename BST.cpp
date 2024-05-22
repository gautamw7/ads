#include<iostream>
#include <queue>
using namespace std;

struct node {
    int value;
    node *left;
    node *right;

    explicit node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* insert(node *root, int value) {
    if (root == nullptr) {
        return new node(value);
    } else if (root->value > value) {
        root->left = insert(root->left, value);
    } else if (root->value < value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorderTraversal(node *root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(node *root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(node *root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->value << " ";
    }
}

node *minValue(node *root){
    node* current = root;
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
        if((root->left == nullptr) || (root->right == nullptr)) {
            node *temp = root->left ? root->left : root->right;

            // no children.
            if(temp == nullptr){
                temp = root;
                root = nullptr;
            }else{
                *root = *temp;
            }
            delete temp;
        }else{
            node *current = minValue(root->right);
            root->value = current->value;
            root->right = deleteNode(root->right, current->value);
        }
    }
    return root;
}

int height(node *root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

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

node *mirror(node *root){
    if (root == nullptr)
        return nullptr;
    node *temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);

    return root;
}

int main() {
    node *root = nullptr;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

/*
    cout << "Height :" << height(root) << endl;
*/
/*    level(root);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    // Mirror Image
    root = mirror(root);*/

/*    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;
    level(root);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;*/

    root = deleteNode(root, 2);
    cout << "Inorder traversal after deletions: ";
    inorderTraversal(root);
    cout << endl;
    root = deleteNode(root, 3);
    cout << "Inorder traversal after deletions: ";
    inorderTraversal(root);
    cout << endl;
    root = deleteNode(root, 5);
    cout << "Inorder traversal after deletions: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
