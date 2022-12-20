#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	char *name;
	int age;
	char sex;
	char *aadhar;
	struct Node *left;
	struct Node *right;
} Node;

Node *new_node(char *name, int age, char sex, char *aadhar) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->name = name;
	temp->age = age;
	temp->sex = sex;
	temp->aadhar = aadhar;
	temp->left = temp->right = NULL;
	return temp;
}

Node *insert(Node *head, Node *node) {
	if (!head) {
		return node;
	}
	if (head->age > node->age) {
		head->left = insert(head->left, node);
	} else {
		head->right = insert(head->right, node);
	}
	return head;
}
void print_tree(Node *head) {
	if (!head) {
		return;
	}
	printf("Name : %s\n", head->name);
	printf("Age : %d\n", head->age);
	printf("Sex : %c\n", head->sex);
	printf("Aadhar : %s\n", head->aadhar);
	printf("\n\n");
	print_tree(head->left);
	print_tree(head->right);
}
void dfs(Node *head) {
	if (!head) {
		return;
	}
	if (head->age < 18) {
		printf("Name : %s\n", head->name);
		printf("Age : %d\n", head->age);
		printf("Sex : %c\n", head->sex);
		printf("Aadhar : %s\n", head->aadhar);
		printf("\n\n");
	}
	dfs(head->left);
	dfs(head->right);

}
int main() {
	Node *head = NULL;

	Node *g_father = new_node("Grand_Father", 69, 'M', "000000000000");
	Node *g_mother = new_node("Grand_Mother", 64, 'F', "000000000000");
	Node *father = new_node("Father", 40, 'M', "000000000000");
	Node *mother = new_node("Mother", 35, 'F', "000000000000");
	Node *first_son = new_node("First_son", 15, 'M', "00000000000");
	Node *second_son = new_node("Second_son", 10, 'M', "00000000000");
	Node *aunt = new_node("Aunt", 25, 'F', "000000000000");
	Node *uncle = new_node("Uncle", 30, 'M', "000000000000");

	head = insert(head, g_father);
	head = insert(head, g_mother);
	head = insert(head, father);
	head = insert(head, mother);
	head = insert(head, first_son);
	head = insert(head, second_son);
	head = insert(head, aunt);
	head = insert(head, uncle);
	printf("4. Create a database for a family with 8 members whose data such as name, sex, age and adhar  number are stored.\n"
	       "i)Construct a Binary Search Tree (BST) based on the age as key element.\n ii) Display the details of the members whose age is less than 18\n\n");

	print_tree(head);

	printf("family members whose age is less than 18\n\n");
	dfs(head);


}
