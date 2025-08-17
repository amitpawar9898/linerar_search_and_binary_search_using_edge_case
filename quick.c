//Quick Sort 
// Amit Pawar
// A1
#include <stdio.h>
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);

int main() {
    int n, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n > 0) {
        quickSort(arr, 0, n - 1);
    }
    //test edge cases
    printf("\nEdge Case Menu:\n");
    printf("1. Empty Array\n");
    printf("2. Single Element\n");
    printf("3. Already Sorted\n");
    printf("4. Duplicate Elements\n");
    printf("5. Negative Numbers\n");
    printf("6. Large Numbers\n");
    printf("7. All Identical Elements\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Empty Array
            if (n == 0)
                printf("Edge Case 1: Empty array handled correctly.\n");
            else
                printf("Array is not empty.\n");
            break;

        case 2: // Single Element
            if (n == 1)
                printf("Edge Case 2: Single element array recognized.\n");
            else
                printf("Array has more than one element.\n");
            break;

        case 3: { // Already Sorted
            int sorted = 1;
            for (int i = 1; i < n; i++) {
                if (arr[i] < arr[i - 1]) {
                    sorted = 0;
                    break;
                }
            }
            if (sorted)
                printf("Edge Case 3: Array is already sorted.\n");
            else
                printf("Array was not sorted initially.\n");
            break;
        }

        case 4: { // Duplicate Elements
            int hasDuplicate = 0;
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] == arr[i + 1]) {
                    hasDuplicate = 1;
                    break;
                }
            }
            if (hasDuplicate)
                printf("Edge Case 4: Duplicate elements detected.\n");
            else
                printf("No duplicates found.\n");
            break;
        }

        case 5: { // Negative Numbers
            int hasNegative = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] < 0) {
                    hasNegative = 1;
                    break;
                }
            }
            if (hasNegative)
                printf("Edge Case 5: Negative numbers detected.\n");
            else
                printf("No negative numbers found.\n");
            break;
        }

        case 6: { // Large Numbers
            int hasLarge = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] > 1000000) { 
                    hasLarge = 1;
                    break;
                }
            }
            if (hasLarge)
                printf("Edge Case 6: Large numbers detected.\n");
            else
                printf("No large numbers found.\n");
            break;
        }

        case 7: { // All Identical Elements
            int identical = 1;
            for (int i = 1; i < n; i++) {
                if (arr[i] != arr[0]) {
                    identical = 0;
                    break;
                }
            }
            if (identical)
                printf("Edge Case 7: All elements are identical.\n");
            else
                printf("Not all elements are identical.\n");
            break;
        }

        default:
            printf("Invalid choice.\n");
    }
    // Always print sorted array 
    if (n > 0) {
        printf("Sorted Array: ");
        printArray(arr, n);
    }

    return 0;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
// Print array function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
