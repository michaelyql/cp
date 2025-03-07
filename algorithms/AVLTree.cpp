#include <iostream>

using namespace std;

class AVLTree 
{
public:
    int height = 0;
    int val = 0;
    AVLTree *left;
    AVLTree *right;
};

int height(AVLTree *node) {
    if (node == NULL) 
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLTree* newNode(int val) {
    AVLTree* node = new AVLTree();
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

AVLTree* rightRotate(AVLTree *y) {
    AVLTree *x = y->left;
    AVLTree *temp = x->right;

    //Perform rotation
    x->right = y;
    y->left = temp;

    // Update heights
    y->height = max(height(y->left), 
                    height(y->right) + 1);
    x->height = max(height(x->left),
                    height(x->right) + 1);
    return x;
}

int main() {
    return 0;
}
