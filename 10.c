#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val, height;
    struct Node *left, *right;
} Node;

Node *new_node(int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}
int height(Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}
int get_difference(Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
Node *left_rotate(Node *x) {
    Node *y = x->right;
    Node *t2 = y->left;

    x->right = t2;
    y->left = x;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

Node *right_rotate(Node *y) {
    Node *x = y->left;
    Node *t2 = x->right;

    y->left = t2;
    x->right = y;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *insert(Node *root, int val) {
    if (root == NULL)
        return new_node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    else
        return root;
    root->height = max(height(root->left), height(root->right)) + 1;

    int difference = get_difference(root);

    if (difference > 1 && val < root->left->val)
        return right_rotate(root);
    if (difference < -1 && val > root->right->val)
        return left_rotate(root);
    if (difference > 1 && val > root->left->val) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (difference < -1 && val < root->right->val) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
Node *min_val(Node *n) {
    Node *temp  = n;
    while (temp ->left != NULL)
        temp = temp->left;
    return temp;
}

Node *delete_node(Node *root, int val) {
    if (root == NULL)
        return root;

    if (val < root->val)
        root->left = delete_node(root->left, val);
    else if (val > root->val)
        root->right = delete_node(root->right, val);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;

                free(temp);
            }
        } else {
            Node *temp = min_val(root->right);

            root->val = temp->val;

            root->right = delete_node(root->right, temp->val);
        }
    }

    if (root == NULL)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int difference = get_difference(root);

    if (difference > 1 && get_difference(root->left) >= 0)
        return right_rotate(root);
    if (difference > 1 && get_difference(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (difference < -1 && get_difference(root->right) > 0)
        return left_rotate(root);
    if (difference < -1 && get_difference(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}
void preorder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}


int main() {
    Node *root = NULL;
    int arr[] = {16, 80, 28, 12, 18, 24, 25, 2, 37, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    printf("10. Make use of AVL tree and insert the following elements 16, 80, 28, 12, 18, 24, 25, and 2"
           "in order. After inserting the elements, you are supposed to delete nodes 37, 62, 12, and 2"
           "from the AVL tree formed.\n\n");
    preorder(root);
    printf("\n");
    int arr1[] = {37, 62, 12, 2};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < m; i++) {
        root = delete_node(root, arr1[i]);
    }
    printf("\n");
    printf("After Deletion\n");
    preorder(root);
}
