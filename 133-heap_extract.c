#include <stdlib.h>
#include "binary_heap.h" 
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
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root) {
    if (!root || !*root)
        return 0;


    heap_t* heap_root = *root;
    int extracted_value = heap_root->data;


        heap_root->data = heap_root->left->data;
    heap_root->left = NULL; // Free the previous left child
    heapify(arr, N, 0);


    return extracted_value;
}
