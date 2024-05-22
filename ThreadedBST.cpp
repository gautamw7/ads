#include<iostream>
using namespace std;

// Definition of a node in the threaded binary search tree
struct node {
    int value;
    node *left, *right;
    bool rightThread;

    // Constructor to initialize a node
    node(int data) {
        value = data;
        left = right = nullptr;
        rightThread = false;
    }
};

class ThreadedBST {
private:
    node *root;

    // Helper function to insert a value into the tree
    node* insert(node* root, int value) {
        if (root == nullptr) {
            return new node(value); // Create a new node if tree is empty
        }

        node *parent = nullptr;
        node *current = root;

        // Traverse the tree to find the correct insertion point
        while (current != nullptr) {
            parent = current;
            if (current->value == value) {
                return root; // No duplicates in BST
            } else if (current->value > value) {
                if (current->left == nullptr) {
                    break; // Found the correct spot
                } else {
                    current = current->left;
                }
            } else {
                if (!current->rightThread) {
                    current = current->right;
                } else {
                    break; // Found the correct spot
                }
            }
        }

        node *newNode = new node(value); // Create the new node

        // Insert the new node in the correct position
        if (value < parent->value) {
            parent->left = newNode;
            newNode->right = parent;
            newNode->rightThread = true;
        } else {
            if (parent->rightThread) {
                newNode->right = parent->right;
                newNode->rightThread = true;
            }
            parent->right = newNode;
            parent->rightThread = false;
        }

        return root;
    }

    // Helper function to find the leftmost node starting from a given node
    node* leftmost(node* current) {
        if (current == nullptr) {
            return nullptr;
        }

        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    // Helper function to delete a node with a given value
    node* deleteNode(node* root, int value) {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return nullptr;
        }

        node *parent = nullptr;
        node *current = root;

        // Traverse the tree to find the node to delete and its parent
        while (current != nullptr && current->value != value) {
            parent = current;
            if (current->value > value) {
                current = current->left;
            } else {
                if (!current->rightThread) {
                    current = current->right;
                } else {
                    break;
                }
            }
        }

        if (current == nullptr || current->value != value) {
            cout << "Value not found in the tree." << endl;
            return root;
        }

        // Node with two children
        if (current->left != nullptr && (!current->rightThread && current->right != nullptr)) {
            node *successor = leftmost(current->right);
            int successorValue = successor->value;
            root = deleteNode(root, successorValue); // Recursively delete the successor
            current->value = successorValue; // Replace current node's value with successor's value
        }
            // Node with one child or no children
        else {
            node *child;
            if (current->left != nullptr) {
                child = current->left;
            } else {
                if (current->rightThread) {
                    child = nullptr;
                } else {
                    child = current->right;
                }
            }

            // Check if the node to delete is the root
            if (parent == nullptr) {
                root = child;
            } else if (current == parent->left) {
                parent->left = child; // Node to be deleted is a left child
            } else {
                if (parent->rightThread) {
                    parent->right = current->right; // Maintain the threading
                } else {
                    parent->right = child; // Node to be deleted is a right child
                }
                parent->rightThread = current->rightThread;
            }


            delete current; // Delete the current node
        }
        return root;
    }

public:
    // Constructor to initialize an empty tree
    ThreadedBST() {
        root = nullptr;
    }

    // Public method to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to delete a value
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Public method to perform in-order traversal
    void inorder() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        node *current = leftmost(root);
        while (current != nullptr) {
            cout << current->value << " ";
            if (current->rightThread) {
                current = current->right;
            } else {
                current = leftmost(current->right);
            }
        }
        cout << endl;
    }
};

int main() {
    ThreadedBST tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(16);
    tree.insert(14);
    tree.insert(17);

    cout << "In-order traversal of the threaded BST: ";
    tree.inorder();
    cout << endl;

    cout << "Deleting 10" << endl;
    tree.deleteValue(10);
    cout << "In-order traversal of the threaded BST: ";
    tree.inorder();
    cout << endl;

    cout << "Deleting 20" << endl;
    tree.deleteValue(20);
    cout << "In-order traversal of the threaded BST: ";
    tree.inorder();
    cout << endl;

    return 0;
}
