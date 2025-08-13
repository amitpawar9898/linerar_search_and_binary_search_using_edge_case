//binary_search
//amit pawar
// A1
#include <stdio.h>
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;  
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; 
}

void testBinarySearch(int arr[], int n, int key, const char* testName) {
    printf("Test: %s\n", testName);
    int result = binarySearch(arr, n, key);
    if (result != -1) {
        printf("  Element %d found at index %d\n\n", key, result);
    } else {
        printf("  Element %d not found\n\n", key);
    }
}

int main() {
    int testNumber;

    do {
        printf("\nBinary Search Test Cases Menu:\n");
        printf("1. Empty Array\n");
        printf("2. Element Not Present\n");
        printf("3. Element at First Position\n");
        printf("4. Element at Last Position\n");
        printf("5. Multiple Occurrences\n");
        printf("6. Negative Numbers\n");
        printf("7. Large Numbers\n");
        printf("8. All Identical Elements\n");
        printf("9. Exit\n");
        printf("Enter test number (1 to 9): ");
        scanf("%d", &testNumber);

        switch (testNumber) {
            case 1: {
                int arr1[1]; 
                testBinarySearch(arr1, 0, 5, "Empty Array");
                break;
            }
            case 2: {
                int arr2[] = {1, 3, 5, 7, 9};
                testBinarySearch(arr2, 5, 4, "Element Not Present");
                break;
            }
            case 3: {
                int arr3[] = {1, 3, 5, 7, 9};
                testBinarySearch(arr3, 5, 1, "Element at First Position");
                break;
            }
            case 4: {
                int arr4[] = {1, 3, 5, 7, 9};
                testBinarySearch(arr4, 5, 9, "Element at Last Position");
                break;
            }
            case 5: {
                int arr5[] = {1, 3, 3, 3, 5, 7};
                testBinarySearch(arr5, 6, 3, "Multiple Occurrences");
                break;
            }
            case 6: {
                int arr6[] = {-10, -5, 0, 5, 10};
                testBinarySearch(arr6, 5, -5, "Negative Numbers");
                break;
            }
            case 7:{
                int arr7[] = {1000000, 2000000, 3000000, 4000000};
                testBinarySearch(arr7, 4, 3000000, "Large Numbers");
                break;
            }
            case 8: {
                int arr8[] = {7, 7, 7, 7, 7};
                testBinarySearch(arr8, 5, 7, "All Identical Elements");
                break;
            }
            case 9:{
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid test number. Please enter a number between 1 and 9.\n");
        }

    } 
    while (testNumber != 9);

    return 0;
}
