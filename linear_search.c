//linerar_serach
//Amit pawar
//A1
#include <stdio.h>
void linearSearch(int arr[], int n, int key) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            return;
        }
    }
    printf("Element %d not found.\n", key);
}
int main() {
    int choice;
    do {
        printf("\n Search Test Cases\n");
        printf("1. Empty Array\n");
        printf("2. Element Not Present\n");
        printf("3. Element at First Position\n");
        printf("4. Element at Last Position\n");
        printf("5. Multiple Occurrences\n");
        printf("6. Negative Numbers\n");
        printf("7. Large Numbers\n");
        printf("8. All Identical Elements\n");
        printf("9. Exit\n");
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        int n, key;
        switch(choice) {
            case 1: { 
                n = 0;
                key = 10;
                int *emptyArray = NULL;
                linearSearch(emptyArray, n, key);
                break;
            }
            case 2: {
                n = 5;
                int arr[] = {1, 2, 3, 4, 5};
                key = 6;
                linearSearch(arr, n, key);
                break;
            }
            case 3: {
                n = 5;
                int arr[] = {10, 20, 30, 40, 50};
                key = 10;
                linearSearch(arr, n, key);
                break;
            }
            case 4: {
                n = 5;
                int arr[] = {10, 20, 30, 40, 50};
                key = 50;
                linearSearch(arr, n, key);
                break;
            }
            case 5: {
                n = 6;
                int arr[] = {5, 1, 5, 3, 5, 9};
                key = 5;
                linearSearch(arr, n, key);
                break;

            }
            case 6: {
                n = 5;
                int arr[] = {-10, -5, 0, 5, 10};
                key = -5;
                linearSearch(arr, n, key);
                break;
            }
            case 7: {
                n = 5;
                int arr[] = {100000, 200000, 300000, 400000, 500000};
                key = 400000;
                linearSearch(arr, n, key);
                break;

            }
            case 8: {
                n = 5;
                int arr[] = {7, 7, 7, 7, 7};
                key = 7;
                linearSearch(arr, n, key);
                break;

            }
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select between 1 to 9.\n");
        }
     }
      while(choice != 9);
        return 0;
}