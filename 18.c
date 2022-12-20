#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

Node *new_node(int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    temp->prev = temp->next = NULL;
    return temp;
}



void sorted_insert(Node **head, int val) {
    if (!(*head)) {
        (*head) = new_node(val);
        return;
    }
    else if ((*head)->val >= val) {
        Node *temp = new_node(val);
        temp->next = (*head);
        (*head)->prev = temp;
        (*head) = temp;
        return;
    }
    else {
        Node *temp = (*head);
        Node *node = new_node(val);
        while (temp->next != NULL && temp->next->val < node->val) {
            temp = temp->next;
        }
        node->next = temp->next;
        node->prev = temp;
        if (temp->next) {
            temp->next->prev = node;
        }
        temp->next = node;
    }
}






Node *insert(Node *head, int val) {
    if (!head) {
        return new_node(val);
    }
    Node *temp = new_node(val);
    temp->next = head->next;
    temp->prev = head;
    if (head->next) {
        head->next->prev = temp;
    }
    head->next = temp;
    return head;
}





int count(Node *head) {
    if (!head)
        return 0;
    return 1 + count(head->next);

}






Node *delete(Node *head) {
    if (!head) {
        return head;
    }
    int c = count(head);
    if (c < 5) {
        return head;
    }
    int i = 0;
    Node *temp = head;
    while (i < 4) {
        temp = temp->next;
        i++;
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    } else
        temp->prev->next = NULL;
    return head;
}



Node *reverse(Node *head) {
    if (!head) {
        return head;
    }
    Node *current = head, *prev = NULL, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    return prev;
}




void print_list(Node *head) {
    if (!head) {
        return;
    }
    printf("%d ", head->val);
    print_list(head->next);
}




Node *create_list(int n) {
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        sorted_insert(&head, a);
    }
    return head;
}

int main() {
    int n;
    scanf("%d", &n);
    Node *head = create_list(n);

    printf("18. Create the doubly linked list program using 7 nodes. Each Node will have a reference pointer"
           "to its next as well as previous node. Doubly linked list program should follow the below"
           "functionalities\n"
           "(i)Create (): create the doubly linked list with ascending order.\n"
           "(ii) Insert (): New elements to be inserted in the 2nd index position.\n"
           "(iii)Delete (): Delete the 5th index position node and display the whole doubly list\n"
           "(iii)Reverse (): Once all the element are inserted and then reversing a linked list will reverse the\n"
           "list as well as the property ascending becomes descending and vice-versa.\n\n");
    print_list(head);


}
