//Singly_Linked list
//Amit pawar
// A1-Ai/Ml
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//INSERT FUNCTIONS 
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}
void insertAtPosition(struct Node** head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertAtFront(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
// DISPLAY FUNCTION
void printList(struct Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
//UPDATE FUNCTIONS
void updateAtFront(struct Node* head, int newData) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    head->data = newData;
}
void updateAtEnd(struct Node* head, int newData) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    while (head->next) head = head->next;
    head->data = newData;
}
void updateAtPosition(struct Node* head, int pos, int newData) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = 1; head != NULL && i < pos; i++)
        head = head->next;

    if (!head) {
        printf("Position out of range!\n");
        return;
    }
    head->data = newData;
}
// DELETE FUNCTIONS 
void deleteAtFront(struct Node** head) {
    if (!*head) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteAtEnd(struct Node** head) {
    if (!*head) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}
void deleteAtPosition(struct Node** head, int pos) {
    if (pos < 1 || *head == NULL) {
        printf("Invalid or empty list!\n");
        return;
    }
    if (pos == 1) {
        deleteAtFront(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
//  DELETE BY VALUE 
void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Value %d deleted successfully!\n", value);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found in list!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Value %d deleted successfully!\n", value);
}
//  OTHER FUNCTIONS 
void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next) temp = temp->next;
        temp->next = *head2;
    }
    *head2 = NULL;
    printf("Lists concatenated successfully!\n");
}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed successfully!\n");
}
void freeList(struct Node** head) {
    while (*head) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int mainChoice, subChoice, data, pos, count, listChoice;
    while (1) {
        printf("\n MAIN MENU\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Delete by Value\n");
        printf("6. Concatenate Lists\n");
        printf("7. Reverse List\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &mainChoice);
        switch (mainChoice) {
        case 1: 
            printf("Insert into which list (1 or 2): ");
            scanf("%d", &listChoice);
            printf("\n-- INSERT MENU --\n1. Front\n2. End\n3. Position\nEnter choice: ");
            scanf("%d", &subChoice);
            printf("How many nodes to insert? ");
            scanf("%d", &count);
            for (int i = 0; i < count; i++) {
                printf("Enter data: ");
                scanf("%d", &data);
                struct Node** targetList = (listChoice == 1) ? &head1 : &head2;
                if (subChoice == 1) insertAtFront(targetList, data);
                else if (subChoice == 2) insertAtEnd(targetList, data);
                else if (subChoice == 3) {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    insertAtPosition(targetList, data, pos);
                } else {
                    printf("Invalid insert choice!\n");
                    break;
                }
            }
            break;
        case 2: 
            printf("Display which list (1, 2, or 3 for both): ");
            scanf("%d", &listChoice);
            if (listChoice == 1) printList(head1);
            else if (listChoice == 2) printList(head2);
            else if (listChoice == 3) {
                printf("List 1: ");
                printList(head1);
                printf("List 2: ");
                printList(head2);
            } else printf("Invalid choice!\n");
            break;
        case 3: 
            printf("Update which list (1 or 2): ");
            scanf("%d", &listChoice);
            printf("\n-- UPDATE MENU --\n1. Front\n2. End\n3. Position\nEnter choice: ");
            scanf("%d", &subChoice);
            printf("How many nodes to update? ");
            scanf("%d", &count);
            for (int i = 0; i < count; i++) {
                printf("Enter new data: ");
                scanf("%d", &data);
                struct Node* targetList = (listChoice == 1) ? head1 : head2;
                if (subChoice == 1) updateAtFront(targetList, data);
                else if (subChoice == 2) updateAtEnd(targetList, data);
                else if (subChoice == 3) {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    updateAtPosition(targetList, pos, data);
                } else {
                    printf("Invalid update choice!\n");
                    break;
                }
            }
            break;
        case 4:
            printf("Delete from which list (1 or 2): ");
            scanf("%d", &listChoice);
            printf("\n-- DELETE MENU --\n1. Front\n2. End\n3. Position\nEnter choice: ");
            scanf("%d", &subChoice);
            printf("How many nodes to delete? ");
            scanf("%d", &count);
            for (int i = 0; i < count; i++) {
                struct Node** targetList = (listChoice == 1) ? &head1 : &head2;
                if (subChoice == 1) deleteAtFront(targetList);
                else if (subChoice == 2) deleteAtEnd(targetList);
                else if (subChoice == 3) {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    deleteAtPosition(targetList, pos);
                } else {
                    printf("Invalid delete choice!\n");
                    break;
                }
            }
            break;
        case 5: 
            printf("Delete from which list? (1 or 2): ");
            scanf("%d", &listChoice);
            printf("Enter value to delete: ");
            scanf("%d", &data);
            if (listChoice == 1) deleteByValue(&head1, data);
            else if (listChoice == 2) deleteByValue(&head2, data);
            else printf("Invalid list choice!\n");
            break;
        case 6:
            concatenateLists(&head1, &head2);
            break;
        case 7: 
            printf("Reverse which list (1 or 2): ");
            scanf("%d", &listChoice);
            if (listChoice == 1) reverseList(&head1);
            else if (listChoice == 2) reverseList(&head2);
            else printf("Invalid choice!\n");
            break;
        case 8: 
            printf("Exiting...\n");
            freeList(&head1);
            freeList(&head2);
            exit(0);
        default:
            printf("Invalid main menu choice!\n");
        }
    }
    return 0;
}
