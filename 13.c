#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	char *name;
	char *roll_no;
	char *course;
	int total_marks;
	struct Node *next;
} Node;

Node *new_node(char *name, char *roll_no, char *course, int total_marks) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->name = name;
	temp->roll_no = roll_no;
	temp->course = course;
	temp->total_marks = total_marks;
	temp->next = NULL;
	return temp;
}


Node *insert(Node *head, Node *temp) {
	if (head == NULL) {
		head = temp;
		return temp;
	}
	Node *node  = head;
	while (node->next) {
		node = node->next;
	}
	node->next = temp;
	return head;
}

void delete(Node **head, Node *node) {
	if ((*head) == NULL) {
		return;
	}
	if ((*head) == node) {
		Node *temp = (*head);
		(*head) = (*head)->next;
		free(temp);
		return;
	}
	Node *temp = *head;
	while (temp->next != node) {
		temp = temp->next;
	}
	Node *temp2 = temp->next;
	temp->next = temp->next->next;
	free(temp2);
}


void show(Node *head) {
	if (!head) {
		return;
	}
	printf("NAME OF THE STUDENT : %s\n", head->name);
	printf("ROLL NO OF THE STUDENT : %s\n", head->roll_no);
	printf("COURSE OF THE STUDENT : %s\n", head->course);
	printf("TOTAL MARKS OF THE STUDENT :%d\n\n\n", head->total_marks);
	show(head->next);
}

Node *search(Node *head, Node *node) {
	if (!head) {
		return head;
	}
	while (head) {
		if (head == node) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}


int main() {
	Node *head = NULL;
	head = insert(head, new_node("name1", "roll_no1", "course1", 101));
	head = insert(head, new_node("name2", "roll_no2", "course2", 102));
	head = insert(head, new_node("name3", "roll_no3", "course3", 103));
	head = insert(head, new_node("name4", "roll_no4", "course4", 104));
	head = insert(head, new_node("name5", "roll_no5", "course5", 105));
	head = insert(head, new_node("name6", "roll_no7", "course6", 106));
	head = insert(head, new_node("name7", "roll_no8", "course7", 107));

	printf("13. Create a student Record Management system using linked list that can perform the"
	       "following operations:\n"
	       "➢ Insert Student record\n"
	       "➢ Delete student record\n"
	       "➢ Show student record\n"
	       "➢ Search student record\n"
	       "The student record should contain the following items\n"
	       "➢ Name of Student\n"
	       "➢ Roll Number of Student\n"
	       "➢ Course in which Student is Enrolled\n"
	       "➢ Total Marks of Student\n\n");
	show(head);
	printf("\ndeleting record of student 1\n");
	delete(&head, head);
	printf("\n");
	show(head);
}