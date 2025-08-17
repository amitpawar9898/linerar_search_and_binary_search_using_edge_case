// Merge Sort 
// Amit Pawar - A1
#include <stdio.h>
#define SIZE 10
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];  
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice;
    int arr[SIZE];
    int n; 
    printf("Select Edge Case:\n");
    printf("1. Empty Array\n");
    printf("2. Single Element\n");
    printf("3. Already Sorted\n");
    printf("4. Duplicate Elements\n");
    printf("5. Negative Numbers\n");
    printf("6. Large Numbers\n");
    printf("7. All Identical Elements\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Empty Array
            n = 0;
            printf("Empty Array selected.\n");
            break;

        case 2: // Single Element
            n = 1;
            arr[0] = 42;
            printf("Single element array: ");
            break;

        case 3: // Already Sorted
            n = 6;
            int sorted[] = {1, 2, 3, 4, 5, 6};
            for (int i = 0; i < n; i++) arr[i] = sorted[i];
            printf("Already sorted array: ");
            break;

        case 4: // Duplicate Elements
            n = 6;
            int dup[] = {5, 3, 4, 2, 5, 2};
            for (int i = 0; i < n; i++) arr[i] = dup[i];
            printf("Array with duplicates: ");
            break;

        case 5: // Negative Numbers
            n = 6;
            int neg[] = {-3, -1, -7, 4, 2, 0};
            for (int i = 0; i < n; i++) arr[i] = neg[i];
            printf("Array with negative numbers: ");
            break;

        case 6: // Large Numbers
            n = 6;
            int large[] = {9990, 12352, 27654, 55555, 1000, 442};
            for (int i = 0; i < n; i++) arr[i] = large[i];
            printf("Array with large numbers: ");
            break;

        case 7: // All Identical Elements
            n = 6;
            for (int i = 0; i < n; i++) arr[i] = 7;
            printf("Array with all identical elements: ");
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }
    printArray(arr, n);
    if (n > 0) {
        mergeSort(arr, 0, n - 1);
        printf("Sorted array: ");
        printArray(arr, n);
    } else {
        printf("Nothing to sort (empty array).\n");
    }
    return 0;
}
