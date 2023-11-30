#include <iostream>
#include <cstring>

struct AVLNode {
    char word[50];
    int* pages;
    int pageCount;
    AVLNode* left;
    AVLNode* right;
    int height;
};

AVLNode* createNode(char* word, int page) {
    AVLNode* node = new AVLNode();
    strcpy(node->word, word);
    node->pages = new int[1];
    node->pages[0] = page;
    node->pageCount = 1;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

int getHeight(AVLNode* node) {
    return (node == nullptr) ? 0 : node->height;
}

int getBalance(AVLNode* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = Max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = Max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = Max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = Max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int customStringCompare(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return static_cast<int>(*str1) - static_cast<int>(*str2);
}

void insertIntoPages(int*& pages, int& pageCount, int page) {
    int i = pageCount - 1;
    while (i >= 0 && pages[i] > page) {
        pages[i + 1] = pages[i];
        --i;
    }
    pages[i + 1] = page;
    ++pageCount;
}

AVLNode* insertNode(AVLNode* node, char* word, int page) {
    if (node == nullptr)
        return createNode(word, page);

    int cmpResult = customStringCompare(word, node->word);

    if (cmpResult < 0)
        node->left = insertNode(node->left, word, page);
    else if (cmpResult > 0)
        node->right = insertNode(node->right, word, page);
    else {
        bool pageExists = false;
        for (int i = 0; i < node->pageCount; i++) {
            if (node->pages[i] == page) {
                pageExists = true;
                break;
            }
        }

        if (!pageExists) {
            int* newPages = new int[node->pageCount + 1];
            for (int i = 0; i < node->pageCount; i++)
                newPages[i] = node->pages[i];
            insertIntoPages(newPages, node->pageCount, page);
            delete[] node->pages;
            node->pages = newPages;
        }

        return node;
    }

    node->height = 1 + Max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && cmpResult < 0)
        return rightRotate(node);

    if (balance < -1 && cmpResult > 0)
        return leftRotate(node);

    if (balance > 1 && cmpResult > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && cmpResult < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printAVL(AVLNode* root) {
    if (root != nullptr) {
        printAVL(root->left);
        std::cout << root->word << ": ";
        for (int i = 0; i < root->pageCount; i++)
            std::cout << root->pages[i] << " ";
        std::cout << std::endl;
        printAVL(root->right);
    }
}

int main() {
    char word[50];
    int page;
    AVLNode* root = nullptr;

    std::cin >> word >> page;
    root = insertNode(root, word, page);

    while (std::cin >> word >> page) {
        root = insertNode(root, word, page);
    }

    printAVL(root);
    return 0;
}
