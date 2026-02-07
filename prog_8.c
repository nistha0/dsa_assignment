#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;
int swaps = 0;

void resetCounters() {
    comparisons = 0;
    swaps = 0;
}

void swap(int* a, int* b) {
    swaps++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0) {
            comparisons++;
            if(arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        comparisons++;
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        swaps++;
    }
    
    while(i < n1) {
        arr[k++] = L[i++];
        swaps++;
    }
    
    while(j < n2) {
        arr[k++] = R[j++];
        swaps++;
    }
}

void mergeSortHelper(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

int main() {
    int n;
    printf("Enter the number of elements (N): ");
    scanf("%d", &n);
    
    if(n <= 0 || n > 1000) {
        printf("Please enter a valid number between 1 and 1000\n");
        return 1;
    }
    
    int* original = (int*)malloc(n * sizeof(int));
    
    srand(time(NULL));
    printf("\nGenerating %d random numbers between 1 and 1000...\n", n);
    for(int i = 0; i < n; i++) {
        original[i] = (rand() % 1000) + 1;
    }
    
    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice (1-4): ");
    
    int choice;
    scanf("%d", &choice);
    
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        arr[i] = original[i];
    }
    
    printf("\nBefore sorting (first 20 elements): ");
    for(int i = 0; i < (n < 20 ? n : 20); i++) {
        printf("%d ", arr[i]);
    }
    if(n > 20) printf("...");
    printf("\n");
    
    resetCounters();
    
    switch(choice) {
        case 1:
            printf("\nUsing Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("\nUsing Selection Sort...\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("\nUsing Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        case 4:
            printf("\nUsing Merge Sort...\n");
            mergeSort(arr, n);
            break;
        default:
            printf("Invalid choice!\n");
            free(arr);
            free(original);
            return 1;
    }
    
    printf("\nAfter sorting (first 20 elements): ");
    for(int i = 0; i < (n < 20 ? n : 20); i++) {
        printf("%d ", arr[i]);
    }
    if(n > 20) printf("...");
    printf("\n");
    
    printf("\n--- Statistics ---\n");
    printf("Total Comparisons: %d\n", comparisons);
    printf("Total Swaps: %d\n", swaps);
    
    free(arr);
    free(original);
    
    return 0;
}