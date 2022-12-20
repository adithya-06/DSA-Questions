#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char *title;
    char *author_name;
    char *publisher_name;
    int year_of_publication;
    char *isbn_no;
    int price;

    struct Node *prev;
    struct Node *next;

} Node;

Node *new_node(char *title, char *author_name, char *publisher_name, int year_of_publication, char *isbn_no, int price) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->title = title;
    temp->author_name = author_name;
    temp->publisher_name = publisher_name;
    temp->year_of_publication = year_of_publication;
    temp->isbn_no = isbn_no;
    temp->price = price;
    temp->prev = temp->next = NULL;
    return temp;

}
typedef struct stack {
    Node *head;
} stack;

stack *create_stack() {
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->head = NULL;
    return temp;
}

void push(stack *s, Node *n) {
    if (s->head == NULL) {
        s->head = n;
        return;
    }
    n->next = s->head;
    s->head->prev = n;
    s->head = n;
}
int is_empty(stack *s) {
    return s->head == NULL;
}

void pop(stack *s) {
    if (is_empty(s)) {
        return;
    }
    Node *temp = s->head;
    s->head = s->head->next;
    free(temp);
}
Node* top(stack *s) {
    if (!s->head) {
        return NULL;
    }
    return s->head;
}
void print_node(Node *temp) {
    printf("Title               : %s\n", temp->title);
    printf("Author's Name       : %s\n", temp->author_name);
    printf("Publisher Name      : %s\n", temp->publisher_name);
    printf("Year of Publication : %d\n", temp->year_of_publication);
    printf("Isbn_No             : %s\n", temp->isbn_no);
    printf("Price               : %d\n\n", temp->price);
    printf("--------------------------------------------------------\n");
}

void print_stack(stack *s) {
    Node *temp = s->head;
    while (temp) {
        print_node(temp);
        temp = temp->next;
    }
}
int price_of_the_books(stack *s) {
    Node *temp = s->head;
    int ans = 0;
    while (temp) {
        ans += temp->price;
        temp = temp->next;
    }
    return ans;
}



int main() {
    stack *s = create_stack();
    push(s, new_node("title1", "authors_name1", "publisher_name1", 1990, "978-3-16-148410-0", 200));
    push(s, new_node("title2", "authors_name2", "publisher_name2", 1991, "978-3-16-148410-0", 200));
    push(s, new_node("title3", "authors_name3", "publisher_name3", 1992, "978-3-16-148410-0", 200));
    push(s, new_node("title4", "authors_name4", "publisher_name4", 1993, "978-3-16-148410-0", 200));
    push(s, new_node("title5", "authors_name5", "publisher_name5", 1993, "978-3-16-148410-0", 200));
    printf("2. Create a stack with 5 books using doubly linked list in which the data relevant to the books"
           "such as book title, authors name, publisher name, year of publication, ISBN number, and"
           "price are stored in the nodes by creating structures.\n"
           "i) Print the book details in Last In First Out (LIFO) order.\n"
           "ii) Calculate the total price of the books purchased by a custome\n\n");
    print_stack(s);
    printf("Price of the Books : %d\n", price_of_the_books(s));
}


