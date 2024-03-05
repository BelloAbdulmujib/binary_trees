#include <stdlib.h>
#include "binary_heap.h" // Include your heap header file here


/**
 * heapify - Helper function to heapify a subtree rooted at index i.
 * @arr: Pointer to the array representing the heap.
 * @N: Total number of nodes in the heap.
 * @i: Index of the node to heapify.
 */
void heapify(int arr[], int N, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;


        if (left_child < N && arr[left_child] > arr[largest])
        largest = left_child;
        if (right_child < N && arr[right_child] > arr[largest])
        largest = right_child;


        if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, N, largest);
    }
}


/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 * Return: Pointer to the sorted array (in descending order), or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size) {
    if (!heap || !size)
        return NULL;


    int N = 0;
    heap_t *current = heap;
    while (current) {
        N++;
        current = current->left;
    }


        int *sorted_array = (int *)malloc(N * sizeof(int));
    if (!sorted_array)
        return NULL;


    for (int i = N - 1; i >= 0; i--) {
        sorted_array[i] = heap->data;
        heap->data = heap->left->data;
        heap->left = NULL; // Free the previous left child
        heapify(sorted_array, i, 0); // Rebuild the heap
    }


    *size = N; // Update the size
    return sorted_array;
}
