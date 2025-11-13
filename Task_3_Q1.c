#include <stdio.h>

// Iterative function
void rearrangeIterative(int arr[], int size) {
    int left = 0;           // Pointer starting from beginning of array
    int right = size - 1;   // Pointer starting from end of array
    
    // Continue until pointers meet
    while (left < right) {
        // Move left pointer forward while current element is odd
        while (left < right && arr[left] % 2 != 0) {
            left++;
        }
        
        // Move right pointer backward while current element is even
        while (left < right && arr[right] % 2 == 0) {
            right--;
        }
        
        // At this point: arr[left] is even and arr[right] is odd
        // Swap them to put odd on left and even on right
        if (left < right) {
            int temp = arr[left];      // Store left element temporarily
            arr[left] = arr[right];    // Move right element to left position
            arr[right] = temp;         // Move stored element to right position
            left++;                    // Move left pointer forward
            right--;                   // Move right pointer backward
        }
    }
}


// Recursive function
void rearrangeRecursive(int arr[], int left, int right) {
    // Base case: when pointers cross or meet, stop recursion
    if (left >= right) {
        return;
    }
    
    // Move left pointer forward while current element is odd
    while (left < right && arr[left] % 2 != 0) {
        left++;
    }
    
    // Move right pointer backward while current element is even
    while (left < right && arr[right] % 2 == 0) {
        right--;
    }
    
    // At this point: arr[left] is even and arr[right] is odd
    // Swap them and make recursive call with updated pointers
    if (left < right) {
        int temp = arr[left];      // Store left element temporarily
        arr[left] = arr[right];    // Move right element to left position
        arr[right] = temp;         // Move stored element to right position
        
        // Recursive call with narrowed range (left+1 to right-1)
        rearrangeRecursive(arr, left + 1, right - 1);
    }
}

// Helper function to print array
void printArray(int arr[], int size) {
    // Loop through each element and print with space separator
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");  // New line after printing all elements
}

// Helper function to copy array
void copyArray(int source[], int dest[], int size) {
    // Copy each element from source to destination
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// Main function to test both iterative and recursive algorithms
int main() {
    // Initialize test array with alternating odd and even numbers
    int original[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(original) / sizeof(original[0]);  // Calculate array size
    
    // Create separate copies for each algorithm to work on
    // This ensures both algorithms start with the same input
    int arr_recursive[size];
    int arr_iterative[size];
    
    // Copy original array to both working arrays
    copyArray(original, arr_recursive, size);
    copyArray(original, arr_iterative, size);
    
    // Display the original array before any rearrangement
    printf("Original array: ");
    printArray(original, size);
    
    // Test recursive algorithm
    rearrangeRecursive(arr_recursive, 0, size - 1);
    printf("Rearranged array (Recursive): ");
    printArray(arr_recursive, size);
    
    // Test iterative algorithm
    rearrangeIterative(arr_iterative, size);
    printf("Rearranged array (Iterative): ");
    printArray(arr_iterative, size);
    
    return 0; 
}