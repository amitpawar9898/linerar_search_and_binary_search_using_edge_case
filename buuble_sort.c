//Amit pawar
// A1
#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int temp, swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        break;
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
    printf("Bubble Sort Edge Case:\n");
    printf("Choose a test case \n");
    printf("1. Empty Array\n");
    printf("2. Single Element\n");
    printf("3. Already Sorted\n");
    printf("4. Duplicate Elements\n");
    printf("5. Negative Numbers\n");
    printf("6. Large Numbers\n");
    printf("7. All Identical Elements\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    int arr[100], n;
    switch (choice) {
        case 1: 
            n = 0;
            printf("Test Case: Empty Array\n");
            break;

        case 2: 
            n = 1;
            arr[0] = 42;
            printf("Test Case: Single Element\n");
            break;

        case 3: 
            n = 5;
            int temp1[] = {1, 2, 3, 4, 5};
            for (int i = 0; i < n; i++) arr[i] = temp1[i];
            printf("Test Case: Already Sorted Array\n");
            break;

        case 4:            n = 6;
            int temp2[] = {4, 2, 2, 3, 4, 1};
            for (int i = 0; i < n; i++) arr[i] = temp2[i];
            printf("Test Case: Duplicate Elements\n");
            break;

        case 5: 
            n = 5;
            int temp3[] = {-3, -1, -7, 2, 0};
            for (int i = 0; i < n; i++) arr[i] = temp3[i];
            printf("Test Case: Negative Numbers\n");
            break;

        case 6: 
            n = 5;
            int temp4[] = {100000, 999999, 956324, 215436, 87455166};
            for (int i = 0; i < n; i++) arr[i] = temp4[i];
            printf("Test Case: Large Numbers\n");
            break;

        case 7: 
            n = 5;
            int temp5[] = {7, 7, 7, 7, 7};
            for (int i = 0; i < n; i++) arr[i] = temp5[i];
            printf("Test Case: All Identical Elements\n");
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }
    printf("Original Array: ");
    printArray(arr, n);
    if (n > 0) {
        bubbleSort(arr, n);
        printf("Sorted Array: ");
        printArray(arr, n);
    }
    return 0;
}