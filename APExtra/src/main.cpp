#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

int getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root;
    }

    root->height = 1 + std::max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Caso 1
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    // Caso 2
    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    // Caso 3
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso 4
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = (root->left != nullptr) ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + std::max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Caso 1
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Caso 3
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso 2
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    // Caso 4
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printPreOrder(Node* root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << root->key << " ";
        printInOrder(root->right);
    }
}

void printPostOrder(Node* root) {
    if (root != nullptr) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        std::cout << root->key << " ";
    }
}

int main() {
    Node* root = nullptr;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        char operation;
        int key;
        std::cin >> operation >> key;

        if (operation == 'i') {
            root = insert(root, key);
        } else if (operation == 'r') {
            root = deleteNode(root, key);
        }
    }

    printPreOrder(root);
    std::cout << std::endl;

    printInOrder(root);
    std::cout << std::endl;

    printPostOrder(root);
    std::cout << std::endl;

    return 0;
}
