#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int val;
	struct Node *next;
} Node;

Node *new_node(int val) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

Node *append(Node *head, int val) {
	if (!head) {
		return new_node(val);
	}
	head->next = append(head->next, val);
	return head;
}
Node *get_mid(Node *head) {
	if (!head) {
		return head;
	}
	Node *temp = NULL;
	while (head && head->next) {
		temp = (!temp) ? head : temp->next;
		head = head->next->next;
	}

	Node *temp2 = temp->next;
	temp->next = NULL;
	return temp2;
}


Node *merge(Node *head1, Node *head2) {
	Node *new_head = new_node(0);
	Node *head = new_head;
	while (head1 && head2) {
		if (head1->val < head2->val) {
			new_head->next = head1;
			head1 = head1->next;
		} else {
			new_head->next = head2;
			head2 = head2->next;
		}
		new_head = new_head->next;
	}
	if (head1) new_head->next = head1;
	else new_head->next = head2;

	return head->next;
}

Node *merge_sort(Node *head) {
	if (!head || !head->next) {
		return head;
	}
	Node *mid = get_mid(head);
	Node *left = merge_sort(head);
	Node *right = merge_sort(mid);
	return merge(left, right);

}

void print_list(Node *head) {
	if (!head) {
		return;
	}
	printf("%d ", head->val);
	print_list(head->next);
}



int main() {
	Node *head1 = NULL;
	Node *head2 = NULL;
	int arr1[] = {1, 8, 10, 4};
	int arr2[] = {7, 9, 3, 11};
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
		head1 = append(head1, arr1[i]);
	}
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
		head2 = append(head2, arr2[i]);
	}
	printf("19. Two linked list mentioned below. Given pointers to the heads of two unsorted linked lists,"
	       "merge them into a single, sorted linked list. Either head pointer may be null meaning that the"
	       "corresponding list is empty.\n"
	       "(i)Create (): create the two singly linked list.\n"
	       "linked list A: 1->8->10->4\n"
	       "linked list B : 7->9->3->11\n"
	       "(ii)display (): display the created linked list.\n"
	       "(iii) merge (): merge the two given linked list and bring the output as ordered one\n"
	       "output : 1->3->4->8->9->10\n"
	       "Function Description\n"
	       "mergeLists has the following parameters:\n"
	       "• SinglyLinkedListNode pointer headA: a reference to the head of a list\n"
	       "• SinglyLinkedListNode pointer headB: a reference to the head of a list\n\n");

	printf("List 1 -> ");
	print_list(head1);
	printf("\n");
	printf("List 2 -> ");
	print_list(head2);
	printf("\n");

	head1 = merge_sort(head1);
	head2 = merge_sort(head2);
	Node *new_head = merge(head1, head2);
	printf("Merged List -> ");
	print_list(new_head);


}
