#include <iostream>

using namespace std;

void max_heapify(int* array, int index, int end_index)
{
	if (index > end_index || index < 0)
    {
		return;
	}
	int left  = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    if (left <= end_index && array[left] > array[largest])
    {
        largest = left;
    }
    if (right <= end_index && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        max_heapify(array, largest, end_index);
    }
}

void build_max_heap(int* array, int heap_size)
{
    // first non-leaf node index is: heap_size / 2 - 1
	for (int i = heap_size / 2 - 1; i >= 0; i--)
    {
		max_heapify(array, i, heap_size - 1);
	}
}

void heap_sort(int* array, int heap_size)
{
    build_max_heap(array, heap_size);
	for (int i = heap_size - 1; i >= 0; i--)
    {
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		max_heapify(array, 0, i - 1);
	}
}


int main() 
{
	int nums[] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	heap_sort(nums, 15);
    for (int i = 0; i < 15; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
