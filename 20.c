#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
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

int search(Node *root, int val) {
	if (root->val == val) {
		return 1;
	} if (root->val > val) {
		search(root->left, val);
	} else {
		search(root->right, val);
	}
	return 0;
}


int max(Node *root) {
	if (!root) {
		return -1;
	}
	if (!root->left && !root->right) {
		return root->val;
	}
	return max(root->right);
}

int min(Node *root) {
	if (!root || !root->left) {
		return root->val;
	}
	return min(root->left);
}
Node *inorder_successor(Node *root) {
	if (!root || !root->left) {
		return root;
	}
	return inorder_successor(root->left);
}
Node* delete(Node *root, int val) {
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
		} else if (root->left == NULL) {
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


void dfs(Node *root) {
	if (!root) {
		return;
	}
	dfs(root->left);
	printf("%d ", root->val);
	dfs(root->right);
}
int main() {
	Node *root = NULL;


	int arr[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		root = insert(root, arr[i]);
	}
	printf("20. Implement Binary Search Trees with following functionalities\n"
	       "(i) Search (): Search user given item into Recursive & Non-Recursive method\n"
	       "(ii) Insertion (): insert the new element in to the binary tree\n"
	       "(iii) Max (): Find the maximum element of the BST\n"
	       "(iv)Min (): Find the Minimum element of the BST\n"
	       "(v) Delete (): Delete a given node from the BST\n\n");


	dfs(root);
	printf("\n");

	printf("After deleting 1 -> ");
	root = delete(root, 1);
	dfs(root);
	printf("\n");
	printf("Minimum element in tree %d\n", min(root));
	printf("Maximum element in tree %d\n", max(root));



	return 0;
}
