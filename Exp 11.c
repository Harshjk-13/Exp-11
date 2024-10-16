#include <stdio.h>

// Function to implement binary search
int binarySearch(int orders[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (orders[mid] == target) {
            return mid;  // Order ID found at index mid
        }

        // If target is greater, ignore the left half
        if (orders[mid] < target) {
            left = mid + 1;
        }

        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Order ID not found
    return -1;
}

int main() {
    // Sample sorted array of customer order IDs (real-world data would come from a database)
    int orders[] = {1001, 1012, 1025, 1030, 1040, 1055, 1067, 1075, 1090};
    int size = sizeof(orders) / sizeof(orders[0]);

    // Simulating customer inquiry for a specific order ID
    int targetOrderID;
    printf("Enter the order ID to search for: ");
    scanf("%d", &targetOrderID);

    // Perform binary search
    int result = binarySearch(orders, size, targetOrderID);

    // Display the result
    if (result != -1) {
        printf("Order ID %d found at index %d in the sorted order list.\n", targetOrderID, result);
    } else {
        printf("Order ID %d not found in the list.\n", targetOrderID);
    }

    return 0;
}
