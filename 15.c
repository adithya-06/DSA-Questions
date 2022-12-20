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
int ans = 0;
void count(Node *root) {
	if (!root) {
		return;
	}
	if (root->left && root->right) {
		ans++;
	}
	count(root->left);
	count(root->right);
}
void dfs(Node *root) {
	if (!root)
		return;
	printf("%d ", root->val);
	dfs(root->left);
	dfs(root->right);
}
int main() {
	Node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);
	root->left->left = new_node(4);
	root->left->right = new_node(5);
	root->right->left = new_node(6);
	root->right->right = new_node(7);

	printf("15. Design an algorithm to count and return the number of nodes in a binary tree that have two"
	       "children. Express your solution as a pair of Java functions (not BST member functions), which"
	       "would be implemented in the same package as the BST generic specified.\n\n");

	dfs(root);

	count(root);
	printf("\n");
	printf("The no of node that have two children : %d", ans);



	return 0;
}



