#include <stdlib.h>
#include "binary_heap.h" 
/**
 * array_to_heap - Builds a Max Binary Heap from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created Binary Heap, or NULL on failure.
 */
heap_t* array_to_heap(int* array, size_t size) {
    if (!array || size == 0)
        return NULL;


    heap_t** heap_nodes = (heap_t**)malloc(size * sizeof(heap_t*));
    for (size_t i = 0; i < size; ++i)
        heap_nodes[i] = create_heap_node(array[i]);


        for (int i = size / 2 - 1; i >= 0; --i)
        heapify(array, size, i);


        for (size_t i = 0; i < size; ++i) {
        heap_nodes[i]->left = (2 * i + 1 < size) ? heap_nodes[2 * i + 1] : NULL;
        heap_nodes[i]->right = (2 * i + 2 < size) ? heap_nodes[2 * i + 2] : NULL;
    }


       return heap_nodes[0];
}
