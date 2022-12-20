#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node {
	int val, count, visited;
	char *name;
	struct Node *prev, *next;
} Node;

Node *new_node(char *name, int val) {
	Node *temp = (Node *)malloc(sizeof(Node ));
	temp->name = name;
	temp->val = val;
	temp->count = 0;
	temp->visited = 0;
	temp->prev = temp->next = NULL;
	return temp;
}

typedef struct queue {
	Node *first;
	Node *last;
} queue;

queue *create_queue() {
	queue *temp = (queue *)malloc(sizeof(queue));
	temp->first = temp->last = NULL;
	return temp;
}
void push(queue *q, Node *u) {
	if (q->first == NULL) {
		q->first = q->last = u;
		return;
	}
	q->last->next = u;
	u->prev = q->last;
	q->last = q->last->next;
}

void pop(queue *q) {
	if (q->last == NULL) {
		return;
	}
	Node *temp = q->last;
	q->last = q->last->prev;
	free(temp);
}


void print_queue(queue *q) {
	Node *temp = q->first;
	while (temp) {
		if (temp->val <= 2) {
			if (temp->val <= 0) {
				temp->count = 0;
			} else {
				temp->count = 1;
			}
		}
		if (temp->val % 2 != 0) {
			temp->count = temp->val / 2 + temp->val % 2;
		} else {
			temp->count = temp->val / 2;
		}
		temp = temp->next;
	}
	temp = q->first;
	while (temp) {
		printf("JOB ID  :%s  |", temp->name);
		printf("EXECUTION TIME :%d  |", temp->val);
		printf("TOTAL COUNTS   :%d  |\n\n", temp->count);
		temp = temp->next;
	}
}




int main() {
	queue *q = create_queue();
	push(q, new_node("POO1", 04));
	push(q, new_node("POO2", 02));
	push(q, new_node("POO3", 05));
	push(q, new_node("POO4", 03));
	push(q, new_node("POO5", 01));
	printf("3. In a single processor system, the processor is allocated with 5 jobs to complete the task in  First Come First Serve (FCFS) manner where each job is allowed to be executed for 2ms  of time in each turn. Create a linked list and store the job information is as follows:\n"

	       "i) Create a circular queue and complete all the jobs allocated in a circular manner. ii) Update the execution time as remaining time after every iteration.\n"
	       "iii) Finally print the number of turns each job undergone for processing.\n\n");
	print_queue(q);
}