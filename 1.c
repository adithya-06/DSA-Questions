#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int roll_no;
	int *arr;
	char *name;
	int average;
	struct Node *next;
	struct Node *prev;
	char grade;
} Node;

Node *new_node(int roll, int *marks, char *name) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->roll_no = roll;
	temp->arr = marks;
	temp->name = name;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += marks[i];
	}
	temp->average = sum / 5;
	if (temp->average >= 90) {
		temp->grade = 'O';
	} else if (temp->average >= 80 && temp->average <= 89) {
		temp->grade = 'A';
	} else if (temp->average >= 70 && temp->average <= 79) {
		temp->grade = 'B';
	} else if (temp->average >= 60 && temp->average <= 69) {
		temp->grade = 'C';
	} else if (temp->average >= 50 && temp->average <= 59) {
		temp->grade = 'D';
	} else {
		temp->grade = 'F';
	}
	temp->next = temp->prev = NULL;

	return temp;
}

void print_list(Node *head) {
	if (!head) {
		return;
	}
	while (head) {
		printf("Name : %s\n", head->name);
		printf("Roll_Number : %d\n", head->roll_no);
		printf("Marks :");
		for (int i = 0; i < 5; i++) {
			printf("%d ", head->arr[i]);
		}
		printf("\n");
		printf("Average :%d\n", head->average);
		printf("Grade : %c\n" , head->grade);
		printf("\n\n");
		head = head->next;
	}

}

int main() {
	int *arr = (int []) {95, 95, 95, 95, 95};
	Node *s_1 = new_node(1, arr, "student_1");

	int *arr2 = (int []) {90, 90, 90, 90, 90};

	s_1->next = new_node(2, arr2, "student_2");
	s_1->next->prev = s_1;

	int *arr3 = (int []) {85, 85, 85, 85, 85};



	s_1->next->next = new_node(3, arr3, "student_3");
	s_1->next->next->prev = s_1->next;

	int *arr4 = (int []) {80, 80, 80, 80, 80};


	s_1->next->next->next = new_node(4, arr4, "student_4");
	s_1->next->next->next->prev = s_1->next->next;
	int *arr5 = (int []) {80, 80, 80, 80, 80};


	s_1->next->next->next->next = new_node(5, arr5, "student_5");
	s_1->next->next->next->next->prev = s_1->next->next->next;

	printf("1. Create a student database with 5 students using doubly linked list in which each student data like roll number, name, marks of 5 subjects (marks between 0 and 100) are stored in the nodes by creating structures.\n");
	printf("i) Print the students’ details by traversing in both the direction.\n");
	printf("ii) Calculate the average marks of the student and display his grade as per the grade mapping below along with name and roll number.\n\n");

	print_list(s_1);
	printf("\n");
	return 0;
}
