//Amit pawar
//A1
// Selection Sort function
#include <stdio.h>
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}
void printArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int choice;
    int arr[100], n;

    printf("Selection Sort Edge Case \n");
    printf("Choose a test case:\n");
    printf("1. Empty Array\n");
    printf("2. Single Element\n");
    printf("3. Already Sorted\n");
    printf("4. Duplicate Elements\n");
    printf("5. Negative Numbers\n");
    printf("6. Large Numbers\n");
    printf("7. All Identical Elements\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            n = 0;
            printf("\nTest Case: Empty Array\n");
            break;

        case 2: 
            n = 1;
            arr[0] = 50;
            printf("\nTest Case: Single Element\n");
            break;

        case 3: 
            n = 5;
            {
                int temp[] = {1, 2, 3, 4, 5};
                for (int i = 0; i < n; i++) arr[i] = temp[i];
            }
            printf("\nTest Case: Already Sorted Array\n");
            break;

        case 4: 
            n = 6;
            {
                int temp[] = {4, 2, 2, 3, 4, 1};
                for (int i = 0; i < n; i++) arr[i] = temp[i];
            }
            printf("\nTest Case: Duplicate Elements\n");
            break;

        case 5:
            n = 5;
            {
                int temp[] = {-3, -1, -7, 2, 0};
                for (int i = 0; i < n; i++) arr[i] = temp[i];
            }
            printf("\nTest Case: Negative Numbers\n");
            break;

        case 6: 
            n = 5;
            {
                int temp[] = {1000, 9999, 5252, 23140, 652};
                for (int i = 0; i < n; i++) arr[i] = temp[i];
            }
            printf("\nTest Case: Large Numbers\n");
            break;

        case 7: 
                    n = 5;
            {
                int temp[] = {9, 9, 9, 9, 9};
                for (int i = 0; i < n; i++) arr[i] = temp[i];
            }
            printf("\nTest Case: All Identical Elements\n");
            break;
        default:
            printf("\nInvalid choice. Exiting.\n");
            return 0;
    }
    printf("Input Array: ");
    printArray(arr, n);
    if (n > 0) {
        selectionSort(arr, n);
        printf("Sorted Array: ");
        printArray(arr, n);
    }
    return  0;
}