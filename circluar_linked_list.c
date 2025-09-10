//circluar_linked_list
//Amit pawar
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; 
    return newNode;
}
// Insert at beginning
void insertBeginning(Node **head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) temp = temp->next;
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}
// Insert at end
void insertEnd(Node **head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    }
}
// Insert at specific position
void insertAtPosition(Node **head, int data, int pos) {
    if (pos <= 1 || *head == NULL) {
        insertBeginning(head, data);
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++) temp = temp->next;
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
// Delete at beginning
void deleteBeginning(Node **head) {
    if (*head == NULL) return;
    Node *temp = *head, *last = *head;
    while (last->next != *head) last = last->next;
    if (temp->next == *head) { 
        free(temp);
        *head = NULL;
    } else {
        *head = temp->next;
        last->next = *head;
        free(temp);
    }
}
// Delete at end
void deleteEnd(Node **head) {
    if (*head == NULL) return;
    Node *temp = *head, *prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) { 
        free(temp);
        *head = NULL;
    } else {
        prev->next = *head;
        free(temp);
    }
}
// Delete at specific position
void deleteAtPosition(Node **head, int pos) {
    if (*head == NULL) return;
    if (pos <= 1) {
        deleteBeginning(head);
        return;
    }
    Node *temp = *head, *prev = NULL;
    for (int i = 1; i < pos && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head) return;
    prev->next = temp->next;
    free(temp);
}
// Reverse the circular linked list
void reverseList(Node **head) {
    if (*head == NULL || (*head)->next == *head) return;
    Node *prev = NULL, *curr = *head, *next = NULL, *last = *head;
    do { last = last->next; } while (last->next != *head);
    do {
        next = curr->next;
        curr->next = prev ? prev : *head; 
        prev = curr;
        curr = next;
    } while (curr != *head);
    (*head)->next = prev;
    *head = prev;
}
// Concatenate two circular linked lists
void concatenate(Node **head1, Node **head2) {
    if (*head2 == NULL) return;
    if (*head1 == NULL) { *head1 = *head2; return; }
    Node *temp1 = *head1, *temp2 = *head2;
    while (temp1->next != *head1) temp1 = temp1->next;
    while (temp2->next != *head2) temp2 = temp2->next;
    temp1->next = *head2;
    temp2->next = *head1;
}
// Display the circular linked list
void display(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}
int main() {
    Node *head1 = NULL, *head2 = NULL;
    int choice, data, pos;

    do {
        printf("\n Circular Linked List Menu \n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Reverse List\n");
        printf("8. Concatenate two lists\n");
        printf("9. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                 scanf("%d", &data);
                insertBeginning(&head1, data); 
                break;
            case 2:
                printf("Enter data: "); 
                scanf("%d", &data);
                insertEnd(&head1, data);
                 break;
            case 3:
                printf("Enter data and position: ");
                 scanf("%d %d", &data, &pos);
                insertAtPosition(&head1, data, pos); 
                break;
            case 4:
                deleteBeginning(&head1);
                 break;
            case 5:
                deleteEnd(&head1);
                 break;
            case 6:
                printf("Enter position: "); 
                scanf("%d", &pos);
                deleteAtPosition(&head1, pos);
                 break;
            case 7:
                reverseList(&head1); 
                break;
            case 8:
                printf("Creating second list for concatenation...\n");
                insertEnd(&head2, 100); 
                insertEnd(&head2, 200);
                concatenate(&head1, &head2); 
                break;
            case 9:
                display(head1);
                 break;
            case 0:
                printf("Exiting...\n");
                 break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
