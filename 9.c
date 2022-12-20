#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int val;
	struct Node *left, *right;
} Node;
Node *new_node(int val) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}


Node *insert(Node *root, int val) {
	if (!root) {
		return new_node(val);
	}
	if (root->val > val) {
		root->left = insert(root->left, val);
	} else {
		root->right = insert(root->right, val);
	}
	return root;
}
Node *inorder_successor(Node *root) {
	if (!root || !root->left) {
		return root;
	}
	return inorder_successor(root->left);
}


Node *delete(Node *root, int val) {
	if (!root) {
		return root;
	}
	if (root->val > val) {
		root->left = delete(root->left, val);
	} else if (root->val < val) {
		root->right = delete(root->right, val);
	} else {
		if (!root->left && !root->right) {
			free(root);
			return NULL;
		} else if (!root->left) {
			Node *temp = root->right;
			free(root);
			return temp;
		} else if (!root->right) {
			Node *temp = root->left;
			free(root);
			return temp;
		}
		Node *temp = inorder_successor(root->right);
		root->val = temp->val;
		root->right = delete(root->right, temp->val);
	}

	return root;
}
void dsf(Node *root) {
	if (!root) {
		return;
	}
	dsf(root->left);
	printf("%d ", root->val);
	dsf(root->right);

}


int main() {
	Node *root = NULL;
	int arr[] = {99, 1, 47, 13, 54, 33, 5, 68, 24, 86, 24, 56, 56};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++) {
		root = insert(root, arr[i]);
	}
	printf("9. Construct a binary search tree using the following input:"
	       "99, 1, 47, 13, 54, 33, 5, 68, 24, 86, 24, 56, 46\n"
	       "i) Insert the elements 20, 38, 44, 53, and 62 into the tree\n"
	       "ii) Delete the elements from tree such as 24, 54, 1, and 47.\n\n");
	dsf(root);
	printf("\n");
	int arr2[] = {24, 54, 1, 47};
	int m = sizeof(arr2) / sizeof(arr2[0]);
	for (int i = 0; i < m; i++) {
		root = delete(root, arr2[i]);
	}
	printf("\n");
	printf("After deleting the elemnets\n");
	dsf(root);



}
