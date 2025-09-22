// Circular Linked List 
// Amit Pawar - A1/AimL
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = newNode;
    return newNode;
}
// Insert at Beginning
struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) return newNode;

    struct Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return newNode; // New node becomes head
}

// Insert at End
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) return newNode;

    struct Node* last = head->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
    return head;
}
// Insert at a specific position
struct Node* insertPosition(struct Node* head, int pos, int data) {
    if (pos == 1) return insertBeginning(head, data);

    struct Node* temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (i < pos - 1) {
        printf("Position out of range.\n");
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}
// Delete from Beginning
struct Node* deleteBeginning(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* last = head->prev;
    struct Node* temp = head;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
    return head;
}
// Delete from End
struct Node* deleteEnd(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    free(last);
    return head;
}
// Delete at specific position
struct Node* deletePosition(struct Node* head, int pos) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }
    if (pos == 1) 
    return deleteBeginning(head);
    struct Node* temp = head;
    int i;
    for (i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;
    if (i < pos) {
        printf("Position out of range.\n");
        return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;
    free(temp);
    return head;
}
// Display the list
void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
// Reverse the list
struct Node* reverseList(struct Node* head) {
    if (!head) return NULL;

    struct Node* current = head, *temp = NULL;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);

    if (temp) head = temp->prev;
    return head;
}
// Concatenate two circular doubly linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    struct Node* last1 = head1->prev;
    struct Node* last2 = head2->prev;

    last1->next = head2;
    head2->prev = last1;
    last2->next = head1;
    head1->prev = last2;
    return head1;
}
// Main function 
int main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL;
    int choice, data, pos;
    do {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Reverse\n");
        printf("9. Concatenate (enter second list)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertBeginning(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertPosition(head, pos, data);
                break;
            case 4:
                head = deleteBeginning(head);
                break;
            case 5:
                head = deleteEnd(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deletePosition(head, pos);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                head = reverseList(head);
                printf("List reversed.\n");
                break;
            case 9:
                printf("Enter second list elements (-1 to stop):\n");
                while (1) {
                    scanf("%d", &data);
                    if (data == -1) break;
                    head2 = insertEnd(head2, data);
                }
                head = concatenate(head, head2);
                printf("Lists concatenated.\n");
                break;
            case 0:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
