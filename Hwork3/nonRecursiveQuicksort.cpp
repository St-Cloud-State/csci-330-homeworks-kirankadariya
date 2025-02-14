#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For std::swap

using namespace std;

// Partition function using Lomuto partition scheme
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1; // Index for the smaller element

    // Iterate through the array to place elements smaller than pivot on the left
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // Swap if element is smaller than pivot
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in its correct position
    return i + 1; // Return partition index
}

// Iterative Quicksort function
void quicksort(vector<int>& arr) {
    stack<pair<int, int>> s; // Stack to simulate recursion
    s.push({0, arr.size() - 1}); // Push the initial range of the array
    
    while (!s.empty()) {
        int low = s.top().first;
        int high = s.top().second;
        s.pop();
        
        if (low < high) {
            int pivotIndex = partition(arr, low, high); // Partition the array
            
            // Push left subarray onto the stack if it has more than one element
            if (pivotIndex - 1 > low)
                s.push({low, pivotIndex - 1});
            
            // Push right subarray onto the stack if it has more than one element
            if (pivotIndex + 1 < high)
                s.push({pivotIndex + 1, high});
        }
    }
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {11, 8, 7, 9, 1, 6};
    cout << "Original array: ";
    printArray(arr); // Print original array
    
    quicksort(arr); // Perform iterative quicksort
    
    cout << "Sorted array: ";
    printArray(arr); // Print sorted array
    return 0;
}
